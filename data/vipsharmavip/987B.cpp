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
    int n;
    cin >> n;
    int ohh = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(val != i+1){
            ohh++;
        }
    }
    if(ohh&1 && (n)&1){
        cout << "Petr";
    }
    else if(!(ohh&1) && (!((n)&1))){
        cout <<"Petr";
    }
    else cout << "Um_nik";
    return 0;
}