#include<bits/stdc++.h>

using namespace std;
struct Point{
    int x;
    int y;
};
bool cmp(Point a,Point b)
{
    if(a.x <= b.x)
        return true;
    else 
        return false;
}
int main()
{
    int x=0,y=0;
    vector<Point> vec;
    while(cin >> x >> y)
    {
        Point p;
        p.x = x;
        p.y = y;
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(auto iter=vec.begin();iter!=vec.end();++iter){
        cout << iter->x << " " << iter->y << endl;
    }
    return 0;
}