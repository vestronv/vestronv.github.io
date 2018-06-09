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
int arr[N];
int BAD[N];
//.............data...................

//.............functions...................
vector<int> findDivisors(int n){
	vector<int> v;
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			if(n/i == i)
				v.PB(i);
			else {
				v.PB(i);
				v.PB(n/i);
			}
		}
	}
	return v;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    for(int i = 0; i < N; i++)BAD[i] = -1;
    int n, k;
    cin >> n >> k;
    ll ans = 0LL;
    ans = n*(n+1LL) >> 1;
    int ii = 0, jj = 1;
    #define adddddd(iii, jjj) do{ans += ii*(jj-(jjj)); ii = iii; jj = (jjj);}while(0)
    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }
    int latestK = 0;
    vector<pair<int,int> >bhag_bc;
    for(int i = 1; i <= n; i++){
    	if(arr[i] == k){
    		latestK = i;
    	}
    	else if(arr[i] > k){
    		int idx = max(BAD[arr[i]], latestK);
    		if(idx > ii){
    			bhag_bc.PB({idx,i});
    			ii = idx; jj = i;
    			//adddddd(idx, i); // i,j pairs
    		}
    		arr[i] -= k;
    		for(int v = 1; v*v <= arr[i]; v++){
    			if(arr[i]%v == 0)BAD[v] = BAD[arr[i]/v] = i;
    		}
    	}
    }
    bhag_bc.PB({n, n+1});
    //adddddd(n,n+1);
    for(int i = 0; i < bhag_bc.size()-1; i++){
    	ans -= (bhag_bc[i].first*(bhag_bc[i+1].second - bhag_bc[i].second));
    }
    cout << ans << endl;
    return 0;
}