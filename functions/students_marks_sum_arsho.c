/*
Title     : Students Marks Sum
Category  : Functions
Author    : arsho
Created   : 26 May 2018
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int* marks, int number_of_students, char gender) {
    int total=0, i, start=0;
    if(gender=='g') start=1;
    for(i=start;i<number_of_students;i+=2)
    {
        total+=marks[i];
    }
    return total;
}
int main() {
    int number_of_students;
    char gender;
    int sum;

    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));

    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }

    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);

    return 0;
}
