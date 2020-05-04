#include<iostream>
using namespace std;

union Data
{
    struct
    {
        int x;
        int y;
        int z;
    }s;
    int x,y;

}d;


void test(char **p)
{
    *p = *p + 1;
}

int main()
{
    char s[] = {'a','c','1','q'};
    //test(&s);
    printf("%c",*s);
    d.x = 1;
    d.y = 2;
    int i = 10;

    cout << i + "aa" << endl;
    cout << "x: " << d.x << "  y: " << d.y << endl;
    //d.s.x = d.x * d.x;
    d.s.y = d.y + d.y;
    cout<< "are you ok?" << endl;
    cout << "dx pos: " << &d.x << "  dy pos: " << &d.y << endl;
    cout << "dsx pos: " << &d.s.x << "  dsy pos: " << &d.s.y <<" dsz pos" << &d.s.z << endl;
    
    cout << "x: " << d.s.x << "  y: " << d.s.y << endl;
    return 0 ;
}