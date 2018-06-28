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
template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};
//.............functions...................
 
//.............main...................
int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        map< pair<int,int> , int >rows;
        map< pair<int,int> , int >cols;
        unordered_map<int, int> freq;
        int arr[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int val;
                cin >> val;
                arr[i][j] = val;
                rows[{i,val}]++;
                cols[{j,val}]++;
                freq[val]++;
            }
        }
        vector<pair<int, int> > mapcopy(freq.begin(), freq.end());
        sort(mapcopy.begin(), mapcopy.end(), less_second<int, int>());
        reverse(mapcopy.begin(), mapcopy.end());
        if(mapcopy.size() > 30)mapcopy.erase(mapcopy.begin()+29, mapcopy.end());
        int ans = 1;
        int flag = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                ans = max(ans, rows[{i,arr[i][j]}] + cols[{j,arr[i][j]}] - 1);
                if(ans == n+m-1)flag = true;
                for(int k = 0; k < min(10, (int)mapcopy.size()); k++){
                    int ulala = rows[{i,mapcopy[k].first}] + cols[{j,mapcopy[k].first}];
                    if(mapcopy[k].first == arr[i][j])ulala--;
                    ans = max(ans, ulala);
                    if(ans == n+m-1)flag = true;
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
4 4
1 2 2 2
3 1 1 1
1 2 2 2
1 2 2 2
*/