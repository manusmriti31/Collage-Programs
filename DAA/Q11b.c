#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 6
#define E 10

struct Edge{
    int src, dest, wt;
};

void BellmanFord(struct Edge edges[], int src){
    int dist[V];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;
    
    for(int i = 0; i <= V-1; i++){
        for(int j = 0; j < E; j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].wt;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

    for(int j = 0; j < E; j++){
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].wt;
        if(dist[u] != INT_MAX && dist[u]+weight < dist[v]){
            printf("Negative Cycle found!");
            return;
        }
    }

    printf("Vertex\tDistance from source\n");
    for(int i = 0; i < V; i++)
        printf("%d\t%d\n",i,dist[i]);


}

int main(){
    struct Edge edges[]= {
        {0,1,-4},
        {0,5,-3},
        {1,3,-1},
        {1,4,-2},
        {2,1,8},
        {2,5,3},
        {3,0,6},
        {3,5,4},
        {4,5,2},
        {4,2,-3},
    };

    int src = 0;

    BellmanFord(edges,src);

    return 0;
}