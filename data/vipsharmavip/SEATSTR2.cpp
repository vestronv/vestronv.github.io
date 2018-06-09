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
const int N = 100050; // 10^5
const ll MOD = 1000000007L;
string str;
ll freq[26];
ll factoz[N], invfactoz[N];
//.............data...................

//.............functions...................
ll solve(){
    ll ans = 0L;
    // 0 swap
    ans += 1L;
    // 1 swap
    for(int i = 0; i < 26; i++){
        if(!freq[i])continue;
        for(int j = 0; j < i; j++){
            if(!freq[j])continue;
            ans += ( (ll)freq[i] * (ll)freq[j]) % MOD;
            ans %= MOD;
        }
    }
    //cout << "ans=" << ans << endl;
    // abc , ab cd , ab ac , ab ab
    // 2 swap , ab cd
    for(int i = 0; i < 26; i++){
        if(!freq[i])continue;
        for(int j = 0; j < i; j++){
            if(!freq[j])continue;
            for(int k = 0; k < j; k++){
                if(!freq[k])continue;
                for(int l = 0; l < k; l++){
                    if(!freq[l])continue;
                    ans += ( ( ( ( ( ( ((ll)freq[i] * (ll)freq[j]) % MOD) * (ll)freq[k]) % MOD ) * freq[l] ) % MOD ) * 3L)  % MOD;
                    ans %= MOD;
                }
            }
        }
    }
    //cout << "ans=" << ans << endl;
    // 2 swap , ab ac
    for(int i = 0; i < 26; i++){
        if(!freq[i])continue;
        for(int j = 0; j < 26; j++){
            if(!freq[j])continue;
            if(i == j)continue;
            for(int k = 0; k < j; k++){
                if(!freq[k])continue;
                if(i == k)continue;
                ans += (  ( ( ( ( ((ll)freq[i] * (ll)(freq[i]-1)) % MOD) * (ll)freq[j]) % MOD ) * freq[k] ) % MOD ) ;
                ans %= MOD;
            }
        }
    }
    //cout << "ans=" << ans << endl;
    // 2 swap , ab ab
    for(int i = 0; i < 26; i++){
        if(!freq[i])continue;
        for(int j = 0; j < i; j++){
            if(!freq[j])continue;
            ans += (((((((freq[i] * (freq[i]-1L)) % MOD ) /2) %MOD) * ((((freq[j] * (freq[j]-1L)) % MOD ) /2)%MOD) ) % MOD ) ) ;
            //ans += ( ( ( ( ( ( (((ll)freq[i] * (ll)(freq[i]-1))/2) % MOD) * (((ll)(freq[j]) % MOD ) * (freq[j]-1))) ) % MOD )) / 2L)  % MOD;
            ans %= MOD;
        }
    }
    //cout << "ans=" << ans << endl;
    // 2 swap , abc
    for(int i = 0; i < 26; i++){
        if(!freq[i])continue;
        for(int j = 0; j < i; j++){
            if(!freq[j])continue;
            for(int k = 0; k < j; k++){
                if(!freq[k])continue;
                ans += ( ( ( ( ( ( ((ll)freq[i] * (ll)freq[j]) % MOD) * (ll)freq[k]) % MOD ) * 2L ) % MOD ) );
                ans %= MOD;
            }
        }
    }
    //cout << "ans=" << ans << endl;
    //////////// DONE //////////////
    ll p =0;
    p = factoz[str.length()];
    for(int i = 0; i < 26; i++){
        p = (p * (ll)invfactoz[freq[i]]) % MOD;
    }
    //cout << "ans = " << ans << endl;
    //cout << "p   = " << p   << endl;
    ans = (((p * p) % MOD) - ((p * ans) % MOD)) % MOD;
    ans = (ans + MOD) % MOD;
    return ans;
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
void clean_(){
    for(int i = 0; i < 26; i++){
        freq[i] = 0L;
    }
}
void setup(){
    for(int i = 0; i < str.length(); i++){
        freq[str[i]-'a']++;
    }
}
//.............functions...................

//.............main...................
int main(){
    boost;
    pre();
    // for(int i = 1000; i < 1005; i++){
    //     cout << factoz[i] << "  --  ";
    // }
    // cout << endl;
    // for(int i = 1000; i < 1005; i++){
    //     cout << invfactoz[i] << "  --  ";
    // }
    // cout << endl;
    int t;
    cin >> t;
    while(t--){
        clean_();
        cin >> str;
        setup();
        cout << solve() << endl;
    }
    return 0;
}
