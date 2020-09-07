#include <vector>  
#include <string>  
#include <iostream>  

using namespace std;
class ScopePtr{
public:
 explicit ScopePtr(int *p = 0) :px(p) {}
 int & operator*()const
 {
  return *px;
 }

private:
 int *px;
};
void test(int n)
{
 ScopePtr ptr(new int(n));
 *ptr *= 2;
 cout << *ptr << endl;
}

int main()
{
 test(5);
 system("pause");
 return 0;
}