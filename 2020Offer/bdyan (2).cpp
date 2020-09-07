#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int MOD=1000000007;
int v[8][8][100005]={0};
void help(int& res,int a,int b,int n,int m){
    if(n==0) res=(res+1)%MOD;
    else if(n<0) return;
    else{
        for(int i=1;i<=m;i++){
            if(i!=a&&i!=b){
                if(v[b][i][n-i]==0) {
                    int mm=0;
                    help(mm,b,i,n-i,m);
                    v[b][i][n-i]=mm;
                    res=(res+mm)%MOD;
                }
                else{
                    res=(res+v[b][i][n-i])%MOD;
                }
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int res=0;
    help(res,0,0,n,m);
    cout<<res<<endl;
    return 0;
}