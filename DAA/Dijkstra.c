/*
A GPS navigation system needs an approach to discover the reachable areas in a given geographical region from a given source area. 
Design and implement an algorithm to find which nodes can be reached from a given source node for the following graph. 
*/



#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int mindistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

void printresult(int dist[]){
    printf("Vertex \t Distance from source\n");
    for(int i = 0; i < V; i++)
        printf("%d\t\t%d\n",i+1,dist[i]);
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    dist[src] = 0;

    for(int count = 0; count < V-1; count++){
        int u = mindistance(dist,sptSet);
        sptSet[u] = true;

        for(int v = 0; v < V; v++)
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u]+graph[u][v];
    }
    
    printresult(dist);

    
}

int main(){
    int graph[V][V] = {
        {0,20,30,10,0},
        {0,0,40,0,39},
        {0,0,0,10,20},
        {0,0,5,0,20},
        {0,0,0,0,0},
    };
    int src = 0;
    dijkstra(graph,src);
    return 0;
}
