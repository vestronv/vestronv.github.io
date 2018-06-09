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
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
	boost;
	int n;
	ll mod;
	cin >> n >> mod;
	ll p[n+1];
	ll op[n+1];
	ll maxi = -1L;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		op[i] = p[i];
		p[i] %= mod;
		maxi = max(maxi, p[i]);
	}
	ll modfac[maxi+1];
	modfac[1] = 1L;
	for(int i = 2; i <= maxi; i++){
		modfac[i] = ((ll)i*(modfac[i-1]))%((ll)mod);
	}
	ll ans = 0L;
	ll pre[maxi+2];
	pre[0] = 0L;
	for(int i = 1; i <= maxi; i++){
		int yo = i;
		if(i >= mod)yo = 0L;
		pre[i] = pre[i-1] + (((ll)yo * modfac[i])%mod );
		pre[i] %= mod;
		if(pre[i] < 0)pre[i] += mod;
		cout << pre[i] << " ";
	}
	for(int i = 0; i < n; i++){
		ans += (pre[p[i]] + ((ll)(op[i])*((((ll)op[i])*((ll)op[i]+1))/2L)))%(ll)mod;
		ans %= (ll)mod;
		if(ans < 0)ans += (ll)mod;
	}
	cout << ans << endl;
	return 0;
	}
