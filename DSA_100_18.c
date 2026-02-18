// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3
#include<stdio.h>
int main(){
    int i , n , j , temp , k;
    printf("Enter the number of terms in array : ");
    scanf("%d" , &n);
    int arr[n];
     for(i=0;i<n;i++){
        printf("Enter the element : ");
        scanf("%d" , &arr[i]);
    }
    printf("Enter the number of rotations :");
    scanf("%d" , &k);
    k = k%n;
    for(i=0,j=n-1;i<j;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
     for(i=k,j=n-1;i<j;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
     for(i=0,j=k-1;i<j;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
     for(i=0;i<n;i++){
        printf("%d " , arr[i]);
     }
    return 0;
}