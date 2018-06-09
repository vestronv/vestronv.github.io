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
ll arr[22], sum, target;
int taken[22];
int n, k;
//.............data...................

//.............functions...................
bool pass(){
	if(sum%k != 0)return false;
	if(k > n)return false;
	target = sum / k;
	return true;
}
bool rec(int idx, int count, ll curSum){
	//cout << idx << " " << count << " " << curSum << endl;
	if(idx < n){
		if(taken[idx])return rec(idx+1, count, curSum);
		if(curSum + arr[idx] == target){
			count++;
			taken[idx] = 1;
			if(count == k){
				return true;
			}
			return rec(0, count, 0L);
		}
		else{
			if(curSum + arr[idx] < target){
				taken[idx] = 1;
				bool iftake = rec(idx+1, count, curSum + arr[idx]);
				taken[idx] = 0;
				bool ifnotake = rec(idx+1, count, curSum);
				return iftake | ifnotake;
			}
			else return rec(idx+1, count, curSum);
		}
	}return false;
}
//.............functions...................

//.............main...................
int main(){
	boost;
	int t;
	cin >> t;
	while(t--){
		sum = 0;
		for(int i = 0; i < 22; i++)taken[i] = 0;
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		if(!pass()){
			cout << "no\n";
			continue;
		}
		bool found = rec(0, 0, 0L);
		if(found)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
	}