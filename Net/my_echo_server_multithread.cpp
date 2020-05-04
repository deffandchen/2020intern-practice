#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<pthread.h>
#include<thread>

class Sock{
public:
    Sock(int x);
    ~Sock();
    void create_sock();
    void accept_connect();
    static void echo(int c_fd);   //类内成员作为静态变量，只需在类内定义时加上static，
                                  //在类外声明时不用加static
    //static void* echo(void * c_fd);//使用pthread_create创建线程时使用该函数
private:
    int serfd,confd;
    int port;
    int max_size = 1024;
    struct sockaddr_in seraddr,conaddr;
};

Sock::Sock(int x){
    port = x;
    memset(&seraddr,0,sizeof(seraddr));
    memset(&conaddr,0,sizeof(conaddr));
}
Sock::~Sock(){
    close(serfd);
    close(confd);
}

void Sock::create_sock(){
    serfd = socket(AF_INET,SOCK_STREAM,0);
    if(serfd==-1)
    {
        perror("sock error!");
        return ;
    }

    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_port = htons(port);
    bind(serfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
    listen(serfd,max_size);
}

void Sock::accept_connect(){
    socklen_t conaddr_len = sizeof(conaddr);
    while(1){
        confd = accept(serfd,(struct sockaddr *)&conaddr,&conaddr_len);
        if(confd < 0)
        {
            perror("accept error!");
        }
        printf("connect id:%s,port:%d\n",inet_ntoa(conaddr.sin_addr),ntohs(conaddr.sin_port));

        //pthread_t t;
        //pthread_create(&t,NULL,&echo,&confd);  //使用pthread创建线程
        
        std::thread t1(echo,confd); //使用c++11 thread库创建线程
        t1.detach();
    }
}

//类内成员作为静态变量，只需在类内定义时加上static，在类外声明时不用加static
void Sock::echo(int c_fd){
    int client_fd = c_fd;
    int buf_len = 1024;
    char rec_buf[buf_len];
    char send_buf[buf_len];
    while(recv(client_fd,rec_buf,buf_len,0)>0)
    {
        printf("from client:%s\n",rec_buf);
        strcpy(send_buf,rec_buf);
        send(client_fd,send_buf,strlen(send_buf),0);
    }
}
//使用pthread_create创建线程时使用该函数
/*
void* Sock::echo(void* c_fd){
    int client_fd = *(int *)c_fd;
    int buf_len = 1024;
    char rec_buf[buf_len];
    char send_buf[buf_len];
    while(recv(client_fd,rec_buf,buf_len,0)>0)
    {
        printf("from client:%s\n",rec_buf);
        strcpy(send_buf,rec_buf);
        send(client_fd,send_buf,strlen(send_buf),0);
    }
}
*/
int main()
{
    Sock my_ser(1234);
    printf("start creat sock\n");
    my_ser.create_sock();
    printf("wait connect...\n");
    my_ser.accept_connect();
    return 0;
}