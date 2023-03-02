#include<stdio.h>
#include<unistd.h>
int main(){
    char a[20];
    char *argv;
    scanf("%s",a);
    argv=a;
    printf("%s\n",argv);
    chdir(argv);
    printf("%s\n",getcwd(NULL,0));
    return 0;
}