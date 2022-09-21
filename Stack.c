#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct Stack
{
	int top;
	unsigned cap;
	int* arr;
}Stack;

int size=sizeof(Stack);

Stack* create_stack(unsigned cap)
{
	Stack* stack=malloc(size);
	stack->cap=cap;
	stack->top=-1;
	stack->arr=malloc(stack->cap*sizeof(int));
	return stack;
}

int is_full(Stack* stack)
{
	return stack->top==stack->cap-1;
}

int is_empty(Stack* stack)
{
	return stack->top==-1;
}

void push(Stack* stack,int element)
{
	if(is_full(stack))
	{
		return;
	}
	stack->arr[++stack->top]=element;
}

int pop(Stack* stack)
{
	if(is_empty(stack))
	{
		return INT_MIN;
	}
	return stack->arr[stack->top--];
}

int peek(Stack* stack)
{
	if(is_empty(stack))
	{
		printf("Stack is empty\n");
		return INT_MIN;
	}
	return stack->arr[stack->top];
}

void display_stack(Stack* stack)
{
	if(is_empty(stack))
	{
		printf("Stack is empty\n");
		return;
	}
	int tmp=stack->top;
	printf("\nElement present in the stack: ");
	while(tmp!=-1)
	{
		printf("\t%d\t",stack->arr[tmp]);
		tmp--;
	}
}

int main(void)
{
	int n;
	printf("Enter size of Stack: ");
	scanf("%d",&n);
	Stack* stack=create_stack(n);
	printf("Enter Elements of Stack\n");
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		push(stack,tmp);
	}
	printf("The Top element in stack is: %d\n",peek(stack));
	printf("Element poped off: %d",pop(stack));
	display_stack(stack);
}
