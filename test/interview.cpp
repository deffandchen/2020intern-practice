#include <iostream>
#include <cstdlib>
#include<exception>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

void test(vector<int*>& res){
    int a = 1;
    res.push_back(&a);
}

int main()
{
    int a = 5;
    vector<int*> res;
    
    res.push_back(&a);
   
    test(res);
    
    cout<<res.size()<<endl;
    
    for(auto iter: res){
        cout<< *iter<<endl;
    }
    
}