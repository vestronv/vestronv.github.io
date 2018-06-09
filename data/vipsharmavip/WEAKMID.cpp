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
int arr[N];
int ans[N];
int ne[N], pr[N];
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    //srand(time(NULL));
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ne[i] = i+1;
            pr[i] = i-1;
            ans[i] = 0;
        }
        if(n <= 2){
            for(int i = 0; i < n; i++){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        vector<int>rem;
        for(int i = 1; i <= n-2; i++){
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1])rem.PB(i);
        }
        for(int d = 1; d < n-2; d++){
            vector<int>next_rond;
            for(int i = 0; i < rem.size(); i++){
                ans[rem[i]] = d;
                int prev = pr[rem[i]];
                int next = ne[rem[i]];
                if(prev >=0 && next < n){
                    ne[prev] = next;
                    pr[next] = prev;
                    int prevprev = pr[prev];
                    if(prevprev >= 0){
                        if(arr[prev] < arr[prevprev] && arr[prev] < arr[next]){
                            next_rond.PB(prev);
                        }
                    }
                    int nextnext = ne[next];
                    if(nextnext < n){
                        if(arr[next] < arr[nextnext] && arr[next] < arr[prev]){
                            next_rond.PB(next);
                        }
                    }
                }
            }
            rem = next_rond;
        }
        for(int i = 0 ; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}