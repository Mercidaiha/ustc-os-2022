#include<stdio.h>
#include<unistd.h>
int main(){
    //char buff[255];
    //getcwd(buff,255);
    printf("directory: %s",getcwd(NULL,0));
    return 0;
}