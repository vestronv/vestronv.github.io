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
		int n;
		cin >> n;
		int val;
		cin >> val;
		int gcd = val;
		for(int i = 1; i < n; i++){
			cin >> val;
			gcd = __gcd(gcd, val);
		}
		if(gcd != 1)cout << -1 << endl;
		else cout << n << endl;
	}
	return 0;
	}
