/*
Title     : Small Triangles, Large Triangles
Category  : Structs and Enums
Author    : arsho
Created   : 29 May 2018
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double calculate_triangle_area(triangle tr){
    double p;
    p = (tr.a+tr.b+tr.c)/2.0;
    return sqrt(p*(p-tr.a)*(p-tr.b)*(p-tr.c));
}

int comparator(const void *v1, const void *v2){
    const triangle *tr1 = v1;
    const triangle *tr2 = v2;
    double tr1_area = calculate_triangle_area(*tr1);
    double tr2_area = calculate_triangle_area(*tr2);
    if(tr1_area>tr2_area) return 1;
    if(tr1_area<tr2_area) return -1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    qsort(tr, n, sizeof(triangle), comparator);
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
