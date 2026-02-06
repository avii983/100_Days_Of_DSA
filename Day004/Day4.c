/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/
#include <stdio.h>
#include <stdlib.h>
int reversing(int *arr , int n , int last_element){
    int swap = 0; 
    for(int i = 0; i < n/2; i++)
    {
        swap = arr[i];
        arr[i] = arr[last_element];
        arr[last_element] = swap;
        last_element -= 1;
    }

printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d" , arr[i]);
        printf(" ");
    }
    return 0;
}
int main(){
            int n;
            scanf("%d" , &n);
            int* arr = malloc(n * sizeof(int));
            printf("\n");
            for(int i = 0; i < n; i++)
            {
                scanf("%d" , &arr[i]);
            }
            int last_element = n - 1;
            reversing(arr , n , last_element);
            free(arr);
            return 0;

}
