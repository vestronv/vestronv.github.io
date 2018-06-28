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
    int n, p;
    string str;
    cin >> n >> p;
    cin >> str;
    bool period = true;
    for(int i = 0; i < n-p; i++){
    	if(str[i] == '.' || str[i+p] == '.'){
    		if(str[i] == str[i+p]){
    			str[i] = '0';
    			str[i+p] = '1';
    		}
    		else{
    			if(str[i] == '.'){
    				if(str[i+p] == '1')str[i] = '0';
    				else str[i] = '1';
    			}
    			else{
    				if(str[i] == '1')str[i+p] = '0';
    				else str[i+p] = '1';
    			}
    		}
    		period = false;
    	}
    	else if(str[i] != str[i+p]){
    		period = false;
    		//break;
    	}
    }
    if(period)cout << "No";
    else{
    	for(int i = 0; i < n; i++){
    		if(str[i] == '.')str[i] = '0';
    	}
    	cout << str;
    }
    return 0;
}