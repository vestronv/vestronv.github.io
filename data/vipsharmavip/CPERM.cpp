// copy From Here
// need for speed...
#include <bits/stdc++.h>
using namespace std;
// bad times...

//.............template...................
#define vimal
#ifdef vimal

#endif
#define boost ios::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define MP make_pair
typedef long long ll;
//.............template...................

//.............data...................
const int N = 100005; // 10^5
const int MOD = 1e9+7;
//.............data...................

//.............functions...................
ll power(int num, int exp){
	ll res = 1L;
	ll p = (ll)num;
	while(exp){
		if(exp&1)res = (res * p) % MOD;
		p = ((ll)p * (ll)p) % MOD;
		exp >>= 1;
	}
	return res;
}
//.............functions...................

//.............main...................
int main(){
	boost;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n <= 1)cout << 0 << endl;
		else cout << (MOD + power(2, n-1) - 2)%MOD << endl;
	}
	return 0;
	}
