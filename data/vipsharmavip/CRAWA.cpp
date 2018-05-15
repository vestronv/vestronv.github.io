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
	// int x=0,y=0;
	// int step = 1;
	// for(int i = 0; i < 50; i++){
	// 	cout<<"["<<x<<","<<y<<"] ";
	// 	if(i%4 == 0){
	// 		x+=step;
	// 	}
	// 	if(i%4 == 1){
	// 		y+=step;
	// 	}
	// 	if(i%4 == 2){
	// 		x-=step;
	// 	}
	// 	if(i%4 == 3){
	// 		y-=step;
	// 	}
	// 	step++;
	// }
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		if(x > 0 && x %2 == 1 && y >= (-(x-1)) && y <= x+1)cout<<"YES\n";
		else if(x < 0 && (-x)%2 == 0 && y <= (-(x)) && y >= x)cout<<"YES\n";
		else if(y > 0 && (y%2 == 0) && (x >= -y) && x < y)cout<<"YES\n";
		else if(y <= 0 && y % 2 ==0 && x >= y && x <= (-y+1))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
	}
