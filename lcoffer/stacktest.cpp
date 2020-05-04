#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<memory>
#include<list>
#include<vector>
#include<string>
using namespace std;

bool isMatch(string s, string p) {
    stack<char> mstack;
    int ls = s.size();
    int lp = p.size();
    map<char,int> repeat;
    if(ls == 0 && lp == 0)
        return true;
    else if(ls != 0 && lp == 0)
        return false;
    
    for(int i = 0; i<ls;++i)
    {
        mstack.push(s[i]);
    }
    int j = lp - 1;
    while(j >= 0)
    {
        if(p[j] == '*')
        {
            if(p[j-1] == '.')
            {
                while(!mstack.empty())
                {
                    repeat[mstack.top()] += 1;
                    mstack.pop();
                }
            }
            else
            {
                while(p[j-1] == p[j-2])
                {
                    j -= 1;
                }

                while(!mstack.empty() && p[j-1] == mstack.top())
                {
                    repeat[mstack.top()] += 1;
                    mstack.pop();
                }
            }   
            j -= 2;
        }
        else if(p[j] == '.')
        {
            mstack.pop();
            j -= 1;
        }
        else if(!mstack.empty() && p[j] == mstack.top())
        {
            mstack.pop();
            j -= 1;
        }
        else
            return false;
        
        if(mstack.empty() && (j >= 0))
        {
            while(j>=0)
            {
                if(repeat.find(p[j]) != repeat.end())
                {
                    repeat[p[j]] -= 1;
                    if(repeat[p[j]] < 0)
                        return false; 
                    j -= 1;
                }
                else if(p[j] == '*' && j > 0)
                {
                    if(p[j-1] == '.')
                        return true;
                    else
                    {
                        j = j - 2;
                    }
                }
                else
                    return false;
                
            }
        }
        if(mstack.empty() && (j < 0))
            return true;
    }
    return false;
}

int overload(int i)
{
    cout << "int" << endl;
    return i;
}

int overload(int i,int j)
{
    cout << "void" << endl;
    overload(i);
    return 0;
}


class A
{
private:
    /* data */
    
public:
    A() {cout << "build A class" << endl;}
    virtual ~A() = default;
    void func(int i,int j) { cout << "int int" << endl;}
    virtual void func(int i) {cout << "int" << i << endl;}
protected:
     double price = 0.0;
};

class B : private A
{
private:
    /* data */
    int pri = 0;
public:
    int pub = 0;
    B() { cout << "build B class" << endl;}
    void foo() { cout << price << endl;}
    void func(int i) override {cout << "double" << i + 1 << endl;}
};

void test(B &temp)  //test的形参是类A 但可传入A的派生类B ,这就是动态绑定
{
    int i = 1;
    temp.func(i);
}

void queue_test()
{
    queue<int> mqueue;
    for(int i = 0;i<8;++i)
    {
        mqueue.push(i);
        cout << "queue front:" << mqueue.front() << endl;
        mqueue.pop();
        cout << "queque back:" << mqueue.back() << endl;
    }
}

class CandidateSum
{
private:
    /* data */
    vector<int> candida;
    
public:
    vector<vector<int> > res;
    vector<int> tmp;

public:

    void helper(int start, int target)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = start;i < candida.size() && candida[i] <= target; ++i)
        {
            tmp.push_back(candida[i]);
            helper(i,target - candida[i]);
            tmp.pop_back();   //不满足条件弹出 体现了回溯的思想
        }
    }
public:
    void candidate(vector<int> can)
    {
        this->candida = can;
        helper(0,7);
    }
};

class telephoneNum
{
private:
    /* data */
    string digits;
    int digits_size = 0;
public:
    vector<string> tmp;
    void helper(char digit, vector<vector<char> > num_char)
    {
        int num_digit = digit;
        if(digit == digits[digits_size - 1])
        {

        }

        for(int i = 0; i < num_char[num_digit].size(); ++i)
        {
            tmp.push_back(string{num_char[num_digit][i]});
            helper(num_char[num_digit][i],num_char);

        }
    }
};
vector<int> aux;
void testaa(vector<int> &con)
{
    for(int i = 0;i<5;++i)
    {
        aux.push_back(con[i]);
        aux.push_back(con[i] * 2);
    }
}

vector<int> shell_sort(vector<int> arry, int N)
{
    int tmp = 0;

    for(int i = N / 2; i > 0; i /= 2)
    {
        for(int j = 0;j < N-i;++j)
        {
            if(arry[j] > arry[j+i])
            {
                tmp = arry[j+i];
                arry[j+i] = arry[j];
                arry[j] = tmp;
            }

            for(int k = 0;k<N;++k)
            {
                cout << arry[k] << " ";
            }
            cout << endl;
        }
    }

    return arry;
}

int main()
{
    int j = 0;
    vector<int> input{20,3,15,7,10};
    vector<int> res;
    res = shell_sort(input,5);
    testaa(input);
    CandidateSum candidatesum;
    //candidatesum.candidate(input);

    vector<vector<char> > num2str{{'a','b','c'},{'d','e','f'},{'w','x','y','z'}};
    cout << "num0 size:" << num2str[2].size() << endl;

    //shared_ptr<int> p(new int(0));
    //A a;
    B b;
    test(b);  //
    queue_test();
    

    if(isMatch("aa","a*") == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    
    /*
    stack<char> mstack;
    string a = "yangou";
    for(int i = 0;i<5;++i)
    {
        mstack.push(a[i]); 
        cout << "stack top:" << mstack.top() << endl;
        
    }

    while(!mstack.empty())
    { 
        cout << "stack top:" << mstack.top() << endl;
        mstack.pop();
    }
    */
}