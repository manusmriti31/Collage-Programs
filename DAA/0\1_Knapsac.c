/*
Alia is planning for a trekking expedition with a backpack that can hold 7kg. She needs to select the most valuable items from the following list that can be accommodated within the backpack. 
Design and implement an algorithm that displays the most valuable items that can be carried by him using Dynamic programming principles. State the design strategy used and time complexity of the same.
*/


#include<stdio.h>

#define MAX(a,b) ((a > b) ? a : b)

void knapsack(int W, int wt[], int val[], int n){
    int k[n+1][W+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i==0 || j == 0)
                k[i][j] = 0;
            else if(wt[i-1] < j)
                k[i][j] = MAX(val[i-1] + k[i-1][j-wt[i-1]],k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }
    int result = k[n][W];
    printf("The maximum value is : %d\n",result);
    printf("The Items that can be taken are:\n");
    printf("Item\tWeight\tValue\n");
    for(int i = n, j = W; i >0 && result > 0; i--){
        if(result != k[i-1][j]){
            printf("%d\t%d\t%d\n",i,wt[i-1],val[i-1]);
            result -= val[i-1];
            j -= wt[i-1];
        }
    }
}

int main(){
    int val[] = {10,4,9,11};
    int wt[] = {3,5,6,2};
    int W = 7;
    int n = 4;

    knapsack(W,wt,val,n);

    return 0;
}
