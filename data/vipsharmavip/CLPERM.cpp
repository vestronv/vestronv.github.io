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
int missing[N*2];
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
	boost;
	int t;
	cin >> t;
	while(t--){
		int n, k;
		ll missSum = 0L;
		for(int i = 0; i < N*2; i++)missing[i] = 0;
		cin >> n >> k;
		for(int i = 0; i < k; i++){
			ll val;
			cin >> val;
			missSum += val;
			if(val < N*2)
				missing[val] = 1;
		}
		ll sum = 1;
		if(k == 0){
			sum = (((ll)n)*((ll)n+1))/2L;
			sum++;
		}
		else{
			for(int i = 1; (i <= sum && i <= n); i++){
				if(!missing[i])sum += i;
				if(sum >= n){
					sum = (((ll)n)*((ll)n+1))/2L;
					sum++;
					sum -= missSum;
					break;
				}
			}
		}
		if(!(sum&1)){
			cout << "Mom\n";
		}
		else{
			cout << "Chef\n";
		}
	}
	return 0;
	}
