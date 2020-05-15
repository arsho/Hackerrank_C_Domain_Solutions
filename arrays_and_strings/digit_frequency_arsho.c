/*
Title     : Digit Frequency
Category  : Arrays and Strings
Author    : arsho
Created   : 25 May 2018
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int count[11]={0};
    char s[1001];
    scanf("%s",s);
    int s_length = strlen(s);
    int i, j;
    for(i=0;i<s_length;i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            count[s[i]-'0']+=1;
        }
    }
    for(i=0;i<10;i++)
    {
        if(i!=0){
            printf(" ");
        }
        printf("%d", count[i]);
    }
    printf("\n");
    return 0;
}
