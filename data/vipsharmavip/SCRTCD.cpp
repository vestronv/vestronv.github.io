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
    int t;
    cin >> t;
    while(t--){
        string src, target;
        int del, ins, rep;
        cin >> src >> target >> del >> ins >> rep;
        int freqsrc[26] = {0}, freqtarget[26] = {0};
        for(int i = 0; i < src.length(); i++){
            freqsrc[src[i]-'a']++;
        }
        for(int i = 0; i < target.length(); i++){
            freqtarget[target[i]-'a']++;
        }
        int want = 0, extra = 0, matches = 0;
        for(int  i = 0; i < 26; i++){
            if(freqsrc[i] - freqtarget[i] < 0){
                want += freqtarget[i] - freqsrc[i];
            }
            else{
                extra += freqsrc[i] - freqtarget[i];
            }
            if(freqtarget[i] == freqsrc[i])matches++;
        }
        if(!extra && !want){
            cout << 0 << endl;
        }
        else if(!extra && want){
            cout << ins * want << endl;
        }
        else if(extra && !want){
            cout << del * extra << endl;
        }
        else if(extra && want){
            int ans = 0;
            ans = (extra * del) + (want * ins);
            if(rep < del + ins){
                ans -= min(want, extra) * (-rep + (del + ins));
            }
            cout << ans << endl;
        }
    }
    return 0;
}