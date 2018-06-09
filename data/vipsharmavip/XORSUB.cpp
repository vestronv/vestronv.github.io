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
		int arr[n];
		for(int i = 0; i < n; i++)cin >> arr[i];
		int ans = k;
		set<int>st1;
		set<int>st2;
		st2.insert(k);
		for(int i = 0; i < n; i++){
			for(set<int>::iterator sit = st2.begin(); sit != st2.end(); sit++){
				int now = (*sit) ^ arr[i];
				ans = max(ans, now);
				st2.insert(now);
			}
		}
		cout << ans << endl;
	}
	return 0;
	}
