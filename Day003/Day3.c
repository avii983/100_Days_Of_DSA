/*Linear Search with Comparison Count

Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include<stdio.h>
#include<stdlib.h> 
int main(){
    int n , element = 0 , counter = 0;
    scanf("%d" , &n);
    int* arr = malloc(n * sizeof(int));
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d" , &arr[i]);
    }
    printf("\n");
    scanf("%d" , &element);
    for(int i = 0; i < n; i++)
    {
        if(element == arr[i])
        {
            counter += 1;
            printf("Found at index %d\n" , i);
            printf("Found in %d comparisons" , counter );
            return 0;
        }
        else{
            counter += 1;
        }
    }
    printf("The element %d is not present in not present in the array\n" , element);
    free(arr);
    return 0;


}
