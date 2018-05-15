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
int pf[N*10];
map<int, vector<pair<int,int> > >cache;
vector<int>primes;
//.............data...................

//.............functions...................
void sieve(){
	int is_prime[N*10];
	for(int i = 0; i < N*10; i++){
		is_prime[i] = 1;
	}
	is_prime[0] = is_prime[1] = 0;
	for(int i = 0; i < N*10; i++){
		if(is_prime[i]){
			primes.PB(i);
			for(int j = i + i; j < N*10; j += i){
				is_prime[j] = 0;
			}
		}
	}
}

int solve(int num){
	int idx = 1;
	int den = primes[0];
	int times = 0;
	int onum = num;
	bool boo = false;
	while(num > 1){
		while(num > 1 && (num % den == 0)){
			num /= den;
			times++;
		}
		//cout << onum << " " << times << ", ";
		pf[den] = max(pf[den], times);
		cache[onum].push_back({den,times});
		times = 0;
		den = primes[idx];
		idx++;
	}
	
	return times;
}
//.............functions...................

//.............main...................
int main(){
	boost;
	sieve();
	int t;
	cin >> t;
	while(t--){
		int maxi = 0;
		for(int i = 0; i < N*10; i++)pf[i] = 0;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;
			int freq = 0;
			while(num % 2 == 0){
				freq++;
				num /= 2;
			}
			if(freq > pf[2])pf[2] = freq;
			for(int j = 3; j <= sqrt(num); j += 2){
				freq = 0;
				while(num % j == 0){
					freq++;
					num /= j;
				}
				if(freq > pf[j])pf[j] = freq;
			}
			if(num > 2){
				if(pf[num] < 1)pf[num] = 1;
			}
		}
		for(int i = 2; i < N*10; i++)maxi += pf[i];
		cout << maxi << "\n";
	}
	return 0;
}

