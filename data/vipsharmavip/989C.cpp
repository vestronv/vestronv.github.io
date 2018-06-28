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
    int a, b, c , d;
    int aa, bb, cc, dd;
    cin >> a >> b >> c >> d;
    aa=a;bb=b;cc=c;dd=d;
    char str[50][50];
    map<char,int>mp;
    mp['A']=a;mp['B']=b;mp['C']=c;mp['D']=d;
    map<char,int>::iterator mit=mp.end();
    mit--;
    char aaa = (*mit).first;
    int high = (*mit).second;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 50; j++){
            str[i][j]=(*mit).first;
        }
    }
    mit--;
    for(int i = 30; i < 50; i++){
        for(int j = 0; j < 50; j++){
            str[i][j]=(*mit).first;
        }
    }
    map<char,int>::iterator mit2 = mp.end();
    mit2--;
    mit2--;
    int now = (*mit2).second;
    map<int,int>infected1,infected2;
    for(int i = 0; i < 30; i+=2){
        for(int  j = 0; j < 50; j+=2){
            if(now > 1){
                infected1[i]=1;
                now--;
                str[i][j] = (*mit2).first;
            }
        }
    }
    for(int i = 49; i > 29; i-=2){
        for(int  j = 0; j < 50; j+=2){
            if(high > 1){
                infected2[i]=1;
                high--;
                str[i][j] = aaa;
            }
        }
    }
    mit2--;
    now= (*mit2).second;
    int doin = 1;
    for(int i = 0; i < 50; i += 2){
        for(int j = 0; j < 50; j+=2){
            if(!infected2[i] && !infected1[i]){
                if(now>0){
                    str[i][j] = (*mit2).first;
                    now--;
                }
                else if(doin == 1){
                    doin = 2;
                    mit2--;
                    now = (*mit2).second;
                }
            }
        }
    }
    cout << "50 50\n";
    ////////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < 50; i++){
        for(int  j = 0; j < 50; j++){
            cout << str[i][j];
        }
        cout <<endl;
    }
    return 0;
}