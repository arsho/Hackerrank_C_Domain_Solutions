/*
Title     : Printing Pattern using Loops
Category  : Conditionals and Loops
Author    : arsho
Created   : 12 May 2018
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int length, i, j, temp, current;
    length = (n*2) - 1;
    current = n;
    for(i=0;i<length/2;i++)
    {
        if(current==n)
        {
            for(j=0;j<length;j++)
            {
                if(j!=0)
                {
                    printf(" ");
                }
                printf("%d",n);
            }
        }
        else
        {
            for(j=n;j>current;j--)
            {
                if(j!=n)
                {
                    printf(" ");
                }
                printf("%d",j);
            }
            temp = length - (n - current)*2;
            for(j=0;j<temp;j++)
            {
                printf(" %d",current);
            }
            for(j=current+1;j<=n;j++)
            {
                printf(" %d",j);
            }
        }
        printf("\n");
        current-=1;
    }

    for(i=n;i>=1;i--)
    {
        if(i!=n)
        {
            printf(" ");
        }
        printf("%d", i);
    }
    for(i=2;i<=n;i++)
    {
        printf(" %d", i);
    }
    printf("\n");

    current=2;
    for(i=0;i<length/2;i++)
    {
        if(current==n)
        {
            for(j=0;j<length;j++)
            {
                if(j!=0)
                {
                    printf(" ");
                }
                printf("%d",n);
            }
        }
        else
        {
            for(j=n;j>current;j--)
            {
                if(j!=n)
                {
                    printf(" ");
                }
                printf("%d",j);
            }
            temp = length - (n - current)*2;
            for(j=0;j<temp;j++)
            {
                printf(" %d",current);
            }
            for(j=current+1;j<=n;j++)
            {
                printf(" %d",j);
            }
        }
        printf("\n");
        current+=1;
    }

    return 0;
}
