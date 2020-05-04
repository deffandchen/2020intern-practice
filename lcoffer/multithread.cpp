#include<iostream>
#include<pthread.h>

using namespace std;

void* print(void* args)
{
    cout << "hello thread!" << endl;
    return 0;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,print,NULL);
    pthread_exit(NULL);
    return 0;
}