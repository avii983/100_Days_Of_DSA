/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/
#include <stdio.h>
#include <stdlib.h>
int powering(int n , int m){
                             if(m == 0)
                             {
                                return 1;
                             }
                             return n *powering(n , m - 1);
}
int main(){
            int n , m , result = 0;
            scanf("%d %d" , &n , &m);
            result = powering(n , m);
            printf("\n");
            printf("%d" , result);
            return 0;
        
}