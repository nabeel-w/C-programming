#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node
{
    int num;
    struct Node* next;
}node;
typedef struct Queue
{
    int rear;
    int front;
    unsigned cap;
    node* head;
}queue;
queue* create_queue(unsigned cap)
{
    queue* que=malloc(sizeof(queue));
    que->cap=cap;
    que->front=-1;
    que->rear=-1;
    que->head=NULL;
    return que;
}
node* add(node* n)
{
    node* tmp=malloc(sizeof(node)),*ptr=n;
    printf("Enter Element: ");
    scanf("%d",&tmp->num);
    tmp->next=NULL;
    if(n==NULL)
    {
        n=tmp;
        return n;
    }
    else
    {
        while (ptr)
        {
            if(ptr->next==NULL)
            {
                ptr->next=tmp;
                return n;
            }
            ptr=ptr->next;
        }
    }
    
}
int IsEmpty(queue* que)
{
    return(que->front==-1||que->rear==-1);
}
int IsFull(queue* que)
{
    return(que->rear==que->cap-1);
}
void enque(queue* que)
{
    if(IsEmpty(que))
    {
        que->head=add(que->head);
        que->front++;
        que->rear++;
        return;
    }
    else if(IsFull(que))
    {
        printf("Queue is Full\n");
        return;
    }
    else
    {
        que->head=add(que->head);
        que->rear++;
        return;
    }
}
int deque(queue* que)
{
    node* ptr=que->head;
    if(IsEmpty(que)||que->front==que->rear+1)
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    int val=ptr->num;
    que->head=ptr->next;
    free(ptr);
    que->front++;
    return val;
}
int peek(queue* que)
{
    if(IsEmpty(que))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return que->head->num;
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
void display_queue(queue* que)
{
    node *ptr=que->head;
    printf("Queue: ");
    while(ptr)
    {
        printf("%d  ",ptr->num);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(void)
{
    int ch;
    queue* que=create_queue(10);
    while (1)
    {
        printf("\n1.Insert an element in Queue\n2.Delete an element from Queue\n3.Peek your Queue\n4.Display Queue\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enque(que);
            break;
        case 2:
            printf("Element removed: %d\n",deque(que));
            break;
        case 3:
            printf("Element at the front: %d\n",peek(que));
            break;
        case 4:
            display_queue(que);
            break;
        case 5:
            delete(que->head);
            free(que);
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    
}