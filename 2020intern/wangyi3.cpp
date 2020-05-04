/*************************************************************** 
    > File Name        : c.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2020/4/7 19:56:16
 ***************************************************************/

#include <bits/stdc++.h>
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>
#define  dbg(x)     cout << #x << " = " << (x) << endl
#define  mes(a, b)  memset(a, b, sizeof a)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int    maxn = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;

int n, m;
int T, cas, tol = 0;

char s[maxn];

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		scanf("%s", s+1);
		int ans = 0, cnt = 0;
		for(int i=1; i<=n; i++) {
			ans = ans*10+s[i]-'0';
			ans %= m;
			if(ans == 0)	cnt++;
		}
		if(ans != 0) {
			printf("0\n");
		} else {
			printf("%lld\n", fpow(2, cnt-1));
		}
	}
	return 0;
}

