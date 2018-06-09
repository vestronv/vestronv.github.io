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
		int n, m;
		cin >> n >> m;
		int minIdx = INT_MAX, maxIdx = INT_MIN;
		for(int i = 0; i < m; i++){
			int idx;
			cin >> idx;
			minIdx = min(minIdx, idx);
			maxIdx = max(maxIdx, idx);
		}
		for(int i = 0; i < n; i++){
			cout << max(abs(i - maxIdx), abs(i - minIdx)) << " ";
		}
		cout << endl;
	}
	return 0;
	}
