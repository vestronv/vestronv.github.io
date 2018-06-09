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
		int n, zero = 0;
		cin >> n;
		ll sum = 0L;
		for(int i = 0; i < n; i++){
			int val;
			cin >> val;
			sum += val;
			if(val == 0)zero++;
		}
		sum -= 100;
		bool yes = true;
		if(sum < 0)yes = false;
		else{
			n -= zero;
			if(sum >= n)yes = false;
		}
		if(yes)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
	}
