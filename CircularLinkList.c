#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    
}node;

int size=sizeof(node);

node* add(node* head)
{
    node* tmp=malloc(size);
    node* ptr=head;
    printf("Enter the Element: ");
    scanf("%d",&tmp->num);
    tmp->next=head;
    if(head->next==head)
    {
        head->next=tmp;
        tmp->next=head;
        return head;
    }
    else 
    {
        while (ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=tmp;
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
    while (1)
    {
        if(ptr->next==head)
        {
            ptr->next=temp;
            return temp;
        }
        ptr=ptr->next;
    }
    

}

node* remove_l(node* head)
{
    node* ptr=head;
    while(1)
    {
        if(ptr->next->next==head)
        {
            node* tmp=ptr->next;
            ptr->next=head;
            free(tmp);
            return head;
        }
        ptr=ptr->next;
    }
}

node* rem_f(node* head)
{
    node* tmp=head;
    node* ptr=head;
    while(1)
    {
        if(ptr->next==head)
        {
            ptr->next=head->next;
            break;
        }
        ptr=ptr->next;
    }
    head=head->next;
    free(tmp);
    return head;
}

void printlist(node* x)
{
    int i=1;
    node* ptr=x;
    do
    {
        printf("Element %d is : %d \n",i,ptr->num);
        ptr=ptr->next;
        i++;
    }while(ptr!=x);
}

void delete(node* n)//frees memory
{
    if(n->next==n)
    {
        free(n);
        return;
    }
    node* tmp=n->next;
    n->next=n->next->next;
    delete(n);
    free(tmp);

}

int main(void)
{
    int n;
    printf("Enter the size of your CLL: ");
    scanf("%d",&n);
    node* head =malloc(size);
    printf("Enter the Element: ");
    scanf("%d",&head->num);
    head->next=head;
    for (int i = 0; i < n-1; i++)
    {
        head=add(head);
    }
    printlist(head);
    head=add_f(head);
    printf("New List\n");
    printlist(head);
    head=remove_l(head);
    printf("New List\n");
    printlist(head);
    head=rem_f(head);
    printf("New List\n");
    printlist(head);
    delete(head);
    

}
