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
		int n, q;
		cin >> n >> q;
		int arr[n+2], L[n+1], R[n+2];
		L[0] = R[0] = L[n+1] = R[n+1] = -1;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		L[1] = arr[1];
		R[n] = arr[n];
		for(int i = 2; i <= n; i++){
			L[i]     = __gcd(L[i-1], arr[i]);
			R[n-i+1] = __gcd(R[n-i+2], arr[n-i+1]);
		}
		while(q--){
			int l, r;
			cin >> l >> r;
			if(l == 1){
				cout << R[r+1] << endl;
			}
			else if(r == n){
				cout << L[l-1] << endl;
			}
			else{
				cout << __gcd(L[l-1], R[r+1]) << endl;
			}
		}
	}
	return 0;
	}
