/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>
#include <stdlib.h>
int main(){
     int r , c , count = 0;
     scanf("%d" , &r);
     scanf("%d" , &c);
     int (*arr)[c] = malloc(sizeof(int) * r * c);
     for(int i = 0; i < r; i++)
     {
        for(int j = 0; j < c; j++)
        {
            scanf("%d" , &arr[i][j]);
        }
     }
     for(int i = 0; i < r - 1; i++)
     {
        for(int j = 0; j < c - 1; j++)
        {
            if(i == j)
            {
                if(arr[i][j] != arr[i + 1][j + 1])
                {
                  count += 1;
                }
            }
        }
     }
     if(count > 0)
     {
        printf("This matrix is not an identity matrix\n");
     }
     else{
        printf("This matrix is identity matrix\n");
     }
     return 0;
}