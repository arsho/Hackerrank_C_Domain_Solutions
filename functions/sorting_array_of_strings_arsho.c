/*
Title     : Sorting Array of Strings
Category  : Functions
Author    : arsho
Created   : 02 May 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_number_of_distinct_characters(const char* a){
    int is_letter_used[26] = {0};
    int i, total_distinct_characters = 0;
    for(i=0;i<strlen(a);i++){
        if(a[i]>='a' && a[i]<='z')
            is_letter_used[a[i]-'a']=1;
    }
    for(i=0;i<26;i++){
        total_distinct_characters += is_letter_used[i];
    }
    return total_distinct_characters;
}

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i;
    int distinct_characters_a = get_number_of_distinct_characters(a);
    int distinct_characters_b = get_number_of_distinct_characters(b);
    //printf("%s %d, %s %d\n", a, unique_a_total, b, unique_b_total);
    if(distinct_characters_a == distinct_characters_b){
        return lexicographic_sort(a, b);
    }
    return distinct_characters_a > distinct_characters_b;
}

int sort_by_length(const char* a, const char* b) {
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);
    if(strlen_a == strlen_b){
        return lexicographic_sort(a, b);
    }
    return strlen_a > strlen_b;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i, j;
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            if((*cmp_func)(arr[i], arr[j])>0){
                char* temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
