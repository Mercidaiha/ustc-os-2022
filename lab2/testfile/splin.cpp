#include <stdio.h>
//#include<iostream>
#include <stdlib.h>
//#include <unistd.h>
//#include <string.h>
//#include <sys/wait.h>
//#include <sys/types.h>
//#include <fcntl.h>
//#include <errno.h>
//using namespace std;
#define MAX_CMDLINE_LENGTH  1024    /* max cmdline length in a line*/
#define MAX_BUF_SIZE        4096    /* max buffer size */
#define MAX_CMD_ARG_NUM     32      /* max number of single command args */
#define WRITE_END 1     // pipe write end
#define READ_END 0      // pipe read end

/*int split_string(char* string, char *sep, char** string_clips) {
    
    char string_dup[MAX_BUF_SIZE];
    string_clips[0] = strtok(string, sep);
    int clip_num=0;
    
    do {
        char *head, *tail;
        head = string_clips[clip_num];
        tail = head + strlen(string_clips[clip_num]) - 1;
        while(*head == ' ' && head != tail)
            head ++;
        while(*tail == ' ' && tail != head)
            tail --;
        *(tail + 1) = '\0';
        string_clips[clip_num] = head;
        clip_num ++;
    }while(string_clips[clip_num]=strtok(NULL, sep));
    return clip_num;
}*/

int main(){
    char a[256];
    fgets(a,256,stdin);
    char *argv[MAX_CMD_ARG_NUM];
    int argc;
    int i=0,flag=0,j=0,k=0;
    char ch[MAX_CMD_ARG_NUM][256];
            while(a[i]!='\0'){
                if(a[i]==' '){
                    i++;
                    if(flag==0){
                        flag=1;
                        ch[j][k]='\0';
                        j++;
                        k=0;
                    }
                    continue;
                }
                else{
                    if(flag==1) flag=0;
                    ch[j][k]=a[i];
                    i++;
                    k++;
                }
            }
            ch[j][k]='\0';
            argc=(++j);
            while(j--){
                argv[j]=ch[j];
                printf("%s\n",argv[j]);
            }
    printf("%d",argc);
    return 0;
}
