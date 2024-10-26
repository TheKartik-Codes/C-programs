
#include <stdio.h>
#include<stdlib.h>

//structure to represent a node in Adjacency list
struct node 
{
    int vertex;
    struct node*next;
};

//structure to represent a Adjacency lists
struct Graph
{
    int numvertices;
    struct node **adjlists;
};

//function to create a new node
struct node *createnode(int vertex )
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->vertex=vertex;
    newnode->next=NULL;
    
    return newnode;
}

//A function to create a graph with given number of vertices

struct Graph* creategraph(int vertices)
{
    struct Graph* graph;
    graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->numvertices=vertices;
    
    //create an array of linkedlists
    graph->adjlists=(struct node**)malloc(vertices*sizeof(struct Node*));
    
    //Initialize each Adjacency list as empty
    for( int i=0; i<vertices; i++ )
    {
        graph->adjlists[i]=NULL;
    }
    
    return graph;
}

//A function to add an edge to the graph
void addedge(struct Graph*graph,int src,int dest)
{
    struct node* newnode=createnode(dest);
    
    newnode->next=graph->adjlists[src];
    graph->adjlists[src]=newnode;
}

//function to calculate and print the outdegree of vertex
void printoutdegree(struct Graph* graph,int vertex)
{
    if ( vertex < 0 || vertex >= graph->numvertices )
    {
        printf("\nVertex %d is out of bounds.",vertex);
        return;
    }
    int outdegree=0;
    
    struct node *temp=graph->adjlists[vertex];
    while ( temp )
    {
        outdegree++;
        temp=temp->next;
    }
    
    printf("\nOutdegree of vertex %d : %d.",vertex,outdegree);
}

int main() 
{
    int numvertices,edges,src,dest;
    
    printf("\nEnter number of vertices :");
    scanf("%d",&numvertices);
    
    struct Graph* graph=creategraph(numvertices);
    
    printf("\nEnter number of edges:");
    scanf("%d",&edges);
    
    for ( int i=0 ; i<edges ; i++ )
    {
        printf("\nEnter source vertex of edge %d: ",i+1);
        scanf("%d",&src);
        
        printf("\nEnter destination vertex of edge %d: ",i+1);
        scanf("%d",&dest);
        
        addedge(graph,src,dest);
    }
    
    int vertextocheck;
    printf("\nEnter a vertex to find its outdegree: ");
    scanf("%d",&vertextocheck);
    
    printoutdegree(graph,vertextocheck);
 
    return 0;
}