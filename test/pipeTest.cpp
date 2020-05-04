#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string>
#include<windows.h>
//#include"stdafx.h"
int main()
{
    int fd[2];
    CreateNamedPipe();
    auto ret = pipe(fd);
}