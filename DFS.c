#include <stdio.h>
#include <stdlib.h>
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
void dfs(graph* graph,int vertex)
{
    node* adjList = graph->adjlist[vertex];
    node* temp = adjList;
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);
    while(temp)
    {
        int connectedVertex = temp->vert;
        if (graph->visited[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
int main(void)
{
    graph* graph=createGraph(5);
    Add(graph,0,1);
    Add(graph,0,2);
    Add(graph,0,3);
    Add(graph,1,2);
    Add(graph,2,4);
    dfs(graph,0);
}