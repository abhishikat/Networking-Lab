

/* From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra’s algorithm. */
//code not working for 9 vertices , as it takes  much time than expected,
#include <stdio.h>
#include<iostream>
#include <limits.h>
using namespace std;

  
// vertices defined as 5
// not working for 9 vertex
#define V 5
  
int minDistance(int dist[],
                bool sptSet[])
{
      
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  
//source is j , print from j to parent // code takeO(1) // change it later on
void printPath(int parent[], int j)
{
    
    if (parent[j] == - 1)
        return;
  
    printPath(parent, parent[j]);
  
    printf("%d ", j);
}
  

void printSolution(int dist[], int n,
                      int parent[])
{
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(int graph[V][V], int src)
{
    
    int dist[V];
  
    bool sptSet[V];
 
    int parent[V];
 
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
  
    dist[src] = 0;
  
  
    for (int count = 0; count < V - 1; count++)
    {
        
        int u = minDistance(dist, sptSet);
  
        sptSet[u] = true;
  
    
        for (int v = 0; v < V; v++)
  
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
  
   
    printSolution(dist, V, parent);
}

int main()
{
    int graph[V][V];
    cout<<"Enter the weighted adjacency matrix (enter 10000 if there is no edge)=\n";
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            cin>>graph[i][j];
    }
  
    dijkstra(graph, 0);
    return 0;
}
                         
