/*
Title     : Calculate the Nth term
Category  : Functions
Author    : arsho
Created   : 23 May 2020
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_nth_term(int n, int a, int b, int c) {
    if(n == 3)return c;
    if(n == 2)return b;
    if(n == 1)return a;
    int d = a+b+c;
    return find_nth_term(n-1,b,c,d);
}

int main() {
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);
    return 0;
}
