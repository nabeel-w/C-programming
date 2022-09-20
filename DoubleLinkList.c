#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    struct node *prev;
    
    
}node;

int size=sizeof(node);

node* add(node* head)
{
    node* tmp=malloc(size);
    node* ptr=head;
    printf("Enter the Element: ");
    scanf("%d",&tmp->num);
    tmp->next=NULL;
    if(head->next==NULL)
    {
        head->next=tmp;
        tmp->next=NULL;
        tmp->prev=head;
        return head;
    }
    else 
    {
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=tmp;
        tmp->prev=ptr;
    }
    return head;
        
}

node* add_f(node* head)
{
    node* temp=malloc(size);
    node* ptr=head;
    printf("Enter the Number you want to add at the Beginning: ");
    scanf("%d",&temp->num);
    temp->next=head;
    temp->prev=NULL;
    head->prev=temp;
    return temp;
}

node* remove_l(node* head)
{
    node* ptr=head;
    while(1)
    {
        if(ptr->next->next==NULL)
        {
            node* tmp=ptr->next;
            ptr->next=NULL;
            free(tmp);
            return head;
        }
        ptr=ptr->next;
    }
}

node* rem_f(node* head)
{
    node* ptr=head;
    head->next->prev=NULL;
    head=head->next;
    free(ptr);
    return head;
}

void printlist(node* x)
{
    int i=1;
    while(x!=NULL)
    {
        printf("Element %d is : %d \n",i,x->num);
        x=x->next;
        i++;
    }
}

void printlist_l(node* x)//prints the list from the end
{
    int i=1;
    node* ptr=x;
    while(1)
    {
        if(ptr->next==NULL)
        {
            while(ptr!=NULL)
            {
                printf("Element %d is : %d \n",i,ptr->num);
                i--;
                ptr=ptr->prev;
            }
            break;
        }
        ptr=ptr->next;
        i++;
    }
}

void delete(node* n)//frees memory
{
    if(n==NULL)
    {
        return;
    }
    delete(n->next);
    free(n);

}

int main(void)
{
    int n;
    printf("Enter the size of your DLL: ");
    scanf("%d",&n);
    node* head =malloc(size);
    printf("Enter the Element: ");
    scanf("%d",&head->num);
    head->next=NULL;
    head->prev=NULL;
    for (int i = 0; i < n-1; i++)
    {
        head=add(head);
    }
    printlist(head);
    head=add_f(head);
    printf("\nNew List\n");
    printlist(head);
    printf("\n");
    printlist_l(head);
    head=rem_f(head);
    printf("\nNew List\n");
    printlist(head);
    printf("\n");
    printlist_l(head);
    delete(head);
}