/*
A truck driver is given a set of locations to be covered with their distances by a company. 
The company strictly orders that truck should be started from a particular location. 
Design and implement an algorithm that gives a greedy solution to the truck driver’s problem and display the shortest path for a given source
location to all other locations. State the design strategy used and time complexity of the same.
*/



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define V 5

int minDistance(int dist[], bool sptset[]){
    int min = INT_MAX, min_index;
    for(int i = 0; i < V; i++)
        if(!sptset[i] && dist[i]< min)
            min = dist[i], min_index = i;
    
    return min_index;
}

void printSolution(int dist[]){
    printf("Vertex \t Distance from source \n");
    for(int i = 0; i < V; i++)
        printf("%d \t %d \n",i+1,dist[i]);
    printf("\n");
}

void dijkstras(int graph[V][V], int src){
    int dist[V];
    bool sptset[V];

    for(int i = 0; i <V ; i++)
        dist[i] = INT_MAX, sptset[i] = false;

    dist[src] = 0;

    for(int i = 0; i < V-1; i++){
        int u = minDistance(dist,sptset);
        sptset[u] = true;

        for(int v = 0; v < V; v++)
            if(!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main(){
    int graph[V][V] = {
        {0,10,0,0,100},
        {10,0,50,0,0},
        {0,50,0,20,10},
        {0,0,20,0,60},
        {100,0,10,60,0}
    };

    int src = 0;
    dijkstras(graph,src);
    return 0;
}
