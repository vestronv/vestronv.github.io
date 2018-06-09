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
const int N = 1005; // 10^5
int n, m;
set<pair<int,int> >st;
int mat[N][N];
int done[N][N];
int ans = 0, mans = 0, temp = 0;
//.............data...................

//.............functions...................
bool valid(int i, int j){
	if(i < 0 || i >= n || j < 0 || j >= m)return false;
	return true;
}
void dfs3(int i,int j, int dude, int bro){
	if(!valid(i,j))return;
	if(mat[i][j]==dude)return;
	done[i][j]=false;
}
void dfs2(int i, int j, int dude, int bro){
	if(i < 0 || i >= n || j < 0 || j >= m)return ;
	if(done[i][j])return ;
	if(mat[i][j] != dude && mat[i][j] != bro)return;
	temp++;
	//mans = max(ans, mans);
	cout << "dfs2 : " << "i=" << i << ", j=" << j << ", val=" << mat[i][j] << ", ans=" << ans << ", temp=" << temp << ", bro=" << bro << ", dude=" << dude << endl;
	done[i][j] = true;
	dfs2(i+1, j, dude, bro);
	dfs2(i, j+1, dude, bro);
	dfs2(i-1, j, dude, bro);
	dfs2(i, j-1, dude, bro);
	//ans--;
	//done[i][j] = false;
}
void dfsMarker(int node, int r, int c){
	if(!valid(r,c))return ;
	if(mat[r][c] != node)return ;
	if(done[r][c])return ;
	done[r][c] = 1;
	ans++;
	//cout << ans << " {" << r << c << "}" << "-- ";
	dfsMarker(node, r+1, c);
	dfsMarker(node, r-1, c);
	dfsMarker(node, r, c+1);
	dfsMarker(node, r, c-1);
	//done[r][c] = 0;
}
void dfsUnMarker(int node, int r, int c){
	if(!valid(r,c))return ;
	if(mat[r][c] != node)return ;
	if(!done[r][c])return ;
	done[r][c] = 0;
	dfsUnMarker(node, r+1, c);
	dfsUnMarker(node, r-1, c);
	dfsUnMarker(node, r, c+1);
	dfsUnMarker(node, r, c-1);
	//done[r][c] = 0;
}
/*
4 5
1 1 2 3 1
3 1 2 5 2
5 2 1 5 6
1 3 1 2 1

5 5
1 1 1 1 1
2 2 2 2 1
3 4 5 6 1
3 3 3 3 1
3 3 3 3 1

7 7
1 1 2 3 4 5 6
1 1 1 2 3 4 5
1 1 2 3 4 1 1
1 1 3 4 1 1 1
3 4 5 1 1 1 1
7 8 9 1 1 1 1
1 2 1 1 2 1 2

9 7
1 1 2 3 4 5 6
1 1 1 2 3 4 5
1 1 2 3 4 1 1
1 1 3 4 1 1 1
3 4 5 1 1 1 1
7 8 9 1 1 1 1
1 2 1 1 2 1 2
2 5 6 7 8 9 10
1 5 6 4 6 8 4

*/

void dfs(int i, int j, int dude, int bro){
	if(i < 0 || i >= n || j < 0 || j >= m)return ;
	if(done[i][j]){return ;}
	if(mat[i][j] == dude){
		//ans++;
		mans = max(ans, mans);
		cout << "       i=" << i << ", j=" << j << ", val=" << mat[i][j] << ", ans="<< ans << ", mans=" << mans << ", bro=" << bro << ", dude=" << dude << endl;
		done[i][j] = true;
		bool d1=false,d2=false,d3=false,d4=false;
		// cover all dude's first . . .
		if(valid(i+1, j)){if(mat[i+1][j]==dude){d1=true;dfs(i+1,j,dude,-1);}}
		if(valid(i, j+1)){if(mat[i][j+1]==dude){d2=true;dfs(i,j+1,dude,-1);}}
		if(valid(i-1, j)){if(mat[i-1][j]==dude){d3=true;dfs(i-1,j,dude,-1);}}
		if(valid(i, j-1)){if(mat[i][j-1]==dude){d4=true;dfs(i,j-1,dude,-1);}}
		if(!d1)dfs(i+1, j, dude, -1);
		if(!d2)dfs(i, j+1, dude, -1);
		if(!d3)dfs(i-1, j, dude, -1);
		if(!d4)dfs(i, j-1, dude, -1);

		if(!d1)dfs3(i+1, j, dude, -1);
		if(!d2)dfs3(i, j+1, dude, -1);
		if(!d3)dfs3(i-1, j, dude, -1);
		if(!d4)dfs3(i, j-1, dude, -1);
		return;
	}
	else{
		dfs2(i,j,dude, mat[i][j]);
		mans = max(ans+temp, mans);
		temp = 0;
	}
	//ans--;
	if(mat[i][j] != dude)done[i][j] = false;
}
// map<int, vector<int> >mp;//comp size, nodes
// int dones[N];
// vector<vector<int> >g;
// void dfss(int node){
// 	dones[node]=1;
// 	ans++;
// 	for(vector<int>::iterator vit = g[node].begin(); vit != g[node].end(); vit++){
// 		if(!dones[*vit])dfss(*vit);
// 	}
// 	dones[node]=0;
// }



