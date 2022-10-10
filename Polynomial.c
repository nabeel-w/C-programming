#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int num;
    int pow;
    struct node* next;
}node;
int size=sizeof(node);
node* create_poly(int num,int power,node* poly)
{
    node* tmp=poly;
    node* ptr=poly;
    node* r=malloc(size);
    if(tmp==NULL)
    {
        r->num=num;
        r->pow=power;
        r->next=NULL;
        return r;
    }
    else
    {
        r->num=num;
        r->pow=power;
        r->next=NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=r;
        return poly;
    }
}

node* add(node*a,node*b,node** result)
{
    node* res=malloc(size);
    res->next=NULL;
    *result=res;
    while (a&&b)
    {
        if(a->pow>b->pow)
        {
            res->pow=a->pow;
            res->num=a->num;
            a=a->next;
        }
        else if(a->pow<b->pow)
        {
            res->pow=b->pow;
            res->num=b->num;
            b=b->next;
        }
        else
        {
            res->pow=a->pow;
            res->num=a->num+b->num;
            a=a->next;
            b=b->next;
        }
        if(a&&b)
        {
            res->next=malloc(size);
            res=res->next;
            res->next=NULL;
        }
    }
    while(a||b)
    {
        res->next=malloc(size);
        res=res->next;
        res->next=NULL;
        if(a)
        {
            res->pow=a->pow;
            res->num=a->num;
            a=a->next;
        }
        else if(b)
        {
            res->pow=b->pow;
            res->num=b->num;
            b=b->next;
        }
    }
}

void show(node* res)
{
    while(res!=NULL)
    {
        printf(" %dx^%d ",res->num,res->pow);
        res=res->next;
        
        if(res!=NULL)
        {
            printf("+");
        }
        
    }
}

int main(void)
{
    int n1,n2;
    node *a=NULL,*b=NULL,*res;
    printf("Enter the number of elements your 1st polynomial has: ");
    scanf("%d",&n1);
    printf("Enter the number of elements your 2nd polynomial has: ");
    scanf("%d",&n2);
    printf("Enter the 1st Polynomial\n");
    for(int i=0;i<n1;i++)
    {
        int num,power;
        printf("Enter the Co-efficient: ");
        scanf("%d",&num);
        printf("Enter the Power: ");
        scanf("%d",&power);
        a=create_poly(num,power,a);

    }
    printf("Enter the 2nd Polynomial\n");
    for(int i=0;i<n2;i++)
    {
        int num,power;
        printf("Enter the Co-efficient: ");
        scanf("%d",&num);
        printf("Enter the Power: ");
        scanf("%d",&power);
        b=create_poly(num,power,b);

    }
    printf("\n1st Polynomial: ");
    show(a);
    printf("\n2nd Polynomial: ");
    show(b);
    add(a,b,&res);
    printf("\nTheir Addition: ");
    show(res);
}
