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
typedef unsigned long long ll;
//.............template...................

//.............data...................
const int N = 100005; // 10^5
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
    	ll n, m;
    	int k;
    	long double ans = 0.0;
    	long double tot = 0.0;
    	cin >> n >> m >> k;
    	tot = ((n) * (m));
    	for(int i = 0; i < k; i++){
    		ll pos;
    		cin >> pos;
    		ll R = pos/m + 1 - ((ll)pos%(ll)m==0);
    		ll C = (ll)pos%(ll)m;
    		if(C == 0LL)C = m;
    		//cout << R << " " << C;
    		ans += (R*(n-R+1.0)) * (C*(m-C+1.0));
    	}
    	ans /= ((long double)n+1.0);
    	ans /= ((long double)m+1.0);
    	ans /= (long double)n;
    	ans /= (long double)m;
    	ans *= 4.0;
    	cout << setprecision(16) << (long double)((long double)ans) << endl;
    }
    return 0;
}