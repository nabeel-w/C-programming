#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    
}node;

int size=sizeof(node);

void addl(node* head)
{
     node *ptr = head;
     int b;
     printf("enter value of the node :");
     scanf("%d",&b);
     node* temp = malloc(sizeof(struct node));
     int n;
     printf("enter the value of the element:");
     scanf("%d",&n);
     temp -> num = n ;
     while (ptr != NULL)
        {
           if(ptr -> num == b)
           {
                 temp ->next = ptr ->next;
                 ptr ->next = temp;
                 break;
            }
            ptr= ptr ->next;
        }
     ptr = head;
}

void add(node* head)
{
    int a;
    printf("Enter a Number: ");
    scanf("%d",&a);
    node* temp=malloc(sizeof(node));
    node* ptr=head;
    temp->num=a;
    temp->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
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
node* insertelement()
{
    int a;
    node* y=malloc(sizeof(node));
    if(y==NULL)//memory check
    {
        printf("Exiting :(\n");
        exit(1);
    }
    printf("Enter a Number: ");
    scanf("%d",&a);
    y->num=a;
    y->next=NULL;     
    return y;
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

void addf(node* head)
{
     node *ptr = head;
     int b;
     printf("enter value of the node :");
     scanf("%d",&b);
     node* temp = malloc(sizeof(struct node));
     int n;
     printf("enter the value of the element:");
     scanf("%d",&n);
     temp -> num = n ;
     while (ptr != NULL)
        {
           if(ptr -> next-> num == b)
           {
                 temp ->next = ptr ->next;
                 ptr ->next= temp;
                 break;
            }
            ptr= ptr ->next;
        }
     ptr = head;
}

int main(void)
{
    int a,inpt;
    printf("Let's Make a Linked List\nEnter the size of the List: ");
    scanf("%d",&a);
    node* head=malloc(size);
    printf("Enter a Number: ");
    scanf("%d",&inpt);
    head->num=inpt;
    head->next=NULL;
    for(int i=0;i<a-1;i++)
    {
        add(head);
    }
    printf("\nYour List\n");
    printlist(head);
    addf(head);
    printf("\nNew List\n");
    printlist(head);
    delete(head);
}