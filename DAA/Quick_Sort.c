/*In a database of numbers there is a table of unsorted numbers. 
The database admin now wants to sort these numbers using an approach wherein a pivot element is selected for sorting. 
At certain point, the first half elements are less than the pivot and right half elements are greater than the pivot. 
Design and implement an algorithm to solve it using random numbers and also display the execution time.
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high -1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printArr(int arr[],int n){
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){

    int n;
    printf("Enter the number of elements in the arr: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));

    for(int i = 0; i < n;i++)
        arr[i] = rand() % 100;

    printf("The input array is: \n");
    printArr(arr,n);

    clock_t start, end;
    double cpu_time;

    start = clock();
    quicksort(arr,0,n-1);
    end = clock();

    cpu_time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("The sorted array is: \n");
    printArr(arr,n);
    printf("\nThe Cpu time for computation is: %f ",cpu_time);

    return 0;

}
