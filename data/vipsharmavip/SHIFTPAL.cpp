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
const int N = 2*200005; // 10^5
ll onePrime = 101LL;
ll MOD = 1000000007LL;
ll hashPre[N];
ll hashSuf[N];
ll power_[N];
string str;
int len;
//.............data...................

//.............functions...................
void pre(){
    power_[0] = 1LL;
    for(int i = 1; i < N; i++){
        power_[i] = (power_[i-1] * onePrime) % MOD;
    }
}
void prefixCalc(){
    hashPre[1] = str[0];
    for(int i = 2; i <= len; i++){
        hashPre[i] = (hashPre[i-1] + ((str[i-1] * power_[i-1]) % MOD)) % MOD;
    }
}
void suffixCalc(){
    hashSuf[1] = str[len-1];
    for(int i = len-2, j = 2; i >= 0 && j <= len; i--, j++){
        hashSuf[j] = (hashSuf[j-1] + ((str[i] * power_[j-1]) % MOD)) % MOD;
    }
}
ll modPow(ll base, ll exponent){
    if (exponent == 0LL)
        return 1LL;
    if (exponent == 1LL)
        return base;
    ll temp = modPow(base, exponent/2LL);
    if (exponent%2LL ==0LL)
        return (temp%MOD * temp%MOD) % MOD;
    else
        return ((( temp%MOD * temp%MOD)%MOD) * base%MOD) % MOD;
}
ll findMMI(ll n){
    return modPow(n, MOD-2LL);
}
//.............functions...................

//.............main...................
int main(){
    boost;
    pre();
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        str = str + str;
        len = str.length();
        prefixCalc();
        suffixCalc();
        int ans = 0;
        for(int i = 0; i < len/2; i++){
            int L = i;
            int R = i + len/2 -1;
            ll hash_LR = (((hashPre[R+1] - hashPre[L] + MOD) % MOD) * findMMI(power_[L])%MOD) % MOD;
            ll reverse_hash_LR = (((hashSuf[len-L] - hashSuf[len-R-1] + MOD)%MOD) * findMMI(power_[len-R-1])%MOD) % MOD;
            if(hash_LR == reverse_hash_LR){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}