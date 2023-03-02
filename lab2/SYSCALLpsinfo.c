SYSCALL_DEFINE5(ps_info, int __user *, pid_ls, char __user *, name_ls, long  __user *, sta,long __user *,exectime,int __user *,count){
    struct task_struct* task;
    pid_t p;
    int counter = 0;
    int i=0;
    long stat;
    printk("[Syscall] ps_info\n");
    for_each_process(task){
    	counter ++;
        p = task->pid;
        stat = task->state;
        copy_to_user(pid_ls+i, &p,sizeof(int));
        copy_to_user(name_ls+16*i,task->comm,16*sizeof(char));
        copy_to_user(sta+i,&stat,sizeof(long));
        copy_to_user(exectime+i,&(task->se.sum_exec_runtime),sizeof(long));
        copy_to_user(count, &counter, sizeof(int));
        i++;
    }
    return 0;
}
