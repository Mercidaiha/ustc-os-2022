#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/syscall.h>
int main(){
    int count1;
    int count2;
    long t1;
    int t2;

    int i,j,k;
    int pid1[400];
    int pid2[400];
    long time1[400];
    long time2[400];
    float runtime[400];
    float runtime2[400];
    char name1[6400];
    char name2[6400];
    long state1[400];
    long state2[400];
    int num[400];
    while(1){
        syscall(333,pid1,name1,state1,time1,&count1);
        sleep(1);
        system("clear");
        syscall(333,pid2,name2,state2,time2,&count2);
        j=0;
        i=0;
        while((i<count2)&&(j<count1)){
            if(pid2[i]==pid1[j]){
                runtime[i]=time2[i]-time1[j];
                runtime[i]=runtime[i]/10000000;
                i++;
                j++;
            }
            else if(pid2[i]>pid1[j]){
                j++;
            }
            else if(pid2[i]<pid1[j]){
                runtime[i]=0;
                i++;
            }
        }
        while(i<count2){
            runtime[i++]=0;
        }
        for(i=0;i<count2;i++){
            runtime2[i]=runtime[i];
            num[i]=i;
        }
        for(i=0;i<count2;i++){
            for(j=i+1;j<count2;j++){
                if(runtime[j]>runtime[i]){
                    t1=runtime[i];
                    t2=num[i];
                    num[i]=j;
                    runtime[i]=runtime[j];
                    runtime[j]=t1;
                    num[j]=i;
                }
            }
        }
        printf("        PID             COMM                CPU(%%)             RUNNING\n");
        for(j=0;j<20;j++){
            char name[16];
            t2=num[j];
            for(i=0;i<16;i++){
                name[i]=name2[16*t2+i];
            }
            printf("%10d%20s%20f%20ld\n",pid2[t2],name,runtime2[t2],state2[t2]);
        }
    }
    return 0;
}
