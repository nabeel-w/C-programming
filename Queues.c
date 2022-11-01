#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Queues
{
    int* arr;
    unsigned cap;
    int rear;
    int front;
}queues;
int IsFull(queues* q)
{
    return q->rear==q->cap-1;
}
int IsEmpty(queues* que)
{
    return que->rear==-1;
}
queues* CreateQueue(int cap)
{
    queues* que=malloc(sizeof(queues));
    que->front=-1;
    que->rear=-1;
    que->cap=cap;
    que->arr=malloc(cap*sizeof(int));
    return que;
}
void enque(queues* que,int ele)
{
    if(IsFull(que))
    {
        printf("Can't Insert %d,Queue is FULL\n",ele);
        return;
    }
    else if(IsEmpty(que))
    {
        que->arr[++que->rear]=ele;
        que->front++;
    }
    else
        que->arr[++que->rear]=ele;

}
int deque(queues* que)
{
    if(IsEmpty(que)||que->front>que->rear)
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return que->arr[que->front++];
}
void DisplayQue(queues* que)
{
    if(IsEmpty(que))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Your Queue: ");
    for (int i = que->front; i <=que->rear; i++)
    {
        printf("%d  ",que->arr[i]);
    }
    printf("\n");
}
int main(void)
{
    int ch;
    queues* que=CreateQueue(10);
     while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            int ele;
            printf("Enter the element you want to insert: ");
            scanf("%d",&ele);
            enque(que,ele);
            break;
            case 2:
            printf("Element dequeued: %d\n",deque(que));
            break;
            case 3:
            DisplayQue(que);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Wrong Choice\n");
        }
    }
}