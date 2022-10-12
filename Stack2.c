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
      return s->cap-1==s->top;
}

int is_empty(stack* s)
{
      return s->top==-1;
}

void display_list(node* head)
{
      if(head==NULL)
      {
            return;
      }
      display_list(head->next);
      printf("Element is %d\n",head->num);
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
      node* ptr=head;
      int t;
      while(head!=NULL)
      {
            
            if(head->next==NULL)
            {
                  t=head->num;
                  free(head);
                  return t;
            }
            
            else if(ptr->next->next==NULL)
            {
                  tmp=ptr->next;
                  t=ptr->next->num;
                  ptr->next=NULL;
                  free(tmp);
                  return t;

            }
            
            ptr=ptr->next;
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
            printf("Stack is FULL\n");
            return;
      }
      else if(is_empty(s))
      {
            int element;
            printf("Enter a Number: ");
            scanf("%d",&element);
            s->head->num=element;
            s->head->next=NULL;
            s->top+=1;
      }
      else
      {
            add(s->head);
            s->top+=1;
      }
}

int pop(stack* s)
{
      if(is_empty(s))
      {
            printf("Stack is empty\n");
            return INT_MIN;
      }
      s->top-=1;
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
            return ;
      }
      printf("Stack\n");
      display_list(s->head);
      
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
	printf("Enter size of Stack: ");
	scanf("%d",&n);
	stack* s1=stack_create(n);
	printf("Enter Elements of Stack\n");
      for(int i=0;i<n;i++)
	{
		push(s1);
	}
      display_stack(s1);
      printf("\ntop=%d\n",s1->top);
      printf("The Top element in stack is: %d\n",peek(s1));
      push(s1);
      while(s1->top!=-1){
	      printf("Element poped off: %d\n",pop(s1));
      }
	display_stack(s1);
      //delete(s1->head);
}
