#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int f_n(int n){
    return ((8*n*n) + (3*n) + 3);
}

int g_n(int n){
    return n;
}

int main(){
    int n0 = 1;
    int c = 1;

    while(true){
        if(f_n(n0) >= g_n(n0)){
            printf("For f(n) = Omega(n)\n");
            printf("The value of C = %d and the value of n0 = %d",c,n0);
            break;
        }
        n0++;
    }

    printf("\nf(n)\tg(n)\n");
    for(int i = 10; i < 30; i++){
        printf("%d\t%d\n",f_n(i),g_n(i));
    }
}