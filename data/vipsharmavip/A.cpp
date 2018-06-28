// copy From Here
// need for speed...
#include <bits/stdc++.h>
using namespace std;
// bad times...

//.............template....................
#define vimal
#ifdef vimal
#endif
#define boost ios::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define MP make_pair
typedef long long ll;
//.............template....................

//.............data........................
const int N = 100005; // 10^5
vector<vector<ll> >dp;
//.............data........................

//.............functions...................
ll fun(vector<ll> &v,ll i,ll s,ll n){
    if(i==n&&!s)
    return 1LL;
    if(i==n||s<0LL)
    return 0LL;
    if(dp[i][s]!=-1LL)
    return dp[i][s];
    dp[i][s]=fun(v,i+1LL,s-v[i],n)+fun(v,i+1LL,s,n);
    return dp[i][s];
}
//.............functions...................

//.............main........................
int main(){
    boost;
    ll n;
    ll s = 0;
    cin >> n;
    string str;
    vector<ll>arr;
    for(ll i = 0; i < n; i++){
    	string str;
    	cin >> str;
    	ll val = 0;
    	for(ll j = 0; j < (ll)str.length(); j++){
    		if(str[j] == ')')val--;
    		else val++;
    	}
    	arr.PB(val);
    	//cout << val << " ";
    }
    // subset sum problem...
    dp.resize(n);
    for(int i=0;i<n;i++){
    	dp[i].resize(s+1,-1LL);
    }
    cout << fun(arr, 0LL, s, n);
    return 0;
}