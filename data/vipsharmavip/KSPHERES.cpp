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
const int mod = 1000000007;
int one[N], two[N];
ll dp[1005][1005]; // k-seq, radius [r]
//.............data........................

//.............functions...................

//.............functions...................

//.............main........................
int main(){
    boost;
    int n, m, c, val;
    cin >> n >> m >> c;
    for(int i = 0 ; i < n; i++){
    	cin >> val;
    	one[val]++;
    }
    for(int i = 0 ; i < m; i++){
    	cin >> val;
    	two[val]++;
    }
    vector<ll>radii;
    ll rad[1005];
    for(int i = 1; i < 1005; i++){
    	ll nums = (ll)one[i] * (ll)two[i];
    	if(nums > 0LL){
    		radii.PB(nums);
    	}
    	rad[i] = nums;
    	rad[i] %= mod;
    }
    for(int i = 0; i <= 1004; i++){
    	dp[0][i] = rad[i];
    	if(i>0)dp[0][i] += dp[0][i-1];
    	dp[0][i] %= mod;
    }
    for(int i = 1; i < radii.size(); i++){
    	ll sm = 0;
    	//for(int j = i+1; j < radii.size(); j++){
    	for(int j = 1; j < 1005; j++){
    		//sm += rad[j-1];
    		if(j>i)dp[i][j] =  ( ( (dp[i-1][j-1])*rad[j])%mod + dp[i][j-1])%mod;
    	}
    }
    for(int i = 0; i <= 10; i++){
    	for(int j = 0; j <= 10; j++){
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    for(int i = 1; i <= c; i++){
    	cout << dp[i][1004] << " ";
    }
    return 0;
}