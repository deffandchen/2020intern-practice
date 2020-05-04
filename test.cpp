#include<iostream>

class A
{
public:
    A(int _size):size(_size)
    {
        data = new int[size];
    }
    
    A(const A &a):size(a.size)
    {
        data = new int[size];
    }

    ~A()
    {
        std::cout<< "data:" << data << std::endl;
        delete [] data;
    }

private:
    int size;
    int* data;
};

void dfs()
{
    A a(5);
    A b = a;
}

int main()
{
    dfs();
    std::cout<< "deepin vs code test." << std::endl;
    return 0;
}