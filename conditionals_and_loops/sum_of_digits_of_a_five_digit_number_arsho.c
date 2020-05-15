/*
Title     : Sum of Digits of a Five Digit Number
Category  : Conditionals and Loops
Author    : arsho
Created   : 08 May 2018
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    printf("%d\n",sum);
    return 0;
}
