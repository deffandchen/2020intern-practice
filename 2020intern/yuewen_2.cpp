#include<iostream>

class ScopePtr{
public:
    ScopePtr(int *p)
    {
        n =  *p;
    };
    ~ScopePtr()
    {
    };
    ScopePtr operator*(ScopePtr ptr)
    {
        
    };
    int n;
};

void test(int n){
    ScopePtr ptr(new int(n));
    *ptr *= 2;
    std::cout << *ptr << std::endl;
}

int main()
{
    int n=0;
    std::cin >> n;
    test(n);
    return 0;
}