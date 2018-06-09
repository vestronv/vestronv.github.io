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
    map<string,string>thanos;
    thanos["purple"] = "Power";
    thanos["green"] = "Time";
    thanos["blue"] = "Space";
    thanos["orange"] = "Soul";
    thanos["red"] = "Reality";
    thanos["yellow"] = "Mind";
    int n;
    cin >> n;
    map<string,int>present;
    int cnt = 0;
    for(int i = 0; i < n; i++){
    	string clr;
    	cin >> clr;
    	if(!present[clr])cnt++;
    	present[clr]=1;
    }
    cout << 6 - cnt << endl;
    for(map<string,string>::iterator mit = thanos.begin(); mit != thanos.end(); mit++){
    	if(present[(*mit).first])continue;
    	else cout << (*mit).second << endl;
    }
    return 0;
}