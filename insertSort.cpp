#include<iostream>

using namespace std;

void insertSort(int a[],int N){
    for(int i=1;i<N;i++){
        int tmp = a[i];
        int j;
        for(j=i;j>0 && a[j-1]>tmp;j--){    
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}
#define lchild(i) (2*i+1)
void heapSort(int a[],int i,int N){
    int tmp,child;
    for(tmp=a[i];lchild(i)<N;i=child){
        child = lchild(i);
        if(child<N-1 && a[child]<a[child+1])
            child++;
        if(tmp<a[child])
            a[i] = a[child];
    }
    a[i] = tmp;
}

int main()
{
    const int N = 10;
    int a[N] = {1,0,2,5,9,7,4,2,6,1};
    /*
    insertSort(a,10);
    for(int i=0;i<10;i++)
     cout << a[i] <<' ' << endl;
    */
   for(int i=N/2;i>=0;i--)
     heapSort(a,i,N);
    return 0;
}