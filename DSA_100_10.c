#include<stdio.h>
#include<string.h>
int main() {
    int isPalindrome=0;
    char str[1000];
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    isPalindrome = 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }
    printf("%s\n", isPalindrome ? "YES" : "NO");
    return 0;
}