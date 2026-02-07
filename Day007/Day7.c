/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/
#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n){
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
            int n  , sum = 0;
            scanf("%d" , &n);
            sum += fibonacci(n);
            printf("\n");
            printf("%d" , sum);
            return 0;
}