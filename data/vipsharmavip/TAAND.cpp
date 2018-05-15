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
const int N = 300005; // 10^5
int arr[N], n;
//.............data...................

//.............functions...................
int solve(int mask){
	int count = 0;
	for(int i = 0; i < n; i++){
		if((arr[i] & mask) == mask)count++;
	}
	return count;
}
//.............functions...................

//.............main...................
int main(){
	boost;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	long long ans = 0L;
	for(int i = 30; i >= 0; i--){
		if(solve(ans | (1<<i)) >= 2){
			ans |= (1 << i);
		}
	}
	cout << ans;
	return 0;
	}
