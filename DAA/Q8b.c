//prim's algorithm

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int minKey(int key[V], bool mstSet[V]){
    int min = INT_MAX, min_index;
    for(int i = 0; i <V;i++)
        if(!mstSet[i] && min > key[i])
            min = key[i], min_index = i;
    
    return min_index;
}

void printMST(int parent[V], int graph[V][V]){
    printf("\nEdge\tDistance\n");
    for(int i = 1; i < V; i++)
        printf("%d-%d\t%d\n",parent[i]+1,i+1,graph[i][parent[i]]);
    printf("\n");
}

void primMST(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mstSet[V];

    for(int i = 0; i < V; i++)
        mstSet[i] = false, key[i] = INT_MAX;

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        for(int v = 0; v < V; v++)
            if(!mstSet[v] && graph[u][v] && key[v] > graph[u][v])
                key[v] = graph[u][v], parent[v] = u;
    }

    printMST(parent,graph);
}

int main(){
    int graph[V][V] = {
        {0,10,0,0,5},
        {10,0,1,6,0},
        {0,1,0,2,7},
        {0,6,2,0,3},
        {5,0,7,3,0},
    };
    primMST(graph);
    return 0;
}