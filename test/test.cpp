#include<bits/stdc++.h>

using namespace std;

class Base
{
public:
    Base() {};
    virtual void func(int a);
public:
    int x = 1;
};
void Base::func(int a)
{
    cout << x << endl;
}

class Derive : public Base
{
public:
    Derive() {};
    void func(int a) override;
public:
    int x = 2;
};

void Derive::func(int a)
{
    cout << x << endl;
}

int main()
{
    Base* tmp = new Derive;
    tmp->func(1);
    return 0;
}