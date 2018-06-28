// copy From Here
// need for speed...
#include <bits/stdc++.h>
using namespace std;
// bad times...

//.............template....................
#define vimal
#ifdef vimal
#endif
#define boost ios::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define MP make_pair
typedef long long ll;
//.............template....................

//.............data........................
const int N = 100005; // 10^5
//.............data........................

//.............functions...................

//.............functions...................

//.............main........................
int main(){
    boost;
    string str;
    cin >> str;
    // int arr[200];
    bool done = false;
    int flag = 0;
    map<char,int>mp;
    int a=0,b=0,c=0;
    for(int i = 2; i < str.length(); i++){
    	if(str[i-2] == 'A')a++;
    	if(str[i-2] == 'B')b++;
    	if(str[i-2] == 'C')c++;
    	if(str[i-1] == 'A')a++;
    	if(str[i-1] == 'B')b++;
    	if(str[i-1] == 'C')c++;
    	if(str[i-0] == 'A')a++;
    	if(str[i-0] == 'B')b++;
    	if(str[i-0] == 'C')c++;
    	if(a == 1 && b == 1 && c == 1){
    		done=true;
    		cout <<"Yes";
    	}
    	a=0;b=0;c=0;
    	// if(str[i] != '.'){
    	// 	flag++;
    	// 	mp[str[i]]++;
    	// 	if(str[i]=='A')a++;
    	// 	if(str[i]=='B')b++;
    	// 	if(str[i]=='C')c++;
    	// 	if(a>){
    	// 		done = true;
    	// 		cout << "Yes";
    	// 		break;
    	// 	}
    	// }
    	// else{
    	// 	a = 0; b = 0; c = 0;
    	// 	mp.clear();
    	// 	flag = 0;
    	// }
    }
    if(!done)cout << "No";
    // for(int i = 1; i < str.length(); i++){
    // 	arr[i] += arr[i-1];
    // }
    return 0;
}