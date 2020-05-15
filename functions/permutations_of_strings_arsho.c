/*
Title     : Permutations of Strings
Category  : Functions
Author    : arsho
Created   : 27 May 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int k, int l){
    char *temp = s[k];
    s[k] = s[l];
    s[l] = temp;
}

int next_permutation(int n, char **s)
{
	/**
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
    * Ref: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
	*/
    int i, j, k, l;
    k=-1;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(s[i], s[j])<0){
                k=i;
            }
        }
    }
    if(k==-1)
        return 0;
    for(i=k+1;i<n;i++){
        if(strcmp(s[i], s[k])>0){
            l=i;
        }
    }
    swap(s, l, k);
    int end = n-1;
    for(i=k+1;i<n;i++){
        if(end<=i)break;
        swap(s, i, end);
        end--;
    }
    return 1;
}
int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
