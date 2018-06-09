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
const int N = 1000005; // 10^5
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
    boost;
    ll n, q;
    map<ll, ll>present;
    cin >> n >> q;
    vector<pair<ll,ll> >v;
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        v.PB({val, i+1});
    }
    sort(v.begin(), v.end());
    set<ll>idxs;
    set<ll>::iterator sit;
    idxs.insert(0);
    idxs.insert(n+1);
    vector<ll,ll>freq;
    for(int i = v.size()-1; i >= 0; i--){
        ll val = v[i].first;
        ll idx = v[i].second;
        sit = idxs.lower_bound(idx);
        ll hi = *sit;
        sit--;
        ll lo = *sit;
        //cout << lo << " " << idx << " " << hi << endl;
        freq.PB({val,  (ll)((ll)(hi-idx) * (ll)(idx-lo))});
        //present[val] += (ll)((ll)(hi-idx) * (ll)(idx-lo));
        idxs.insert(idx);
    }
    v.clear();
    v.PB({0,0});
    vector<pair<ll,ll> >::iterator mit;
    vector<pair<ll,ll> >ufreq;
    for(int i = 0; i < freq.size(); ){
        ll prev = freq[i].first;
        ll yo = 0LL;
        for(; i < freq.size(); i++){
            if(freq[i].first != prev)break;
            yo += freq[i].second;
        }
        ufreq.PB({prev,yo});
    }
    map<char,char>rev;
    rev['D'] = 'C';
    rev['C'] = 'D';
    while(q--){
        string type, player;
        ll k;
        cin >> type >> k >> player;
        
        if(type[0] == '='){
            ll games = 0;
            ll idx = upper_bound(ufreq.begin(), ufreq.end(),k) - ufreq.begin();
            idx--;
            if(ufreq[idx])
            if(games&1){
                cout << player;
            }
            else cout << rev[player[0]];
        }
        else if(type[0] == '<'){
            ll games = 0;
            mit = freq.lower_bound(k); // smallest greater than = k
            mit--;
            games = (*mit).second;
            if(games&1){
                cout << player;
            }
            else cout << rev[player[0]];
        }
        else if(type[0] == '>'){
            ll games = 0;
            mit = freq.end();
            mit--;
            ll tot = (*mit).second;
            mit = freq.lower_bound(k);
            if(!present[k])mit--;
            games = tot - ((*mit).second);
            if(games&1){
                cout << player;
            }
            else cout << rev[player[0]];
        }
    }
    cout << endl;
    return 0;
}