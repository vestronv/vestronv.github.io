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
const int N = 1005; // 10^5
ll mat[N][N];
ll left_[N][N];
ll right_[N][N];
ll up_[N][N];
ll down_[N][N];
//.............data...................

//.............functions...................
void print(int n, int m){
    cout << "LEFT----------\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << left_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "RIGHT---------\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << right_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "UP------------\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << up_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "DOWN----------\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << down_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------\n";
}
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin         >> mat[i][j];
                left_[i][j]   = 0;
                right_[i][j]  = 0;
                up_[i][j]     = 0;
                down_[i][j]   = 0;
                    if(j == 0) left_[i][j] = mat[i][j];
                    else       left_[i][j] = max(left_[i][j-1] + mat[i][j], mat[i][j]); // including current necessary
                    if(i == 0) up_[i][j]   = mat[i][j];
                    else       up_[i][j]   = max(up_[i-1][j]   + mat[i][j], mat[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = m-1; j >= 0; j--){
                int                     rowFromdown_           = n-1-i;
                if(j == m-1)            right_[i][j]           = mat[i][j];
                else                    right_[i][j]           = max(right_[i][j+1]             + mat[i][j],            mat[i][j]);
                if(rowFromdown_ == n-1) down_[rowFromdown_][j] = mat[rowFromdown_][j];
                else                    down_[rowFromdown_][j] = max(down_[rowFromdown_ + 1][j] + mat[rowFromdown_][j], mat[rowFromdown_][j]);
            }
        }
        //print(n , m);
        ll ans = -1LL<<30;;
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                ans = max(ans, left_[i][j-1] + right_[i][j+1] + up_[i-1][j] + down_[i+1][j] + mat[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
