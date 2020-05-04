#include<iostream>
#include<vector>
using namespace std;

class A
{
    public:
        A(){};
    void func(int x);
    private:
        vector<int> dat;
};

void A::func(int x)
{
    dat.push_back(x);
}

int main()
{
    A a;
    a.func(1);
    A b = a;
    
    return 0;
}