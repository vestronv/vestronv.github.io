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
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int pickTime[n];
		for(int i = 0; i < n; i++){
			cin >> pickTime[i];
		}
		ll ans = 0L;
		for(int i = 0; i < n; i++){
			int profit;
			cin >> profit;
			ans = max(ans , (ll)(k/pickTime[i]) * (ll)profit);
		}
		cout << ans << endl;
	}
	return 0;
	}
