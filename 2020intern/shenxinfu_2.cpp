#include<bits/stdc++.h>

using namespace std;

int main()
{
    int jilu,day,date,money;
    map<int,int> num;
    cin >> jilu;
    for(int i=0;i<jilu;i++)
    {
        cin >> day >> date >> money;
        num[date] = money;
    }
    int start = 0,s_max=0,max=0, tmp_max = 0;
    for(auto m:num)
    {
        if(start+7200 > m.first)
        {
            tmp_max += m.second;
            if(tmp_max>max) 
            {
                max = tmp_max;
            }
        }
        else
        {
            
        }
        
    }
    return 0;
}

/*
64
1 8924 25
1 23860 28
2 1507 19
2 4675 12
2 16096 26
3 2098 25
3 3389 16
3 29309 18
4 27966 15
5 11983 21
5 15966 27
5 20545 22
6 30106 29
6 30345 25
7 14043 28
7 19831 24
7 26007 11
8 2867 23
8 24790 29
9 11038 14
9 12900 12
9 31312 24
10 7808 26
11 6653 27
12 1717 22
12 3224 10
13 14767 25
14 2832 19
14 7304 17
15 9505 18
15 30210 25
15 30560 12
16 1139 21
17 15881 27
18 10401 26
18 10404 26
19 16120 23
20 95 14
20 12362 18
20 29878 28
21 9647 14
21 23625 16
22 42 20
22 12736 26
22 20244 10
23 28391 24
23 29059 20
24 569 24
25 29749 17
25 31544 25
26 22051 21
26 30478 28
27 22746 10
27 28157 10
27 30513 16
28 19401 24
28 20430 18
28 26960 15
29 17300 13
29 24550 11
29 25798 17
30 19155 14
30 21469 21
31 5166 24
*/