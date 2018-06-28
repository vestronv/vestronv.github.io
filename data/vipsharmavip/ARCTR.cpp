    #include<bits/stdc++.h>
     
    using namespace std;
     
    vector<int> fac;
     
    //int dp[42][700][700];
    unordered_map<int, int> dp;
    unordered_map<int, vector<int> > af;
    unordered_map<int, int> fid;
    int a[1000010];
     
    inline int has(int n, int c, int next) {
        return (n * 2000 + c) * 2000 + next;
    }
     
    void aldiv(vector<int> &div, int c) {
        if(div.size()) return;
        for(int i = 1; i * i <= c; i++) {
            if(c % i == 0) {
                div.push_back(i);
                if(i * i != c)
                div.push_back(c / i);
            }
        }
        sort(div.begin(), div.end());
    }
     
    bool f(int h) {
        int g = h / 2000;
        int n = g / 2000;
        int c = g % 2000;
        int next = h % 2000;
     
        if(dp.count(h)) return dp[h];
        //cout << fac[c] << ' ' << fac[next] << '\n';
        if(fac[c] == 1) return true;
        if(n == 1 && (fac[c] > fac[next] + 1)) return false;
        else if(n == 1 && (fac[c] <= fac[next] + 1)) return true;
        int res = fac[c];
     
     
        //aldiv(af[fac[c]], fac[c]);
        vector<int> &div = af[fac[c]];
     
        bool pos = false;
        for(int i = 0; i < div.size(); i++) {
            if(div[i] > fac[next] + 1)
                break;
            pos |= f(has(n - 1, fid[fac[c] / div[i]],  fid[div[i]]));
            if(pos)break;
        }
        dp[h] = pos;
        return pos;
    }
     
    int check(int n, int c) {
     
        if(c == 1) return 1;
        if(n == 1) return c;
     
        //aldiv(af[c], c);
        vector<int> &div = af[c];
        int res = c;
        for(int i = div.size() - 1; i >= 0; i--) {
            int sel = div[i];
            int prev = f(has(min(32, n - 1), fid[c / sel], fid[sel]));
            if(prev) {
                //cout << sel << "a " << c << '\n';
                res = min(res, sel);
            }
        }
        return res;
    }
     
     
     
    int main(){
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
     
        int t;
        t = 1002;
        int ns = 1, cs = 1;
        //cin >> t;
        //memset(dp, -1, sizeof(dp));
        while(t--) {
            //memset(dp, -1, sizeof(dp));
            dp.clear();
            int n, c, rem;
            //cin >> n >> c;
            
            n = ns;
        c = cs;
        cout << n << " " << c << " ";
            ns++;
        if(ns == 11){cs++;ns=1;}

            rem = c;
            fac.clear();
            fid.clear();
            aldiv(fac, c);
            if(n == 1 && fac.size() == 2) {
                cout << fac[1] << '\n';
                continue;
            }
            af[c] = fac;
     
            for(int i = 1; i < fac.size(); i++) {
                int tem = fac[i];
                vector<int> er;
                for(int j = 0; j <= i; j++) {
                    if(tem % fac[j] == 0) {
                        er.push_back(fac[j]);
                       // cout << fac[j] << ' ';
                    }
                }
                //cout << '\n';
                af[tem] = er;
            }
     
     
            //if(fac.size() > 100) abort();
            for(int i = 0; i < fac.size(); i++) {
                fid[fac[i]] = i;
            }
            //int y = check(i + 1, rem)
            for(int i = n - 1; i >= 0; i--) {
                int y = check(i + 1, rem);
     
                while(rem % y == 0) {
                    rem /= y;
                    a[i] = i + y;
                    i--;
                    y++;
                }
                i++;
                //rem /= y;
                //a[i] = i + y;
            }
     
            for(int i = 0; i < n; i++)
                cout << a[i] << ' ';
            cout << '\n';
     
        }
     
        return 0;
    }
     
// // copy From Here
// // need for speed...
// #include <bits/stdc++.h>
// using namespace std;
// // bad times...

