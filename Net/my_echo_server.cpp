#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

class Sock{
public:
    Sock(int x);
    ~Sock();
    void create_sock();
    void accept_connect();
    void echo(int client_fd);

private:
    int serfd,confd;
    int port;
    int max_size = 1024;
    struct sockaddr_in seraddr,conaddr;
};

Sock::Sock(int x){
    port = x;
    //memset(&seraddr,0,sizeof(seraddr));
    //memset(&conaddr,0,sizeof(conaddr));
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
        echo(confd);
    }

}

void Sock::echo(int client_fd){
    char rec_buf[max_size];
    char send_buf[max_size];
    while(recv(client_fd,rec_buf,max_size,0)>0)
    {
        printf("from client:%s\n",rec_buf);
        strcpy(send_buf,rec_buf);
        send(client_fd,send_buf,strlen(send_buf),0);
    }
}

int main()
{
    Sock my_ser(1234);
    printf("start creat sock\n");
    my_ser.create_sock();
    printf("wait connect...\n");
    my_ser.accept_connect();
    return 0;
}