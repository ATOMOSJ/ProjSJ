#include<stdio.h>
int
no_nonzero (int n, int (*ptr)[n]){
int i, j, count = 0;
for (i = 0; i < n; i++){
for (j = 0; j < n; j++){
if (ptr[i][j]!==0){
count++;
}
}