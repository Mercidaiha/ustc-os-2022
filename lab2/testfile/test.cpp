#include<stdio.h>
int main(){
    char *a[2];
    char b[10]="abcd";
    a[0]=b;
    if(a[1]!=NULL) printf("1");
    return 0;
}