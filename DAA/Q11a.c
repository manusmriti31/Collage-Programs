#include<stdio.h>
#include<stdbool.h>

int f_n(int n){
    return ((8*n*n)+(3*n)+3);
}

int g_n(int n){
    return (n);
}

int main(){
    int c = 7;
    int n0 = 1;

    while(true){
        if(c*g_n(n0) <= f_n(n0)){
            printf("The value of n0 = %d\n", n0);
            break;
        }
        n0++;
    }

    printf("f(n)\tc*g(n)\n");
    for(int i = 10; i < 30; i++)
        printf("%d\t%d\n",f_n(i),g_n(i));
    
    return 0;
}