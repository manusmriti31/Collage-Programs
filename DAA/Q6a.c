#include<stdio.h>
#include<stdlib.h>

void generate_data(int start,int end, int c){
    for(int n = start; n <= end; n++){
        int f_n = (8*n*n) + (3*n) + 3;
        int g_n = (c*n*n);
        printf("%d\t%d\t%d\n",n,f_n,g_n);
    }
}

int main(){
    int start = 10, end = 30;
    int c = 9;
    generate_data(start,end,c);
    return 0;
}