#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mk make_pair
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie();
using namespace std;
typedef pair<int, int> pii;
const ll MOD=1e9+7;
const int N=0;
 
int par[1];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void join(int x,int y){par[find(x)]=y;}
ll expo(ll a,ll b,ll mod){ll ans=1; while(b){if(b&1) ans=(ans*a)%mod; a=(a*a)%mod; b>>=1;} return ans;}
int gcd(int a,int b,int& x,int& y) {if(a==0){x=0;y=1;return b;}int x1, y1;int d=gcd(b%a, a, x1, y1);x=y1-(b/a)*x1;y=x1;return d;}
 
ll c[20][20],p[10][20];
int a[10],b[10];
int fix[10];
int dig[20];
int fix_n,dig_n;
 
ll ways_to_place(int places){
	ll ans=1;
	for(int i=0;i<fix_n;++i){
		if(b[fix[i]]<0){
			return 0;
		}
		ans*=c[places][b[fix[i]]];
		places-=b[fix[i]];
		if(places<0){
			return 0;
		}
	}
	ans*=p[10-fix_n][places];
	//cout<<ans<<"\n";
	return ans;
}
 
ll calc(ll x){
	if(x==0) return 0;
	cout << x << ", ";
    for(dig_n=0;x;x/=10){
		dig[dig_n++]=x%10;
	}
    cout << dig_n << "  --  ";
	int i,j,be;
	for(i=0;i<10;++i){
		b[i]=a[i];
	}
	ll ans=0;
	for(i=0;i<dig_n-1;++i){
		for(j=1;j<10;++j){
			b[j]--;
			ans+=ways_to_place(i);
			b[j]++;
		}
	}
	for(i=dig_n-1;i>=0;--i){
		be=(i==dig_n-1 ? 1 : 0);
		for(j=be;j<dig[i];++j){
			b[j]--;
			ans+=ways_to_place(i);
			b[j]++;
		}
		b[dig[i]]--;
	}
	ans+=ways_to_place(0);
	return ans;
}
 
ll solve(ll x){
	int i,end=(1<<10);
	ll ans=x;
	for(int mask=1;mask<end;++mask){
		fix_n=0;
		for(i=0;(1<<i)<=mask;++i){
			if(mask&(1<<i)){
				fix[fix_n++]=i;
			}
		}
		if(fix_n&1){
			ans-=calc(x);
		} else{
			ans+=calc(x);
		}
	}
	return ans;
}
 
void init(){
	int i,j;
	for(i=0;i<20;++i){
		c[i][0]=1;
	}
	for(i=1;i<20;++i){
		for(j=1;j<=i;++j){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	p[0][0]=1;
	for(i=1;i<=10;++i){
		p[i][0]=1;
		for(j=1;j<20;++j){
			p[i][j]=p[i][j-1]*i;
		}
	}
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main(){
	int test,i;
	ll r,l;
	ll res;
	init();
	scanf("%d",&test);
	while(test--){
		scanf("%lld",&l);scanf("%lld",&r);
		for(i=0;i<10;++i){
			scanf("%d",&a[i]); 
		}
		res=solve(r)-solve(l-1);
		printf("%lld\n", res);
	}	
	return 0;
} 