//int done[N][N];
//int mat[N][N];
//int n, m;
// bool isValid(int r, int c){
// 	if(r >= 0 && r < n && c >= 0 && c < m)return true;
// 	return false;
// }
// void print(){
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cout << done[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }
// void dfsMarker(int node, int r, int c){
// 	if(!isValid(r,c))return ;
// 	if(mat[r][c] != node)return ;
// 	if(done[r][c])return ;
// 	done[r][c] = 1;
// 	ans++;
// 	dfsMarker(node, r+1, c);
// 	dfsMarker(node, r-1, c);
// 	dfsMarker(node, r, c+1);
// 	dfsMarker(node, r, c-1);
// }
// void dfsUnMarker1(int node, int r, int c){
// 	if(!valid(r,c))return ;
// 	if(mat[r][c] != node)return ;
// 	if(!done[r][c])return ;
// 	done[r][c] = 0;
// 	dfsUnMarker1(node, r+1, c);
// 	dfsUnMarker1(node, r-1, c);
// 	dfsUnMarker1(node, r, c+1);
// 	dfsUnMarker1(node, r, c-1);
// 	//done[r][c] = 0;
// }
// void dfsProp(int node, int dude, int r, int c){
// 	if(!isValid(r,c))return ;
// 	if(mat[r][c] == dude && done[r][c]>=2)return ;
// 	if(mat[r][c] != dude && done[r][c])return ;
// 	if(mat[r][c] != node && mat[r][c] != dude){return;}
// 	done[r][c]++;
// 	cout << " r="<<r << " c="<<c<<endl;
// 	print();
// 	cout <<endl;
// 	temp++;
// 	dfsProp(node, dude, r+1, c);
// 	dfsProp(node, dude, r-1, c);
// 	dfsProp(node, dude, r, c+1);
// 	dfsProp(node, dude, r, c-1);
// 	done[r][c]--;// or a separate dfs again to reset ??
// }
// void dfsOther(int node, int dude, int r, int c){
// 	if(!isValid(r,c))return ;
// 	if(done[r][c] >= 2)return ;
// 	//done[r][c]++;
// 	if(mat[r][c] == node){
// 		dfsOther(node, dude, r+1, c);
// 		dfsOther(node, dude, r-1, c);
// 		dfsOther(node, dude, r, c+1);
// 		dfsOther(node, dude, r, c-1);
// 	}
// 	else{
// 		// start choosing pair for `node`
// 		//done[r][c]--;
// 		cout << done[r][c] << "   ";
// 		dfsProp(mat[r][c], dude, r, c);

// 		cout << r << " " << c << " " << dude << " " << ans << " " << temp << endl;
// 		mans = max(mans, ans + temp);
// 		temp = 0;
// 	}
// }

// int main(){
// 	cin >> n >> m;
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cin >> mat[i][j];
// 		}
// 	}
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			if(done[i][j] < 2){
// 				dfsMarker(mat[i][j], i, j);
// 				cout << ans;
// 				//dfsUnMarker1(mat[i][j], i, j);
// 				dfsOther(mat[i][j], mat[i][j], i, j);
// 				ans = 0;
// 			}
// 		}
// 	}
// 	cout << mans << endl;
// 	return 0;
// }
//.............functions...................

//.............main...................
int main(){
    boost;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> mat[i][j];
    		done[i][j] = false;
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		ans = 0;
    		if(!done[i][j]){
    			dfsMarker(mat[i][j], i, j); 
    			//dfsUnMarker(mat[i][j], i , j); 
    			dfs(i,j, mat[i][j],-1);
    		}
    	}
    }
    cout << mans << endl;
    

//     ///////////////////// CONNECTED COMPONENET WALA
//     // cin >> n;
//     // for(int i = 1; i < n; i++){
//     // 	int u, v;
//     // 	cin >> u >> v;
//     // 	g[u].PB(v);
//     // 	indeg[v]++;
//     // }
//     // for(int i = 1; i <= n; i++){
//     // 	if(indeg[i] == 0){
//     // 		ans = 0;
//     // 		dfss(i);
//     // 		mp[ans].PB(i);
//     // 	}
//     // }
//     // map<int, vector<int> >::iterator mit;
//     // mit = mp.end();
//     // mit--;
//     // if(mit == mp.end()){
//     // 	cout << -1;
//     // }
//     // else{
//     // 	vector<int>v = (*mit).second;
//     // 	sort(v.begin(), v.end());//lexographically
//     // 	for(vector<int>::iterator vit = v.begin(); vit != v.end(); vit++){
//     // 		cout << (*vit) << " ";
//     // 	}
//     // }
//    	// cout << endl;

