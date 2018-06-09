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
const int MOD = 1000000007;
int factoz[N];
int invfactoz[N];
//.............data...................

//.............functions...................
int nCr2(int N, int R) {
    if (R > N)
        return 0;
    return (((ll)factoz[N] * 1L * invfactoz[R]) % MOD * 1L * invfactoz[N - R]) % MOD;
}
int lucas(int N, int R){
	if(N <= 1)return 1;
	return ((ll)lucas(N/MOD, R/MOD)%MOD * (ll)nCr2(N%MOD, R%MOD)%MOD)%MOD;
}
void pre(){
    for(int i = 0; i < N; i++){
        if(i < 2)invfactoz[i] = 1;
        else invfactoz[i] = ((MOD - (MOD/(ll)i)) * (ll)invfactoz[MOD % i] ) % MOD;
    }
    for(int i = 0; i < N; i++){
        if(i < 2)factoz[i] = 1;
        else{
            factoz[i] = ((ll)factoz[i-1] * (ll)i) % MOD;
            invfactoz[i] = ((ll)invfactoz[i-1] * (ll)invfactoz[i] ) % MOD;
        }
    }
}
//.............functions...................

//.............main...................
int main(){
    boost;
    pre();
    int t;
    cin >> t;
    while(t--){
    	int n, m;
    	cin >> n >> m;
    	int N, R;
    	R = m-1;
    	N = n - (2*m) + m - 1;
    	if(N == R){
    		cout << 1 << endl;
    	}
    	else if(N < R){
    		cout << 0 << endl;
    	}
    	else if(N == R+1){
    		cout << N << endl;
    	}
    	else{
    		cout << (lucas(N, R) + MOD) % MOD;
    	}
    }
    return 0;
}