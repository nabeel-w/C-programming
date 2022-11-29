#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int vertex;
    struct node* next;
}node;
typedef struct graph
{
    int numVert;
    node** adjlist;
}graph;
node* createNode(int v)
{
    node* NewNode=malloc(sizeof(node));
    NewNode->vertex=v;
    NewNode->next=NULL;
    return NewNode;
}
graph* createGraph(int verticies)
{
    graph* NewGraph=malloc(sizeof(graph));
    NewGraph->numVert=verticies;
    NewGraph->adjlist=malloc(verticies*sizeof(node *));
    for(int i=0;i<verticies;i++)
    {
        NewGraph->adjlist[i]=NULL;
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
void print(graph* graph)
{
    for(int i=0;i<graph->numVert;i++)
    {
        node* tmp=graph->adjlist[i];
        printf("\nVertex %d\n",i);
        while (tmp)
        {
            printf("%d ->",tmp->vertex);
            tmp=tmp->next;
        }
        printf("\n");
    }
}
int main(void)
{
    graph* graph=createGraph(4);
    Add(graph,0,1);
    Add(graph,0,2);
    Add(graph,0,3);
    Add(graph,1,2);

    print(graph);
}