#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n);


int main(){
    int a[10] = {12,43,-23,3,6,4,-45,6,8,86};

    insertionSort(a,sizeof(a)/sizeof(a[0]));

    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
    return 0;

}

void insertionSort(int *a, int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int toPlace = a[i];
        while(j>=0 && a[j] > toPlace){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = toPlace;
    }
}