/*
Title     : Pointers in C
Category  : Introduction
Author    : arsho
Created   : 07 May 2018
*/

#include <stdio.h>

void update(int *a,int *b) {
    int p, m;
    p = *a + *b;
    m = abs(*a - *b);
    *a = p;
    *b = m;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
