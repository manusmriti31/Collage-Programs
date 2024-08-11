#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int start, finish, value;
} Request;

int compare(const void *a, const void *b){
    return ((Request *)a)->finish - ((Request *)b)->finish;
}

int MaxProfit(Request request[], int n){
    qsort(request,n,sizeof(Request),compare);

    int dp[n];
    dp[0] = request[0].value;

    for(int i = 1; i < n; i++){
        int incprofit = request[i].value;
        for(int j = i -1 ; j >= 0 ; j--){
            if(request[j].finish <= request[i].start){
                incprofit += dp[j];
                break;
            }
        }
        dp[i] = incprofit > dp[i-1] ? incprofit : dp[i-1];
    }
    return dp[n-1];
}

int main(){
    Request request[] = {
        {1,2,100},
        {2,5,200},
        {3,6,300},
        {4,8,400},
        {5,9,500},
        {6,10,100},
    };

    int n = 6;

    printf("The maximum profit is: %d", MaxProfit(request,n));

    return 0;
}
