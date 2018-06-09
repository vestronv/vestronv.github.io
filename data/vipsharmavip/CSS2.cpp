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
	int n, q;
	cin >> n >> q;
	map<pair<int, int>, pair<int,int> >mp;// {id, attr}, {val, priority}
	for(int i = 0; i < n; i++){
		int id, attr, val, priority;
		cin >> id >> attr >> val >> priority;
		int prio = mp[{id, attr}].second;
		if(prio <= priority){
			mp[{id, attr}] = {val, priority};
		}
	}
	while(q--){
		int id, attr;
		cin >> id >> attr;
		cout << mp[{id, attr}].first << "\n";
	}
	return 0;
	}
