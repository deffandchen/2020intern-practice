    #include<iostream>
    #include<string>
    using namespace std;
    
    int myAtoi(string str) {
        int len = str.size();
        string sub;
        for(int i=0;i<len;i++)
        {
            if(sub.empty() && str[i]==' ')
            {

            }
            else if(sub.empty() && (str[i]=='+' || str[i]=='-'))
            {
                sub += str[i];
            }
            else if(str[i]>='0' && str[i]<='9')
            {
                sub += str[i];
            }
            else
            {
                break;
            }
        }
        long ans=0,j=0;
        if(sub.size()>10) return 0;
        else
        {
            ans = stol(sub);
        }
        if(ans>INT_MAX || ans<INT_MIN) return 0; 
        return ans;
    }

    int main()
    {
        string a = "   +-42";
        int b = myAtoi(a);
        cout << b << endl;
        return 0;
    }