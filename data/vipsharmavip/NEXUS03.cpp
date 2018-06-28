// copy From Here
// need for speed...
#include <bits/stdc++.h>
using namespace std;
// bad times...

//.............template....................
#define vimal
#ifdef vimal
#endif
#define boost ios::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define MP make_pair
typedef long long ll;
//.............template....................

//.............data........................
const int N = 100005; // 10^5
//.............data........................

//.............functions...................

//.............functions...................

//.............main........................
int main(){
    boost;
    ll n, k;
    cin >> n >> k;
    ll arr[n+2];
    arr[0] = 0;
    for(ll i = 1; i <= n; i++){
    	cin >> arr[i];
    	arr[i] += arr[i-1];
    }
    ll lim = 0;
    for(ll i = 1; i+k-1 <= n; i++){
    	arr[i-1] = arr[i+k-1] - arr[i-1];
    	if(lim > 0)arr[i-1] += arr[i-2];
    	lim++;
    }
    // for(ll i = 0; i < lim; i++){
    // 	cout << arr[i] << " ";
    // }
    // cout << endl << endl;
    ll q;
    cin >> q;
    while(q--){
    	ll s, x, flag = 0;
    	cin >> s >> x;
    	for(ll i = 0; i < lim; i++){
    		ll temp = arr[i+s-1];
    		if(i > 0)temp -= arr[i-1];
    		if(temp == x){
    			flag = 1;
    			break;
    		}
    	}
    	if(flag){
    		cout << "YES\n";
    	}
    	else cout << "NO\n";
    }
    return 0;
}