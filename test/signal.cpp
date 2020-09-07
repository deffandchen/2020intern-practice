#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h> // 信号量函数库
#include <unistd.h>

#define SEM_FILE "/Users/meetmax/CWork/sem_file" // 信号量文件

union sem_union //信号量联合
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

//初始化信号量
int init_sem(int sem_id,int val)
{
    union sem_union tmp;
    tmp.val = val;
    if((semctl(sem_id,0,SETVAL,tmp)) == -1)
    {
        perror("初始化信号量失败");
        return -1;
    }
    return 0;
}

/**
 * P操作
 * 信号量大于0时执行 -1 操作，获取资源
 * 若信号量 <= 0 则挂起等待
*/
int sem_p(int sem_id)
{
    struct sembuf sbuf;
    sbuf.sem_num = 0;
    sbuf.sem_op = -1;
    sbuf.sem_flg = SEM_UNDO;
    if(semop(sem_id,&sbuf,1) == -1)
    {
        perror("p操作失败");
        return -1;
    }
    return 0;
}

/**
 * V操作
 * 信号量 <= 0时执行，+1操作，释放资源
 * 若信号量 > 0 时挂起等待
 */
int sem_v(int sem_id)
{
    struct sembuf sbuf;
    sbuf.sem_num = 0;
    sbuf.sem_op = 1;
    sbuf.sem_flg = SEM_UNDO;
    if(semop(sem_id,&sbuf,1) == -1)
    {
        perror("V操作失败");
        return -1;
    }
    return 0;
}

//删除信号量
int sem_del(int sem_id)
{
    union sem_union tmp;
    if(semctl(sem_id,0,IPC_RMID,tmp) == -1)
    {
        perror("删除信号量失败");
        return -1;
    }
    return 0;
}

int main()
{
    int sem_id;
    key_t key;
    pid_t pid;

    //获取key值
    if((key = ftok(SEM_FILE,100)) == -1)
    {
        perror("获取key值失败");
        exit(1);
    }
    //获取信号量id
    if((sem_id = semget(key,1,IPC_CREAT|0666)) == -1)
    {
        perror("信号量id获取失败");
        exit(1);
    }

    //初始化信号量
    init_sem(sem_id,0);

    //fork进程
    if((pid = fork()) == -1)
    {
        perror("进程fork失败");
        exit(1);
    }else if(pid == 0){ //子进程
        printf("我是子进程：%d \n",getpid());
        sleep(2);
        sem_v(sem_id);
    }else if(pid > 0){ //父进程
        sem_p(sem_id);
        printf("我是父进程：%d \n",getpid());
        sem_v(sem_id);
        sem_del(sem_id);
    }
    return 0;
}