#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
    
}node;
//global variable for size
int size=sizeof(node);
void printlist(node* x)
{
    while(x!=NULL)
    {
        printf("Number is :%d \n",x->num);
        x=x->next;
    }
}
//inserting element at the front
node* insertelement(node* n)
{
    int a;
    node* y=malloc(sizeof(node));
    printf("Enter a Number: ");
    scanf("%d",&a);
    y->num=a;
    y->next=n;     
    return y;
}
void delete(node* n)
{
    if(n==NULL){
        return;
    }
    delete(n->next);
    free(n);

}
int main(void)
{
    node* x = malloc(sizeof(node));
    node* z = malloc(size);
    node* y = malloc(sizeof(node));
    int a;
    if(x==NULL||y==NULL||z==NULL)
    {
        printf("Exiting :(\n");
        return 1;
    }
    printf("Enter a Number: ");
    scanf("%d",&a);
    x->num=a;
    x->next=NULL;
    y=insertelement(x);
    x=y;
    printlist(x);
    delete(x);
}