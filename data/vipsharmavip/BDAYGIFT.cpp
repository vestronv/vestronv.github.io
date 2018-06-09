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
    	cin >> str;
    	str = str + str;
    	int len = str.length();
    	char ch;
    	int maxi = 0;
    	for(int i = 0; i < len/2; i++){
    		if(str[i]-'a' > maxi){
    			maxi = str[i]-'a';
    			ch = str[i];
    		}
    	}
    	vector<int>pos;
    	for(int i = 0; i < len/2; i++){
    		if(str[i] == ch)pos.PB(i);
    	}
    	int covered = pos[0];
    	int point  = pos[0];
    	int maxi2 = 0;
    	for(vector<int>::iterator vit = pos.begin(); vit != pos.end(); vit++){
    		if(*vit < covered)continue;
    		for(int j = *vit; j<len-1 ; j++){
    			if(str[j] >= str[j+1]);
    			else {
    				covered = j;
    				if(j-(*vit) > maxi2){
    					maxi2 = j-(*vit);
    					point = (*vit);
    				}
    				break;
    			}
    		}
    	}
    	for(int i = point; i < point+(len/2); i++){
    		cout << str[i];
    	}
    	cout << endl;
    }
    return 0;
}

/*
for i in range(n):
    for j in range(m):
        D[i+1][j]=H[i][j]+D[i][j]
        R[i][j+1]=H[i][j]+R[i][j]

for i in range(n):
    for j in range(m):
        for (k = 1, s = H[i][j]; i-k >= 0 and j+k <  m; k++)
            yield (s += R[i-k][j+k+1] - R[i-k][j])
        for (k = 1, s = H[i][j]; i+k <  n and j+k <  m; k++)
            yield (s += R[i+k][j+k+1] - R[i+k][j])
        for (k = 1, s = H[i][j]; i-k >= 0 and j-k >= 0; k++)
            yield (s += R[i-k][j+1] - R[i-k][j-k])
        for (k = 1, s = H[i][j]; i+k <  n and j-k >= 0; k++)
            yield (s += R[i+k][j+1] - R[i+k][j-k])
        for (k = 1, s = H[i][j]; i-k >= 0 and j-k >= 0 and j+k < m; k++)
            yield (s += R[i-k][j+k+1] - R[i-k][j-k])
        for (k = 1, s = H[i][j]; i+k <  n and j-k >= 0 and j+k < m; k++)
            yield (s += R[i+k][j+k+1] - R[i+k][j-k])
        for (k = 1, s = H[i][j]; j-k >= 0 and i-k >= 0 and i+k < n; k++)
            yield (s += D[i+k+1][j-k] - D[i-k][j-k])
        for (k = 1, s = H[i][j]; j+k <  m and i-k >= 0 and i+k < n; k++)
            yield (s += D[i+k+1][j+k] - D[i-k][j+k])
*/