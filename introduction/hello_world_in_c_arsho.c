/*
Title     : "Hello World!" in C
Category  : Introduction
Author    : arsho
Created   : 05 May 2018
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%[^\n]%*c", &s);
    printf("Hello, World!\n%s\n",s);
    return 0;
}
