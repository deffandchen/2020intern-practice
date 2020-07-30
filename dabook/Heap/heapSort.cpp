#include<iostream>
using namespace std;

#define child_left(i) (2 * (i) + 1)

void buildHeap(int a[],int i,int n)
{
    int child,tmp;
    for(tmp = a[i];child_left(i)<n;i = child)
    {
        child = child_left(i);
        if(child < n-1 && (a[child] < a[child+1])) 
            child++;
        if(a[i] < a[child])
            swap(a[i],a[child]);
        else
            break;
    }
}

int main()
{
    int N = 9;
    int a[9] = {1,3,5,2,7,5,1,3,4};
    for(int i=N/2;i>=0;i--)
        buildHeap(a,i,N);
    for(int i=0;i<N;i++)
        cout << a[i] << ' ';
    cout << endl;
    for(int i=N-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        buildHeap(a,0,i);
    }
    for(int i=0;i<N;i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
