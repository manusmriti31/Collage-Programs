#include<stdio.h>
#include<stdbool.h>

int f_n(int n){
    return ((5*n*n)+(6*n)+3);
}

int g_n(int n){
    return (n*n);
}

int main(){
    int c1 = 4, c2 = 6;
    int n0 = 1;

    while(true){
        if(c1*g_n(n0) <= f_n(n0) && f_n(n0) <= c2*g_n(n0)){
            printf("The value for n0 = %d\n",n0);
            break;
        }
        n0++;
    }

    printf("c1*g(n)\tg(n)\tc2*g(n)\n");
    for(int i = 10; i < 30; i++)
        printf("%d\t%d\t%d\n",c1*g_n(i),f_n(i),c2*g_n(i));
    
    return 0;
}