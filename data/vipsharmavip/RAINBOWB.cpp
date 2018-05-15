// #include<iostream>
// #define mod 1000000007
// using namespace std;
// int main()
// {
	
// 	   long long int n;
// 	   long long int base=720;
// 	   long long int exp=mod-2,ans=1,ans2=1,i;
// 	   while(exp>0)
// 	   {
//    		if(exp&1)
//    		ans=ans*base%mod;
//    		exp=exp>>1;
//    		base=base*base%mod;
//    	}
// 	   	ans2=1;
//    		cin>>n;
//    		n=n-13;
//    		if(n&1)
//    		n=n-1;
//    		n=n/2;
//    		for(i=1;i<=6;i++)
//    		{
// 		   	ans2=ans2*(n+i)%mod;
// 		   }
// 		   ans2=ans2*ans%mod;
// 		   cout<<ans2<<endl;
//    	return 0;
// } 

// // copy From Here
// // need for speed...
// #include <bits/stdc++.h>
// using namespace std;
// // bad times...

// //.............template...................
// #define vimal
// #ifdef vimal

// #endif
// #define boost ios::sync_with_stdio(0);cin.tie(0);
// #define PB push_back
// #define MP make_pair
// typedef long long ll;
// //.............template...................

// //.............data...................
// const int N = 1005; // 10^3
// const int MOD = 1000000007;
// //.............data...................

// //.............functions...................
// //.............functions...................

// //.............main...................
// int main(){
//   boost;
//   int n;
//   cin >> n;
//   int start = n/2 - 1;
//   int times = n/2 - 6;
//   long long ans = 1;
//   long long temp = 1;
//   int temp2 = start;
//   while(temp2){
//     temp *= temp2;
//     if(temp >= MOD)temp -= MOD;
//     if(temp < 0)temp += MOD;
//     temp2--;
//   }
//   int den = 720;
//   for(int i = 0; i < min(times,6); i++){
//     ans += (temp2) / den;
//     if(temp >= MOD)temp -= MOD;
//     if(temp < 0)temp += MOD;
//     den /= (6-i);
//     temp2 /= start;
//     start--;
//   }
//   cout << ans;
//   return 0;
//   }









#include <algorithm>
#include <iostream>
#include <ctime>
#include <memory.h>
#include <vector>
#include <map>
#include <fstream>
#include <string>
 
using namespace std;
 
int n, k;
 
/*
Main idea: From first k + 2 elementh we can choose two numbers that will not change. Use brute force for first K + 2 numbers. Final solution is O(K ^ 2 * N).
* You can think about O(N * K) solution - it is quite easy :)
*/ 
 
void solve() {
  scanf("%d%d",&n,&k);
  vector<int> a(n);
  map < pair <long long, long long>, bool> f;
  for (int i = 0; i < n; ++i)
    scanf("%d",&a[i]);
  int ans = 0;
  long long E, Q, Fir;
  long long aF = 1000000000000000LL, sF = -1;
  for (int i = 0; i < k + 2; ++i)
    for (int j = i + 1; j < k + 2; ++j){
      // choose first and second number that will not change
      E = a[j] - a[i];
      Q = E / (j - i);
      // calculate d - (Ai = A0 + i * d)
      if (Q * (j - i) == E) {
        Fir = a[i] - Q * i;
        // check is it new pair --- Fir = A0, Q = d
        if (f[make_pair(Fir, Q)] == false) {
          f[make_pair(Fir, Q)] = true;
          // chK - number of error that can do
          int chK = k;
          for (int qt = 0; qt < n; ++qt) {
            if (Fir != a[qt]) chK--;
            if (chK < 0) break;
            Fir += Q;
          }
          if (chK >= 0) {
            // checking this sequence for beauty
            Fir = a[i] - Q * i;
            if (Fir < aF || (Fir == aF && sF > Q)) {
              aF = Fir;
              sF = Q;
            }
          }
        }
      }
    }
  if (aF > 1000000000000LL) printf("-1\n");
  else {
    // printing this sequence
    for (int i = 0; i < n; ++i) {
      printf("%lld ", aF);
      aF += sF;
    }
    printf("\n");
  }
}
 
int main(){
  solve();
  return 0;
}
 
