/*
Title     : 1D Arrays in C
Category  : Arrays and Strings
Author    : arsho
Created   : 20 May 2018
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int *ar = (int*)malloc(n*sizeof(int));
    int i, total=0, temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        ar[i] = temp;
    }
    for(i=0;i<n;i++)
    {
        total+=ar[i];
    }
    printf("%d\n",total);
    return 0;
}
