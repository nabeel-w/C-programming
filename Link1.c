#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    
}node;

int size=sizeof(node);

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

void delete(node* n)//frees memory
{
    if(n==NULL)
    {
        return;
    }
    delete(n->next);
    free(n);

}
//inserting element at the front
node* insertelementf(node* n)
{
    int a;
    node* y=malloc(sizeof(node));
    printf("Enter a Number: ");
    scanf("%d",&a);
    y->num=a;
    y->next=n;     
    return y;
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

int addf(node* head,int numinp)
{
    int flag;
    node* new1;
    while(head!=NULL)
            {
                if(head->next->num==numinp)
                {
                    flag=0;
                    new1=insertelement(head);
                    new1->next=head->next;
                    head=new1;
                    break;
                }
                else
                    flag++;
                    head=head->next;
            }
    return flag;
}

int main(void)
{
    int a;
    printf("Let's Make a Linked List\nEnter the size of the List: ");
    scanf("%d",&a);
    node* ele[a];
    ele[0]=insertelement();
    for (int i = 1; i < a; i++)
    {
        ele[i]=insertelement();
        ele[i-1]->next=ele[i];

    }
    printf("\nYour List\n");
    printlist(ele[0]);
    int inpt=0;
    printf("\nWould you like to input a new element(press 1/0): ");
    scanf("%d",&inpt);
    if(inpt == 1)
    {
        node* new=insertelement();
        ele[a-1]->next=new;
        printf("\nNew List\n");
        printlist(ele[0]);
        //delete(ele[0]);
    }
    else 
    {
        printf("\nBye\n");
        delete(ele[0]);
        exit(0);
    }
    printf("\nWould you like to delete element(press 1 TO DELETE THE FIRST)(press 0 TO DELETE THE LAST): ");
    scanf("%d",&inpt);
    if(inpt==1)
    {
        node* tmp=ele[0];
        ele[0]=ele[0]->next;
        free(tmp);
        printf("\nNew List\n");
        printlist(ele[0]);
        //delete(ele[0]);
    }
    else if(inpt==0)
    {
        node* tmp=ele[a-1]->next;
        ele[a-1]->next=NULL;
        free(tmp);
        printf("\nNew List\n");
        printlist(ele[0]);
        //delete(ele[0]);
    }
    else 
    {
        printf("\nBye\n");
        delete(ele[0]);
        exit(0);
    }
    printf("Would you like to add an element before a specific node(1/0):");
    scanf("%d",&inpt);
    if(inpt==1)
    {
        int numinp;
        printf("Enter the element before which you wanna add the number:");
        scanf("%d",&numinp);
        int flag=0;
        node* new1;
        if(ele[0]->num==numinp)
        {
            flag=0;
            new1=insertelementf(ele[0]);
            ele[0]=new1;
        }
        else
        {
            /*while(ele[0]!=NULL)
            {
                if(ele[0]->next->num==numinp)
                {
                    flag=0;
                    new1=insertelement(ele[0]);
                    new1->next=ele[0]->next;
                    ele[0]=new1;
                    break;
                }
                else
                    flag++;
                    ele[0]=ele[0]->next;
            }*/
            flag=addf(ele[0],numinp);
        }
        if(flag==0)
        {
            printf("\nNew List\n");
            printlist(ele[0]);
            delete(ele[0]);
        }
        else
            printf("Number Not found\n");
    }
    else 
    {
        printf("\nBye\n");
        delete(ele[0]);
        exit(0);
    }
    

    
}
