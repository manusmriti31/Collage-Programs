//Prims Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define V 5

int minKey(int key[],bool mstSet[]){
    int min = INT_MAX, min_index;
    for(int i = 0; i < V; i++)
        if(!mstSet[i] && key[i] < min)
            min = key[i], min_index = i;
    
    return min_index;
}

void printMST(int parent[], int graph[V][V]){
    printf("Edge\tDistance\n");
    for(int i = 1; i < V; i++)
        printf("%d-%d\t%d\n",parent[i]+1,i+1,graph[i][parent[i]]);
    printf("\n");
}

void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i = 0;i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        for(int v = 0; v <V; v++)
            if(!mstSet[v] && graph[u][v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];

    }
    printMST(parent,graph);
}

int main(){
    int graph[V][V] = {
        {0,4,0,8,0},
        {4,0,3,1,0},
        {0,3,0,7,8},
        {8,1,7,0,3},
        {0,0,8,3,0}
    };

    primMST(graph);
    return 0;
}