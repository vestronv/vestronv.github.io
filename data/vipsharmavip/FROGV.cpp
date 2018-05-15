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
const int N = 100005; // 10^3
pair<int, int> xpos[N];
ll max_jump[N];
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
	boost;
	int n, k, q;
	cin >> n >> k >> q;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		xpos[i] = {val, i};
	}
	sort(xpos, xpos + n);
	max_jump[xpos[n-1].second] = (ll)xpos[n-1].first + (ll)k;
	for(int i = n-2; i >=0; i--){
		if(xpos[i+1].first - xpos[i].first <= k){
			max_jump[xpos[i].second] = max_jump[xpos[i+1].second];
		}
		else{
			max_jump[xpos[i].second] = (ll)xpos[i].first + (ll)k;
		}
	}
	while(q--){
		int frog1x, frog2x;
		cin >> frog1x >> frog2x;
		frog1x--;
		frog2x--;
		if(max_jump[frog1x] == max_jump[frog2x])cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
	}
