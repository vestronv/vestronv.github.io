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
const int N = 2005; // 10^5
int n;
vector<pair<int,int> >points;
map<pair<int, int>, int>mp;
//.............data...................
 
//.............functions...................
//.............functions...................
 
//.............main...................
int main(){
	boost;
	cin >> n;
	bool easy = false;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		points.PB({x, y});
		mp[{x, y}]++;
		if(mp[{x, y}] >= 4)easy = true;
	}
	if(n < 3){
		cout << 4 - n << endl;
		return 0;
	}
	if(easy){
		cout << 0 << endl;
		return 0;
	}
	int min_to_find = 2;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int x1, y1, x2, y2;
			x1 = points[i].first;
			y1 = points[i].second;
			x2 = points[j].first;
			y2 = points[j].second;
			int x3, y3, x4, y4;
			x3 = x1 - (y2 - y1);
			y3 = y1 + (x2 - x1);
			x4 = x2 - (y2 - y1);
			y4 = y2 + (x2 - x1);
			int to_find = 2;
			if(mp.find({x3, y3}) != mp.end()){
				to_find--;
				if(mp.find({x4, y4}) != mp.end()){
					to_find--;
				}
			}
			else{
				if(mp.find({x4, y4}) != mp.end()){
					min_to_find = min(1, min_to_find);
				}
			}
			min_to_find = min(min_to_find, to_find);
			if(min_to_find <= 0)break;
		}
		if(min_to_find <= 0)break;
	}
	cout << min_to_find << endl;
	return 0;
	}