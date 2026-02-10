/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    fgets(string, sizeof(string), stdin);
    int length = strlen(string);
    length -= 1;
    for (int i = 0; i < (strlen(string) - 1); i++)
    {
        if (string[i] != string[length - 1])
        {
            printf("NO");
            return 0;
        }
        length -= 1;
    }
    printf("YES");
    return 0;
}