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
const int N = 1000070; // 10^5
const ll MOD = 1000003L;
int n, l, r;
ll factoz[N], invfactoz[N];
//.............data...................

//.............functions...................
ll nCr2(ll N, ll R) {
    if (R > N)
        return 0L;
    return ((factoz[N] * 1L * invfactoz[R]) % MOD * 1L * invfactoz[N - R]) % MOD;
}
ll nCr(ll N, ll R){
    ll C[R+1];
    memset(C, 0L, sizeof C);
    C[0] = 1L;
    for(int i = 1; i <= N; i++){
        for(int j = min(i, (int)R); j > 0; j--){
            C[j] = (C[j] + C[j-1]) % MOD;
        }
    }
    return C[R];
}
ll lucas(ll N, ll K){
    if(N <= 1L)return 1L;
    return (lucas(N/MOD, K/MOD) * nCr2(N % MOD, K % MOD) ) % MOD;
}
ll solve(){
    ll N = n + r - l + 1;
    ll K = n;
    return lucas(N, K);
}
void pre(){
    for(int i = 0; i < N; i++){
        if(i < 2)invfactoz[i] = 1L;
        else invfactoz[i] = ((MOD - (MOD/(ll)i)) * invfactoz[MOD % i] ) % MOD;
    }
    for(int i = 0; i < N; i++){
        if(i < 2)factoz[i] = 1L;
        else{
            factoz[i] = (factoz[i-1] * (ll)i) % MOD;
            invfactoz[i] = (invfactoz[i-1] * invfactoz[i] ) % MOD;
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
        cin >> n >> l >> r;
        // C(n + r - l + 1, n) - 1
        cout << (solve()-1 + MOD) % MOD << endl;
    }
    return 0;
    }
