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
bool comp(pair<int,int>& a, pair<int,int>& b){
	return a.first < b.first;
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
		std::vector<pair<int,int> > kingdom;
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			kingdom.PB({x, y});
		}
		sort(kingdom.begin(), kingdom.end(), comp);
		std::vector<pair<int,int> > bomb;
		pair<int,int>cur;
		cur.first = kingdom[0].first;
		cur.second = kingdom[0].second;
		int ans = 1;
		for(int i = 1; i < n; i++){
			int f = kingdom[i].first;
			int s = kingdom[i].second;
			if(f > cur.second){
				ans++;
				cur.first = kingdom[i].first;
				cur.second = kingdom[i].second;
			}
			else{
				cur.second = min(cur.second, kingdom[i].second);
			}
		}
		cout << ans << "\n";
	}
	return 0;
	}