// //.............template....................
// #define vimal
// #ifdef vimal
// #endif
// #define boost ios::sync_with_stdio(0);cin.tie(0);
// #define PB push_back
// #define MP make_pair
// typedef long long ll;
// //.............template....................

// //.............data........................
// const int N = 2000005; // 10^5
// int n, m;
// bool done[N];
// long double ans[N];
// vector<pair<int,int> > g[N];
// pair<int,int> parent[N];
// vector<int> record, lvl;
// int dist[N];
// int logg[3*N], dp[3*N][25], lsz[N];
// //.............data........................

// //.............functions...................
// int isp2(int i){
// 	return !(i&(i+1));
// }
// void sparse(int n){
// 	logg[0] = -1;
// 	for(int i = 0; i <= n; i++){
// 		dp[i][0] = i;
// 		logg[i+1] = logg[i] + isp2(i);
// 	}
// 	for(int j = 1; (1<<j) <= n; j++){
// 		for(int i = 0; (i+(1<<j)) <= n; i++){
// 			int a = dp[i][j-1];
// 			int b = dp[i+(1<<(j-1))][j-1];
// 			if(lvl[a] < lvl[b])dp[i][j] = a;
// 			else dp[i][j] = b;
// 		}
// 	}
// }
// int lca_helper(int pp, int qq) {
//     if (pp > qq) swap(pp, qq);
// 	int g = logg[qq-pp+1];
// 	int a = dp[pp][g];
// 	int b = dp[qq - (1 << g) + 1][g];
// 	if (lvl[a] < lvl[b])
//         return a;
//     return b;
// }
// int lca(int a, int b){
//     return record[lca_helper(lsz[a] - 1, lsz[b] - 1)];
// }
// void dfs(int node, int parr, int level){
// 	lvl.PB(level);
// 	if(!lsz[node])lsz[node] = lvl.size();
// 	dist[node] = level;
// 	record.PB(node);
// 	for(int i = 0; i < g[node].size(); i++){
// 		int v = g[node][i].first;
// 		int distance = g[node][i].second;
// 		if(v != parr){
// 			dfs(v, node, level + 1);
// 			lvl.PB(level);
// 			record.PB(node);
// 			parent[v] = {node, distance};
// 		}
// 	}
// }
// struct speedster{
//     long double t;
//     int lca_, u, v, spd, cur;
//     speedster(long double tt , int uu , int vv , int ss){
//         lca_ = lca(uu, vv);
//         cur = 0;
//         if(lca_ == uu){
//             cur = 1;
//         }
//         u = uu;
//         v = vv;
//         spd = ss;
//         t = tt;
//     }
//     bool operator < (const  speedster & x) const{
//     	if(t == x.t)return spd < x.spd;
//         return t > x.t;
//     }
// };
// void solve(){
//     priority_queue<speedster>q;
//     cin >> m;
//     for(int i = 0 ; i < m ; i++){
//         int u, v, t, spd;
//         cin >> u >> v >> t >> spd;
//         q.push(speedster(t , u , v , spd));
//     }
//     int idx = 0;
//     while(!q.empty()){
//         speedster now = q.top();
//         q.pop();
//         if(!done[now.u]){
//             done[now.u] = true;
//             ans[now.u] = now.t;
//             idx++;
//             if(idx == n)break;
//         }
//         if(now.u == now.v)continue;
//         int next;
//         long double c = now.t;
//         if(now.cur == 0){
//             next = parent[now.u].first;
//             long double cost = parent[now.u].second * 1.0/now.spd;
//             c += cost;
//             if(next == now.lca_)now.cur = 1;
//         }
//         else{
//             next = now.u;
//             for(int i = 0 ; i < g[next].size() ; i++){
//                 int a = g[next][i].first;
//                 long double cost = g[next][i].second * 1.0/now.spd;
//                 if(a != parent[next].first  && lca(a , now.v) == a){
//                 	next = a;
//                 	c += cost; 
//                 	break;
//                 }
//             }
//         }
//         while(next != now.v && done[next]){
//             if(now.cur == 1){
//                 for(int i = 0 ; i < g[next].size() ; i++){
//                     int a = g[next][i].first;
//                     double cost = g[next][i].second * 1.0/now.spd;
//                     if(a != parent[next].first  && lca(a , now.v) == a){
//                     	next = a;
//                     	c += cost;
//                     	break;
//                     }
//                 }
//             }
//             else{
//                 next = parent[now.u].first;
//                 double cost = parent[now.u].second * 1.0/now.spd;
//                 c += cost;
//                 if(next == now.lca_)now.cur = 1;
//             }
//         }
//         if(done[next]) continue;
//         q.push(speedster(c , next , now.v , now.spd));
//     }
//     for(int i = 1 ; i<=n ; i++){
//     	if(!done[i]){
//     		ans[i] = -1;
//     	}
//     	cout << fixed << setprecision(12) << ans[i] << "\n";
//     }
// }
// //.............functions...................

