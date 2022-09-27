#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
      int num;
      struct node* next;
}node;

typedef struct stack
{
      int top;
      unsigned cap;
      node* head;
}stack;
int size_n=sizeof(node);
int size_s=sizeof(stack);

stack* stack_create(unsigned cap)
{
      stack* s1=malloc(size_s);
      s1->cap=cap;
      s1->top=-1;
      s1->head=malloc(size_n);
      return s1;
}

int is_full(stack* s)
{
      return s->cap==s->top-1;
}

int is_empty(stack* s)
{
      return s->top==-1;
}

int fetch(node* head)
{
      int t;
      while (head!=NULL)
      {
           if(head->next->next==NULL)
            {
                  t=head->next->num;
                  return t;
            }
            head=head->next; 
      }
      
} 

int fetch_l(node* head)
{
      node* tmp;
      int t;
      while(head!=NULL)
      {
            if(head->next->next==NULL)
            {
                  tmp=head->next;
                  t=head->next->num;
                  head->next=NULL;
                  free(tmp);
                  return t;

            }
            head=head->next;
      }
      
}
void add(node* head)
{
      int a;
      printf("Enter a Number: ");
      scanf("%d",&a);
      node* temp=malloc(size_n);
      node* ptr=head;
      temp->num=a;
      temp->next=NULL;
      while (ptr->next!=NULL)
      {
            ptr=ptr->next;
      }
      ptr->next=temp;
}

void push(stack* s)
{
      if(is_full(s))
      {
            printf("Stack is EMPTY\n");
            return;
      }
      else if(is_empty(s))
      {
            int element;
            printf("Enter a Number: ");
            scanf("%d",&element);
            s->head->num=element;
            s->head->next=NULL;
            s->top++;
            return s;
      }
      else
      {
            add(s->head);
            s->top++;
            return s;
      }
}

int pop(stack* s)
{
      if(is_empty(s))
      {
            printf("Stack is empty\n");
            return INT_MIN;
      }
      s->top--;
      return fetch_l(s->head);
}

int peek(stack* s)
{
      if(is_empty(s))
      {
            printf("Stack is empty\n");
            return INT_MIN;
      }
      return fetch(s->head) ;
}

void display_stack(stack* s)
{
      if(is_empty(s))
      {
            printf("Stack is empty\n");
            return INT_MIN;
      }
      int tmp=s->top;
      while(tmp!=-1)
      {
            
      }
      
}