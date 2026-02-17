// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1
#include <stdio.h>
int main() {
    int n , j , i , min , max;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    max = min = arr[0];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                max = arr[i];
            }
            else{
                max = arr[j];
            }
        }
        }
    printf("MAX : %d" , max);
        for(i=1;i<n;i++){
            if(arr[i]<min){
            min = arr[i];
        }
    }
        printf("\nMIN : %d" , min);
}