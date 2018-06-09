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
		string str;
		int k;
		cin >> str >> k;
		int len = str.length();
		ll ans = 0LL;
		for(int i = 0; i < len; i++){
			int freq[26];
			for(int i = 0; i < 26; i++)freq[i] = 0;
			int cnt = 0, hif = 0;
			for(int j = i; j >= 0; j--){
				if(freq[str[j] - 'a'] == 0)cnt++;
				hif = max(hif, ++freq[str[j]-'a']);
				if(cnt>=k && hif*cnt == i-j+1)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
	}
