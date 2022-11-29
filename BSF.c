#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
typedef struct queue
{
    int item[SIZE],front,rear;    
}queue;
typedef struct node
{
    int vert;
    struct node* next;
}node;
typedef struct graph
{
    int numvertices;
    node** adjlist;
    int *visited;
}graph;
int IsEmpty(queue* q)
{
    return(q->rear==-1);
}
node* createNode(int v)
{
    node* NewNode=malloc(sizeof(node));
    NewNode->vert=v;
    NewNode->next=NULL;
    return NewNode;
}
graph* createGraph(int verticies)
{
    graph* NewGraph=malloc(sizeof(graph));
    NewGraph->numvertices=verticies;
    NewGraph->adjlist=malloc(verticies*sizeof(node *));
    NewGraph->visited = malloc(verticies*sizeof(int));
    for(int i=0;i<verticies;i++)
    {
        NewGraph->adjlist[i]=NULL;
        NewGraph->visited[i]=0;
    }
    return NewGraph;
}
void Add(graph* graph,int s,int d)
{
    node* newNode = createNode(d);
    newNode->next = graph->adjlist[s];
    graph->adjlist[s] = newNode;
    newNode = createNode(s);
    newNode->next = graph->adjlist[d];
    graph->adjlist[d] = newNode;
}
queue* CreateQueue()
{
    queue* q=malloc(sizeof(queue));
    q->front=q->rear=-1;
    return q;
}
void enque(queue* que,int ele)
{
    if(IsEmpty(que))
    {
        que->item[++que->rear]=ele;
        que->front++;
    }
    else
        que->item[++que->rear]=ele;
}
int deque(queue* que)
{
    if(IsEmpty(que)||que->front>que->rear)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return que->item[que->front++];
}
void bfs(graph* graph, int startVertex)
{
    queue* q = CreateQueue();
    graph->visited[startVertex] = 1;
    enque(q, startVertex);
    while (!IsEmpty(q)) 
    {
        //printQueue(q);
        int currentVertex = deque(q);
        printf("Visited %d\n", currentVertex);
        node* temp = graph->adjlist[currentVertex];
        while (temp) 
        {
            int adjVertex = temp->vert;
            if (graph->visited[adjVertex] == 0) 
            {
                graph->visited[adjVertex] = 1;
                enque(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
int main(void) 
{
    graph* graph = createGraph(6);
    Add(graph, 0, 1);
    Add(graph, 0, 2);
    Add(graph, 1, 2);
    Add(graph, 1, 4);
    Add(graph, 1, 3);
    Add(graph, 2, 4);
    Add(graph, 3, 4);
    bfs(graph, 0);
}