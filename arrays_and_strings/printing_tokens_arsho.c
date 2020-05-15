/*
Title     : Printing Tokens
Category  : Arrays and Strings
Author    : arsho
Created   : 24 May 2018
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    int i, s_length;
    s_length = strlen(s);
    for(i=0;i<s_length;i++)
    {
        if(s[i]==' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}
