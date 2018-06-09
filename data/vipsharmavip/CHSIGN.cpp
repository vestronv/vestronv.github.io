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
const int N = 200070; // 10^5
const ll INF = 1e18+7L;
ll dp[N][2];// include, exclude
ll arr[N];
ll badids[N];
//.............data...................

//.............functions...................
//.............functions...................

//.............main...................
int main(){
    boost;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n + 7; i++){
            arr[i] = 0L;
            badids[i] = 0L;
            dp[i][0] = dp[i][1] = 0L;
        }
        arr[0] = INF;
        arr[n + 1] = INF;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i <= n; i++){
            if(arr[i] < arr[i+1] && arr[i] < arr[i-1]){
                badids[i] = 1L;
            }
        }
        for(int i = 1; i <= n;){
            if(!badids[i]){
                i++;
                continue;
            }
            if(badids[i] && !badids[i+2]){
                arr[i] *= -1;
                i++;
                continue;
            }
            int r = i;
            while(badids[r]){
                r += 2;
            }
            r -= 2;
            dp[i][0] = 0L;// exc
            dp[i][1] = arr[i];// inc
            ll to_be_remove = dp[i][1];
            int from_idx = i;
            for(int j = i + 2; j <= r; j += 2){
                dp[j][0] = max(dp[j-2][0], dp[j-2][1]);
                if(arr[j] + arr[j-2] >= arr[j-1])dp[j][1] = arr[j] + dp[j-2][0];
                else dp[j][1] = arr[j] + max(dp[j-2][0], dp[j-2][1]);
                if(to_be_remove < dp[j][1]){
                    from_idx = j;
                    to_be_remove = dp[j][1];
                }
            }
            int just_removed = -1;
            for(int j = from_idx; j >= i; j -= 2){
                if(dp[j][1] == to_be_remove){
                    if(j+2 == just_removed && arr[j] >= arr[j+1] + arr[j+2])continue;
                    to_be_remove -= arr[j];
                    arr[j] *= -1;
                    just_removed = j;
                }
            }
            i = r + 1;
        }
        for(int i = 1; i <= n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define pb push_back
// #define mp make_pair
// #define f first
// #define s second
// #define sc(n) scanf("%d",&n)
// #define scl(n) scanf("%lld",&n)
// #define pr(n) printf("%d",n)
// #define prl(n) printf("%lld",n)
// #define nl printf("\n")
// #define fr(i,n) for(i=1;i<=n;i++)
 
// typedef long long ll;
// const int N = 200010;
// ll A[N],dp[N][2];
// int mark[N];
// ll INF = 1e18+5;
// int main()
// {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int t=1,n,i,j;
//     cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         for(int i=0;i<n+5;i++)
//         {
//             A[i]=0;
//             mark[i]=0;
//             dp[i][0]=0;
//             dp[i][1]=0;
//         }
//         i=0;
//         fr(i,n)cin>>A[i];
//         A[0]=INF;
//         A[n+1]=INF;
//         fr(i,n)if(A[i]<A[i-1] && A[i]<A[i+1])mark[i]=1;
//         int i=1;
//         while(i<=n)
//         {
//             if(!mark[i]){i++;continue;}
//             if(mark[i]&&!mark[i+2]){
//                 A[i]*=-1;
//                 i++;
//                 continue;
//             }
//             else
//             {
//                 int lim=i;
//                 while(mark[lim]){
//                     lim+=2;}
//                 lim-=2;
 
 
//                 dp[i][1]=A[i];
//                 dp[i][0]=0;
//                 for(int j=i+2;j<=lim;j+=2)
//                 {
//                     dp[j][0]=max(dp[j-2][0],dp[j-2][1]);
//                     if(A[j]+A[j-2]>=A[j-1])dp[j][1]=A[j]+dp[j-2][0];
//                     else dp[j][1]=A[j]+dp[j][0];
//                 }
//                 ////////////////////
//                 cout << i << " - " << lim << endl;
//                 for(int j = i; j <= lim; j += 2){
//                     cout << dp[j][0] << " ";
//                 }
//                 cout << endl;
//                 for(int j = i; j <= lim; j += 2){
//                     cout << dp[j][1] << " ";
//                 }
//                 cout << endl;
//                 ////////////////////
//                 ll mx = 0;
//                 int ind = 0;
//                 for(int j=i;j<=lim;j+=2)
//                 {
//                     if(dp[j][1]>mx){//greatest sum with exc..
//                         mx = dp[j][1];
//                         ind = j;
//                     }
//                 }
//                 ll cur = mx;
//                 int nex =-1;
//                 for(int k = 1; k <= n; k++)cout<<A[k]<<" ";
//                     cout<<endl;
//                 for(int j=ind;j>=i;j-=2)
//                     if(dp[j][1]==cur)
//                     {
//                         cout << endl;
//                         cout<<nex<<" "<<j+2<<" "<< j;
//                         cout<<endl;
//                         if (nex==j+2 && A[j]-A[j+2]>=A[j+1])continue;
//                         cur-=A[j];
//                         A[j]*=-1;
//                         nex = j;
                        
//                     }
 
 
 
//                 i=lim+1;
//             }
//         }
//         i=0;
//         fr(i,n)cout<<A[i]<<" ";
//         cout<<"\n";
 
//     }
//     return 0;
// }
//  