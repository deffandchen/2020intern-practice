#include<bits/stdc++.h>

using namespace std;
unique_ptr<int> ptr;
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

class Derive : protected Base
{
public:
    Derive() {};
    void func(int a) override;

};

void Derive::func(int a)
{
    cout << x << endl;
}

class Dderive : public Derive{
    public:
        Dderive() {};
        void test() {
            cout << x << endl;
        };
};
//深拷贝与浅拷贝
//unique_ptr实现

struct Byte{
    char c ;
    //char a[10];
    short j;
    int i = 4;
    
};
union com{
    int x ;
    int y;
    double s;
};

int main()
{
    com c;
    c.x = 1;
    c.s = 2;
    //string s="flkshd";
    cout << sizeof(Byte) <<endl;
    string str = "dasgd";
    str += string {'c'};
    cout << str << endl;
    cout << sizeof(Byte) << endl;
    int b = 1;
    auto a = [b]() -> int {return b;};

    const char* cp = new char('a');
    //string b = static_cast<string>(cp);
    char* p1 = const_cast<char*>(cp);
    p1[0] = 'd';
    shared_ptr<string> p(new string("ab"));
    cout << "p:" << p.use_count() << endl;
    {
        vector<shared_ptr<string>> vec;
        shared_ptr<string> p2(p);
        cout << "p:" << p.use_count() << endl;
        cout << "p2:" <<p2.use_count() << endl;
        vec.push_back(p2);
        cout << "p:" << p.use_count() << endl;
        cout << "p2:" <<p2.use_count() << endl;
    }
    cout << "p:" << p.use_count() << endl;
    return 0;
}