//    	// ///////////////////// STRING VOWEL WALA
//    	// string str;
//    	// cin >> str;
//    	// int len = str.length();
//    	// string vowel = "";
//    	// for(int i = 0; i < len; i++){
//    	// 	if(vowel_(str[i]))vowel += str[i];
//    	// }
//    	// int val[n];
//    	// for(int i = 0; i < n; i++){
//    	// 	cin >> val[i];
//    	// }
//    	// int last_idx = -1;
//    	// int val_idx = 0;
//    	// while(q--){
//    	// 	int kth;
//    	// 	cin >> kth;
//    	// 	if(kth > last_idx){
//    	// 		last_idx++;
//    	// 		if(last_idx == n){
//    	// 			flag_idx = q;
//    	// 			break;
//    	// 		}
//    	// 		if(val[last_idx] < 0){

//    	// 		}
//    	// 		else{

//    	// 		}
//    	// 		val_idx++;
//    	// 	}
//    	// 	else{

//    	// 	}
//    	// }
    return 0;
}




/*

7 3
2 1 9 7 8 4 3
5 1 6 1 6 1 5

// -> 5
*/

/*
#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
	return min(a, min(b,c));
}
int min(int a, int b, int c, int d){
	return min(a, min(b,c,d));
}
int main(){
	int n, k;
	cin >> n >> k;
	int write[n], copy[n];
	for(int i = 0; i < n; i++){
		cin >> write[i];
	}
	for(int i = 0; i < n; i++){
		cin >> copy[i];
	}
	int dp[2][n+1];
	for(int i = 0; i <= n; i++){
		dp[0][i] = dp[1][i] = INT_MAX;
	}
	dp[0][0] = write[0];
	dp[1][0] = copy[0];
	for(int i = 1; i < n; i++){
		for(int j = i-k+1; j < i; j++){
			if(j >= 0){
				//dp[i] = min(dp[i], dp[j] + copy[j+1]);
				dp[0][i] = min(dp[0][i], dp[1][j]    , dp[1][j]+write[i]      , dp[0][i-1] + write[i]);
				dp[1][i] = min(dp[1][i], dp[0][j] + copy[i], dp[0][i-1] + copy[i]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << dp[0][i] << " " << dp[1][i] << endl;
	}
	cout << endl;
	
	return 0;
}


*/




/*

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
bool isvowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )return true;
    return false;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    int n, q;
    string str;
    string vowel="";
    cin >> n >> q;
    cin >> str;
    int val[n];
    int maxq;
    for(int i = 0; i < n; i++)cin >> val[i];
    //int vowel_pre[n];
    vector<int>vowel_pre;
    for(int i = 0; i < str.length(); i++){
        if(!i)vowel_pre.PB(isvowel(str[i])?1:0);
        else vowel_pre.PB( vowel_pre[i-1] + (isvowel(str[i])?1:0));
        if(isvowel(str[i]))vowel+=str[i];
    }
    // for(int i = 0; i < str.length(); i++){
    //     cout << vowel_pre[i] << " ";
    // }
    // cout << endl;
    vector<int>val_new;
    for(int i = 0; i < n; i++){
        if(val[i] < 0){
            int temp = val[i];
            temp = -temp;
            val_new.PB(vowel_pre[str.length()-1] - vowel_pre[temp-1]);
        }
        else{
            val_new.PB(vowel_pre[val[i]-1]);
        }
    }
    for(int i = 0; i < n; i++){
        if(i)val_new[i] += val_new[i-1];
    }
    // for(int i = 0; i < n; i++){
    //     cout << val_new[i] << " ";
    // }
    // cout << endl;
    maxq = val_new[n-1];
    cout << "maxq=" << maxq << endl;
    vector<pair<int,int> >queries;
    for(int i = 0; i < q; i++){
        int kth;
        cin >> kth;
        queries.PB({kth, i});
    }
    sort(queries.begin(), queries.end());
    vector<pair<int,int> >qans;
    for(vector<pair<int,int> >::iterator vit = queries.begin(); vit != queries.end(); vit++){
        int kth = (*vit).first;
        int ii = (*vit).second;
        if(kth > maxq){
            cout << -1 << endl;
            //qans.PB({i,-1});
        }
        else{
            vector<int>::iterator vit1 = lower_bound(val_new.begin(), val_new.end(), kth);
            int cur_idx = vit1 - val_new.begin();
            int to_be_find = kth;
            if(cur_idx > 0)to_be_find -= val_new[cur_idx-1];
            int yo = val[cur_idx];
            yo = yo<0 ? abs(yo):0;
            // yo se to_be_find'th wala vowel... can be at `yo` itself too..
            int vowel_before = 0;
            if(yo > 0)vowel_before = vowel_pre[yo-1];
            cout << cur_idx << " " << to_be_find << " " << yo << " " << vowel_before << endl;
            cout << vowel[vowel_before + to_be_find-1] << endl;
        }
    }
    sort(qans.begin(), qans.end());
    return 0;
}

*/





