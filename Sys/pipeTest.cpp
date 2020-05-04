//#include<bits/stdc++.h>
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string>
#include<memory.h>

int main()
{
    int fd[2];
    
    auto ret = pipe(fd);
    if(ret == -1)
    {
        perror("pipe error\n");
        return 1;
    }
    pid_t id = fork();
    //pid_t id1 = fork();
    if(id == 0) //child
    {
        int i=0;
        close(fd[0]);
        char *child = "i am child!";
        while (i<5)
        {
            write(fd[1],child,sizeof(child)+1);
            sleep(2);
            i++;
        }
    }
    else if(id>0)
    {
        close(fd[1]);
        char msg[100];
        int j=0;
        while(j<5)
        {
            memset(msg,'\0',sizeof(msg));
        }
    }
    
}