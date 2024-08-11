#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int f_n(int n){
    return ((6*n*n)+(2*n)+2);
}

int g_n(int n){
    return (n*n);
}

int main(){
    int n0 = 1, c = 7;

    while(true){
        if(f_n(n0) <= c*g_n(n0)){
            printf("The value of n0 = %d\n",n0);
            break;
        }
        n0++;
    }

    printf("f(n)\tg(n)\n");
    for(int i = 10; i < 30; i++)
        printf("%d\t%d\n",f_n(i),g_n(i));
    
    return 0;
}