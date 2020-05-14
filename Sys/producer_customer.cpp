#include<iostream>
#include<queue>
#include<thread>
#include<unistd.h>
#include<mutex>
#include<chrono>
#include<condition_variable>

using namespace std;

deque<int> buff; 
mutex mtx;
condition_variable condVar;

void producer(int val)
{
    for(int i=0;i<10;i++)
    {
        {
            unique_lock<mutex> l(mtx);
            buff.push_back(val+i);
        }
        condVar.notify_all();
        this_thread::sleep_for(chrono::milliseconds(val));
    }
}

void customer(int num)
{
    int front;
    while (true)
    {
        {
            unique_lock<mutex> l(mtx);
            condVar.wait(l,[]{return !buff.empty();});
            front = buff.front();
            buff.pop_front();
        }
        cout << "customer" << num << ":" << front << endl;
    }    
}

int main()
{
    thread t1(producer,100);
    thread t2(producer,300);
    thread t3(producer,500);

    thread t4(customer,1);
    thread t5(customer,2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    return 0;
}
