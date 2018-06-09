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
int n, m, k, s;
int citygood[N];
vector<vector<int> >g;
//.............data...................

//.............functions...................
int solve(int node){
    int lefts = s-1;
    queue<pair<int,int> >q; // node, len
    q.push({node,0});
    vector<bool> visi(n+1,false);
    vector<bool> done(k+1,false);
    int ans = 0;
    visi[node]=true;
    done[citygood[node]]=true;
    while(!q.empty()){
        int nnode = q.front().first;
        int len = q.front().second;
        q.pop();
        visi[nnode]=true;
        if(!done[citygood[nnode]]){
            ans += len;
            done[citygood[nnode]]=true;
            lefts--;
        }
        if(lefts <= 0)break;
        for(int i = 0; i < g[nnode].size(); i++){
            if(!visi[g[nnode][i]]){
                q.push({ g[nnode][i] , len+1 });
            }
        }
    }
    return ans;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    cin >> n >> m >> k >> s;
    g.resize(n+1);
    for(int i = 0; i < n; i++){
        int good;
        cin >> good;
        citygood[i+1] = good;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    for(int i = 1; i <= n; i++){
        cout << solve(i) << " ";
    }
    cout << endl;
    return 0;
}