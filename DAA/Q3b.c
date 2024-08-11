#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    int Leftarr[n1], Rightarr[n2];

    for(int i = 0; i < n1; i++)
        Leftarr[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        Rightarr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if(Leftarr[i] <= Rightarr[j]){
            arr[k] = Leftarr[i];
            i++;
        }
        else{
            arr[k] = Rightarr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = Leftarr[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = Rightarr[j];
        j++;
        k++;
    }

}

void mergesort(int arr[], int left, int right){
    if (left<right){
        int mid = left + (right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void printarr(int arr[], int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");    
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));
    for(int i = 0; i < n; i++)
        arr[i] = rand()%100;
    
    printf("The input array is: \n");
    printarr(arr,n);

    clock_t start, end;
    double cpu_time;

    start = clock();
    mergesort(arr,0,n-1);
    end = clock();

    cpu_time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("The sorted array is: \n");
    printarr(arr,n);

    printf("The CPU Computaional time is: %f\n",cpu_time);
    
    return 0;
}