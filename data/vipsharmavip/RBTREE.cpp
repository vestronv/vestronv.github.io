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
int findLevel(int num){
	int level = 1;
	while(num > 1){
		level++;
		num /= 2;
	}
	return level;
}
int find_lca(int a, int b){
	if(a == 1 || b == 1)return 1;
	while(a != b){
		if(a < b)b/=2;
		else a/=2;
	}
	return a;
}
//.............functions...................

//.............main...................
int main(){
	boost;
	int q;
	cin >> q;
	bool madness = false;
	while(q--){
		string query;
		cin >> query;
		if(query[1] == 'i'){
			madness = !madness;
			continue;
		}
		int from, to;
		cin >> from >> to;
		int fromLevel = findLevel(from);
		int toLevel = findLevel(to);
		int lca = find_lca(from, to);
		int lcaLevel = findLevel(lca);
		//cout << fromLevel << " " << toLevel << " " << lca << " " << lcaLevel << endl;
		if(query[1] == 'b'){
			if(!madness){
				int b = (fromLevel+1)/2;
				b += (toLevel+1)/2;
				b -= 2*((lcaLevel+1)/2);
				if((lcaLevel&1))b++;
				b = max(b, 0);
				cout << b << endl;
			}
			else{
				int b = (fromLevel)/2;
				b += (toLevel)/2;
				b -= 2*((lcaLevel)/2);
				if(!(lcaLevel&1))b++;
				b = max(b, 0);
				cout << b << endl;
			}
		}
		else{
			if(!madness){
				int b = (fromLevel)/2;
				b += (toLevel)/2;
				b -= 2*((lcaLevel)/2);
				if(!(lcaLevel&1))b++;
				b = max(b, 0);
				cout << b << endl;
			}
			else{
				int b = (fromLevel+1)/2;
				b += (toLevel+1)/2;
				b -= 2*((lcaLevel+1)/2);
				if(lcaLevel&1)b++;
				b = max(b, 0);
				cout << b << endl;
			}
		}
	}
	return 0;
	}
