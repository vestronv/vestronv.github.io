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
int solve(vector<int> &A) {
    int sz = A.size();
    int mat[sz+1][sz+1];
    for(int i = 0; i < sz + 1; i++){
        for(int j = 0; j < sz + 1; j++){
            mat[i][j] = 0;
        }
    }
    int count[sz];
    for(int  i = 0; i < sz; i++){
        count[i] = 1;
        A[i]--;
    }
    int pos = 0;
    int jump = 0;
    while(pos < sz){
        //if(count[pos] == -1){
        //    count[pos]++;
        //    pos = A[pos];
        //    jump++;
        //}
        //else 
        if(count[pos]&1){
            count[pos]++;
            if(mat[A[pos]][pos]){
                cout << A[pos] << ", "<< pos << ",  ";
                jump += mat[A[pos]][pos];
                mat[pos][pos+1] = ++jump;
                pos++;
            }
            else{pos = A[pos];
            jump++;}
        }
        else{
            count[pos]++;
            mat[pos][pos+1] = ++jump;
            pos++;
            //jump++;
        }
        //cout << pos << " , " << jump << " ";
    }
    return jump;
}

vector<int> solve2(vector<int> &A, vector<int> &B) {
    int as = A.size();
    int bs = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int pa = 0, pb = 0;
    int ans = INT_MIN;
    int ansa = -1, ansb = -1;
    int d= 0;
    ans = 3*as - 3*bs;
    ansa = 3*as;
    ansb = 3*bs;
    while(pa < A.size() && pb < B.size()){
        if(A[pa] <= B[pb]){
            int temp = 2*(pa+1) + 3*(as-pa) - ((pb)*2 + (bs-pb)*3);
            if(temp > ans){
                ans = temp;
                ansa = 2*(pa+1) + 3*(as-pa-1);
                ansb = ((pb)*2 + (bs-pb-1)*3);
            }
            pa++;
        }
        else {
            int temp = 2*(pa) + 3*(as-pa) - ((pb+1)*2 + (bs-pb)*3);
            if(temp > ans){
                ans = temp;
                ansa = 2*(pa+1) + 3*(as-pa-1);
                ansb = ((pb)*2 + (bs-pb-1)*3);
            }
            pb++;
        }
        cout << pa << " " << pb << " , ";
        int deb;
        //cin >> deb;
        if(pa >= as || pb >= bs)break;
    }
    vector<int>C;
    C.push_back(ansa);
    C.push_back(ansb);
    
}


//.............main...................
int main(){
    boost;
    vector<int>vv1;
    vector<int>vv2;
    vv1.push_back(5);
    vv1.push_back(6);
    vv1.push_back(7);
    vv1.push_back(8);
    vv2.push_back(1);
    vv2.push_back(2);
    vv2.push_back(3);
    vv2.push_back(4);
    solve2(vv1,vv2);// << endl;
    return 0;

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
    //cout << "maxq=" << maxq << endl;
    vector<pair<int,int> >queries;
    for(int i = 0; i < q; i++){
        int kth;
        cin >> kth;
        queries.PB({kth, i});
    }
    sort(queries.begin(), queries.end());
    vector<pair<int,string> >qans;
    for(vector<pair<int,int> >::iterator vit = queries.begin(); vit != queries.end(); vit++){
        int kth = (*vit).first;
        int ii = (*vit).second;
        cout << ii << " ";
        if(kth > maxq){
            //cout << -1 << endl;
            qans.PB({ii,"-1"});
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
            //cout << cur_idx << " " << to_be_find << " " << yo << " " << vowel_before << endl;
            //cout << vowel[vowel_before + to_be_find-1] << endl;
            string titu(1,vowel[vowel_before + to_be_find-1]);
            qans.PB({ii, titu});
        }
    }
    sort(qans.begin(), qans.end());
    for(int i = 0; i < qans.size() ; i++){
        cout << qans[i].second << " ";
    }
    //cout << endl;
    return 0;
}


/*
int Solution::solve(vector<int> &A) {
    int sz = A.size();
    int mat[sz+1][sz+1];
    for(int i = 0; i < sz + 1; i++){
        for(int j = 0; j < sz + 1; j++){
            mat[i][j] = 0;
        }
    }
    int count[sz];
    for(int  i = 0; i < sz; i++){
        count[i] = 1;
        A[i]--;
    }
    int pos = 0;
    int jump = 0;
    while(pos < sz){
        //if(count[pos] == -1){
        //    count[pos]++;
        //    pos = A[pos];
        //    jump++;
        //}
        //else 
        if(count[pos]&1){
            count[pos]++;
            if(mat[A[pos]][pos]){
                jump += mat[A[pos]][pos];
                mat[pos][pos+1] = ++jump;
                pos++;
            }
            else{pos = A[pos];
            jump++;}
        }
        else{
            count[pos]++;
            mat[pos][pos+1] = ++jump;
            pos++;
            //jump++;
        }
    }
    return jump;
}

*/


/*

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int as = A.size();
    int bs = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int pa = 0, pb = 0;
    int ans = INT_MIN;
    int ansa = -1, ansb = -1;
    int d= 0;
    ans = 3*as - 3*pb;
    ansa = 3*as;
    ansb = 3*bs;
    while(pa < as && pb < bs){
        if(A[pa] <= B[pb]){
            int temp = 2*(pa+1) + 3*(as-pa) - ((pb)*2 + (bs-pb)*3);
            if(temp > ans){
                ans = temp;
                ansa = 2*(pa+1) + 3*(as-pa-1);
                ansb = ((pb)*2 + (bs-pb-1)*3);
            }
            pa++;
        }
        else {
            int temp = 2*(pa) + 3*(as-pa) - ((pb+1)*2 + (bs-pb)*3);
            if(temp > ans){
                ans = temp;
                ansa = 2*(pa+1) + 3*(as-pa-1);
                ansb = ((pb)*2 + (bs-pb-1)*3);
            }
            pb++;
        }
        if(pa == as || pb == bs)break;
    }
    vector<int>C;
    C.push_back(ansa);
    C.push_back(ansb);
}

*/