// //.............main........................
// int main(){
// 	boost;
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		cin >> n;
// 		for(int i = 0; i < n+2; i++){
// 			done[i] = false;
// 		}
// 		for(int i = 0; i < n-1; i++){
// 			int u, v, d;
// 			cin >> u >> v >> d;
// 			g[u].PB({v,d});
// 			g[v].PB({u,d});
// 		}
// 		dfs(1, -1, 0);
// 		sparse(lvl.size());
// 		solve();
// 	}
// 	return 0;
// }



// //for(int i = 0; i < N; i++){
// //			done[i] = false;
// //		}

// // int F[N], dist[N], st[3*N][25], LOG[3*N]; vector<int> E, L;
// // vector<pair<int,int> > edges[N];
// // pair<int,int> par[N];
 
// // void dfs(int u, int p =-1, int level=0) {
// //     E.push_back(u);
// //     L.push_back(level);
 
// //     if (F[u] == 0)
// //         F[u] = L.size();
 
// //     dist[u] = level;
 
// //     for (int i = 0; i < edges[u].size(); ++i) {
// //         int v = edges[u][i].first;
 
// //         if (v != p) {
// //             dfs(v, u, level + 1);
// //             E.push_back(u);
// //             L.push_back(level);
// //             par[v] = {u , edges[u][i].second};
// //         }
// //     }
// // }
 
// // void build_sparse_table(int n) {
// // 	int x, y, i, j;
 
// // 	for (i = 0, LOG[0] = -1; i <= n; ++i) {
// // 		st[i][0] = i;
// // 		LOG[i + 1] = LOG[i] + !(i & (i + 1));
// // 	}
 
// // 	for (j = 1; (1 << j) <= n; ++j) {
// // 		for (i = 0; (i + (1 << j)) <= n; ++i) {
// // 			x = st[i][j - 1];
// // 			y = st[i + (1 << (j - 1))][j - 1];
// // 			if (L[x] < L[y])
// //                 st[i][j] = x;
// //             else
// //                 st[i][j] = y;
 
// // 		}
// // 	}
// // }
 
// // inline int getMin_st(int l, int r) {
// //     if (l > r) swap(l, r);
 
// // 	int s = r - l + 1;
// // 	int g = LOG[s];
 
// // 	int a = st[l][g];
// // 	int b = st[r - (1 << g) + 1][g];
 
// // 	if (L[a] < L[b])
// //         return a;
// //     else
// //         return b;
// // }
 
// // inline int LCA(int u, int v) {
// //     return E[getMin_st(F[u] - 1, F[v] - 1)];
// // }
 
// // double ans[N];
// // int visit[N];
// // int n,m;
// // struct node
// // {
// //     double t;
// //     int lca,u,v,s,cur;
// //     node(double tt , int uu , int vv , int ss)
// //     {
// //         lca = LCA(uu,vv);
// //         if(lca == uu)
// //         {
// //             cur = 1;
// //         }
// //         else cur = 0;
// //         u = uu,v = vv, s = ss;
// //         t = tt;
// //     }
// //     bool operator < (const  node & x) const
// //     {
// //         return t > x.t;
// //     }
// // };
// // int vid;
 
