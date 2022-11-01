#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue
{
    int* arr;
    unsigned cap;
    int rear;
    int front;
}queue;
queue* create_queue(unsigned cap)
{
    int size=(cap)*sizeof(int);
    queue* que=malloc(sizeof(queue));
    que->arr=(int*)malloc(size);
    que->cap=cap;
    que->front=-1;
    que->rear=-1;
    return que;
}
void enque(queue* que)
{
     if ((que->front == 0 && que->rear == que->cap-1) ||(que->rear == (que->front-1)%(que->cap-1)))
    {
        printf("\nQueue is Full\n");
        return;
    }
    else if(que->front==-1)
    {
        que->front=que->rear=0;
        printf("Enter Element: ");
        scanf("%d",&que->arr[que->rear]);
    }
    else if(que->rear==que->cap-1&&que->front!=0)
    {
        que->rear=0;
        printf("Enter Element: ");
        scanf("%d",&que->arr[que->rear]);
    }
    else
    {
        printf("Enter Element: ");
        scanf("%d",&que->arr[++que->rear]);
    }
}
int deque(queue* que)
{
    if(que->front==-1)
    {
        printf("Queue is Empty!\n");
        return INT_MIN;
    }
    int data = que->arr[que->front];
    que->arr[que->front] = -1;
    if (que->front == que->rear)
    {
        que->front = -1;
        que->rear = -1;
    }
    else if (que->front == que->cap-1)
    {
        que->front = 0;
    }
    else
    {
        que->front++;
    }
    return data;
}
int peek(queue* que)
{
    if(que->front!=-1)
        return(que->arr[que->front]);
    else
    {
        printf("Queue empty\n");
        return INT_MIN;
    }
}
void display(queue* que)
{
    if(que->front==-1)
    {
        printf("Queue is Empty!\n");
        return ;
    }
    printf("\nElements in Circular Queue are: ");
    if(que->rear>=que->front)
    {
        for(int i=que->front;i<=que->rear;i++)
        {
            printf("%d  ",que->arr[i]);
        }
    }
    else
    {
        for(int i=que->front;i<que->cap;i++)
        {
            printf("%d  ",que->arr[i]);
        }
        for(int i=0;i<=que->rear;i++)
        {
            printf("%d  ",que->arr[i]);
        }
    }
    printf("\n");
}

int main(void)
{
    int ch;
    queue* que=create_queue(5);
     while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Peek Queue\n");
        printf("5.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enque(que);
            break;
            case 2:
            printf("Element dequeued: %d\n",deque(que));
            break;
            case 3:
            display(que);
            break;
            case 4:
            printf("Element at front:%d\n",peek(que));
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Wrong Choice\n");
        }
    }
}