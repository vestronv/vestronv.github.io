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
const int N = 2005;
int dirX[] = {0,0,1,-1};
int dirY[] = {1,-1,0,0};
int n, m, mans, cur, indexx, id, valA, valB;
int cache[N][N], mat[N][N], freq[N*N], vis[N*N], track[N*N];
set<int>st[N*N];
//.............data...................

//.............functions...................
bool valid(int r, int c){
    if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == cur && cache[r][c] != indexx)return true;
    return false;
}
void dfsSimple(int r,int c){
    cache[r][c] = indexx;
    freq[indexx]++;
    for(int i = 0; i < 4; i++){
        int nr = r + dirX[i], nc = c + dirY[i];
        if(valid(nr,nc)){
            dfsSimple(nr,nc);
        }
    }
}
int dfsNotSimple(int node){
    int anss = freq[node];
    vis[node] = id;
    vector< set<int>::iterator > vs;
    for(set<int>::iterator sit = st[node].begin(); sit != st[node].end(); ++sit){
        if(vis[*sit] != id && (track[*sit] == valA || track[*sit] == valB)) anss += dfsNotSimple(*sit);
        if(track[*sit] == valA || track[*sit] == valB) vs.push_back(sit);
    }
    for(int i = 0; i < vs.size(); i++) st[node].erase(vs[i]);
    return anss;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    #ifdef vimal
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    indexx = 1;
    id = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                if(!cache[i][j]){
                    cur = mat[i][j];
                    dfsSimple(i,j);
                    mans = max(mans,freq[indexx]);
                    track[indexx] = mat[i][j];
                    indexx++;
                }
            }
    }
    //cout << indexx << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j && cache[i][j-1] != cache[i][j]) st[cache[i][j-1]].insert(cache[i][j]),st[cache[i][j]].insert(cache[i][j-1]);
            if(i && cache[i-1][j] != cache[i][j]) st[cache[i-1][j]].insert(cache[i][j]),st[cache[i][j]].insert(cache[i-1][j]);

            if(j<m-1 && cache[i][j+1] != cache[i][j]) st[cache[i][j+1]].insert(cache[i][j]),st[cache[i][j]].insert(cache[i][j+1]);
            if(i<n-1 && cache[i+1][j] != cache[i][j]) st[cache[i+1][j]].insert(cache[i][j]),st[cache[i][j]].insert(cache[i+1][j]);

            if(i == 0 && j == 2){
                cout << cache[i][j-1] << " " << cache[i][j] << endl;
                st[cache[i][j]].insert(cache[i][j-1]);
            }
        }
    }

    set<int>::iterator sit;
    for(int i = 1; i < indexx; i++){
        valA = track[i];
        cout << valA << ": ";
        while(!st[i].empty()){
            sit = st[i].begin();
            valB = track[*sit];
            cout << valB << " ";
            mans = max(mans,dfsNotSimple(i));
            id++;
        }
        cout << endl;
    }
    cout << mans << endl;
    return 0;
}