// // void dikstra()
// // {
// //     int nw = 0;
// //     priority_queue<node>q;
// //     vid++;
// //     scanf("%d" , &m);
// //     for(int i = 0 ; i<m ; ++i)
// //     {
// //         int u,v,t,s;
// //         scanf("%d%d%d%d" , &u , &v , &t , &s);
// //         q.push(node(t , u , v , s));
// //     }
// //     while(!q.empty())
// //     {
// //         node x = q.top();
// //         q.pop();
// //         if(visit[x.u] != vid)
// //         {
// //             visit[x.u] = vid;
// //             ans[x.u] = x.t;
// //             nw++;
// //             //cout<<nw<<endl;
// //             if(nw==n) break;
// //         }
// //         if(x.u == x.v) continue;
// //         int nxt;
// //         double c = x.t;
// //         if(x.cur==0)
// //         {
// //             nxt = par[x.u].first;
// //             double aaa=1ll*par[x.u].second * 1.0/x.s;
// //             c += aaa;
// //             if(nxt == x.lca) x.cur = 1;
// //         }
// //         else
// //         {
// //             nxt = x.u;
// //             for(int i = 0 ; i<edges[nxt].size() ; ++i)
// //                 {
// //                     int a = edges[nxt][i].first;
// //                     double aaa=1ll*edges[nxt][i].second * 1.0/x.s;
// //                     if(a != par[nxt].first  && LCA(a , x.v) == a ) {nxt = a; c += aaa; break;}
// //                 }
// //         }
// //          while(nxt != x.v && visit[nxt] == vid)
// //             {
// //                 if(x.cur)
// //                 {
// //                     for(int i = 0 ; i<edges[nxt].size() ; ++i)
// //                     {
// //                         int a = edges[nxt][i].first;
// //                         double aaa=1ll*edges[nxt][i].second * 1.0/x.s;
// //                         if(a != par[nxt].first  && LCA(a , x.v) == a) {nxt = a; c+= aaa; break;}
// //                     }
// //                 }
// //                 else
// //                 {
// //                     nxt = par[x.u].first;
// //                     double aaa=1ll*par[x.u].second * 1.0/x.s;
// //                     c += aaa;
// //                     if(nxt == x.lca) x.cur = 1;
// //                 }
// //             }
// //         if(visit[nxt] == vid) continue;
// //         q.push(node(c , nxt , x.v , x.s));
// //     }
// //     for(int i = 1 ; i<=n ; ++i) if(visit[i] != vid) ans[i] = -1;
// // }
 
// // int main()
// // {
// //     int T;
// //     cin>>T;
// //     while(T--)
// //     {
// //         scanf("%d" , &n);
// //         for(int i = 0 ; i<n-1 ; ++i)
// //         {
// //             int u,v,c;
// //             scanf("%d%d%d" , &u , &v , &c);
// //             edges[u].push_back({v,c});
// //             edges[v].push_back({u,c});
// //         }
// //         dfs(1);
// //         cout << "\nF: ";
// //         for(int i = 0; i < 20; i++){
// //         	cout << F[i] << " ";
// //         }
// //         cout << "\nDist: ";
// //         for(int i = 0; i < 20; i++){
// //         	cout << dist[i] << " ";
// //         }
// //         cout << "\nE: ";
// //         for(int i = 0; i < E.size(); i++){
// //         	cout << E[i] << " ";
// //         }
// //         cout << "\nL: ";
// //         for(int i = 0; i < E.size(); i++){
// //         	cout << L[i] << " ";
// //         }
// //         cout << endl;
// //         build_sparse_table(L.size());
// //         dikstra();
 
// //         for(int i = 1 ; i<=n ; ++i) printf("%.7f\n" , ans[i]);
// //     }
// //     return 0;
// // }

// // int main(){
// // 	boost;
// // 	int t;
// // 	cin >> t;
// // 	while(t--){
// // 		int n, q;
// // 		cin >> n;
// // 		for(int i = 0; i < n-1; i++){
// // 			int u, v, d;
// // 			cin >> u >> v >> d;
// // 			g[u].PB({v,d});
// // 			g[v].PB({u,d});
// // 		}
// // 		dfs(1);
// // 		sparse(L.size());
// // 	}
// // }