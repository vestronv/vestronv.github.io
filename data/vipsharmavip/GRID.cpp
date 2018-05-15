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
		int n;
		cin >> n;
		string str[n];
		for(int i = 0; i < n; i++){
			cin >> str[i];
		}
		int x[n][n];
		int y[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				x[i][j] = 1;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				y[i][j] = 1;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = n-1; j >= 0; j--){
				if(str[i][j]=='#')x[i][j] = 0;
				else{
					if(j == n-1)x[i][j] = 1;
					else x[i][j] *= x[i][j+1]; 
				}
			}
		}
		for(int i = n-1; i >= 0 ;i--){
			for(int j = n-1; j >= 0; j--){
				if(str[j][i]=='#')y[j][i] = 0;
				else{
					if(j == n-1)y[j][i] = 1;
					else y[j][i] *= y[j+1][i];
				}
			}
		}
		// cout << "\n";
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < n; j++){
		// 		cout << x[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(x[i][j] && y[i][j])ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
	}
