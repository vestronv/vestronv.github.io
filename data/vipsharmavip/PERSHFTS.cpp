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
#define LSOne(s) (s & (-s))
typedef long long ll;
//.............template....................

//.............data........................
const int N = 100005; // 10^5
const int mod = 1000000007;
int P[2*N], Q[N];
int mark[N];
int fact[N], ft[N];
int n, k;
//.............data........................

//.............functions...................
ll invMod( ll exp ){
    ll base = 2;
    ll res = 1 ;
    while(exp){
        if(exp&1)
        res = (res * base )%mod;
        exp = exp >> 1;
        base = (base * base )%mod;
    }
    return res;
}
void FACT(){
    fact[0]=1;
    for(int i = 1 ; i <= 100000 ; ++i )
        fact[i] = ( i * fact[i-1])%mod;
}
ll sum(int b){
    ll sum = 0LL;
    for(; b; b -= LSOne(b))sum += (ll)ft[b];
    return sum;
}
void update(int k, int v, int n, int q){
    for (; k <= n; k += LSOne(k)) ft[k] += v;
}
ll query(int a, int b, int q){
    return sum(b) - (a == 1 ? 0 : sum(a-1));
}
int getRank(int q){
    int rank = 1;
    for(int i = 0; i < n; i++){
        if(q)rank += ( (ll)((ll)Q[i]-1-query(1,Q[i]-1,q)) * (ll)fact[n-i-1] ) % mod;
        else rank += ( (ll)((ll)P[i]-1-query(1,P[i]-1,q)) * (ll)fact[n-i-1] ) % mod;
        rank %= mod;
        update(i,1,n,q);
    }
}
int getParity(int q){
    int ans = 0;
    int done[N];
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++){
        if(!done[i]){
            int cnt = 0;
            int v = i;
            while(!done[v]){
                done[v] = 1;
                v = q*(Q[v]-1) + (1-q)*(P[v]-1);
                cnt++;
                //cout << v ;
            }
            if(cnt%2 == 0)ans++;
        }
    }
    return ans&1;
}
//.............functions...................

//.............main........................
int main(){
    boost;
    FACT();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> P[i];
        }
        for(int i = n; i < 2*n; i++)P[i] = P[i-n];
        for(int i = 0; i < n; i++){
            cin >> Q[i];
        }
        if(k == n){
            int j, yo = 0;
            for(int i = 0; i < 2*n; i++){
                if(P[i] == Q[0]){j=i;break;}
            }
            for(int i = j; i < j+n; i++){
                if(P[i] != Q[i-j]){
                    break;
                }
                else yo++;
            }
            if(yo == n){
                cout << Q[0] << endl;
            }
            else cout << "-1\n";
        }
        else if(k%2){
            memset(ft, 0, sizeof(ft));
            int parity1 = getParity(0);//P
            int parity2 = getParity(1);//Q
            //cout << parity2 << " " << parity1 << endl;
            if(parity2 == parity1){
                int rank = getRank(1);
                if(Q[n-2]<Q[n-1]){//odd perm
                    rank++;
                }
                int ans = invMod(mod-2);
                cout << ans << endl;
            }
            else cout << "-1\n";
        }
        else{//even
            memset(ft, 0, sizeof(ft));
            int rank = getRank(1);
            int ans = invMod(mod-2);
            cout << ans << endl;
        }
    }
    return 0;
}