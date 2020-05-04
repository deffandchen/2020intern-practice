#include<iostream>
using namespace std;

int parition(int a[],int left,int right)
{
    int mid = (right + left)/2;
    if(a[left] < a[mid])
        swap(a[left],a[mid]);
    if(a[right] > a[left])
        swap(a[right],a[left]);
    if(a[right] < a[mid])
        swap(a[right],a[mid]);
    int i = left-1;
    for(int j = left;j<right;j++)
        if(a[j] > a[right])
            swap(a[++i],a[j]);
    
    swap(a[++i],a[right]);
    return i;
}
int topk(int a[],int left,int right,int k)
{
    if(left == right)
        return a[left];
    int mid = parition(a,left,right);
    int cur = mid - left + 1;
    if(cur == k)
        return a[k-1];
    else if(k<cur)
        return topk(a,left,mid-1,k);
    else
    {
        return topk(a,mid+1,right,k-cur);
    }
}
int N,i=0,in;
int main()
{   
    cin >> N;
    int que1[10]; 
    int que2[10]; 
    while(i<N)
    {
        cin >> in;
        que1[i] = in;
        i++;
    }
    i=0;
    while(i<N)
    {
        cin >> in;
        que2[i] = in;
        i++;
    }
    int a =0,b=0;
    for(int j=0;j<3;j++)
    {
        a += topk(que1+j,0,N-j-1,3);
        b += topk(que2+j,0,N-j-1,3);
    }
    if(a>=b) cout << a << endl;
    else cout << b << endl;

    return 0;
}