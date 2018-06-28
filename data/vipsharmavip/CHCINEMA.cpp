#include<bits/stdc++.h>
inline long long int 
Scan_f(){
long long int num = 0;
	char c = getchar_unlocked();
	while(!(c>='0' & c<='9'))
	    c=getchar_unlocked();
	while(c>='0' && c<='9'){
	    num = (num<<1)+(num<<3)+c-'0';
	    c=getchar_unlocked();
	}
return num;
}

inline long long min(long long a, long long b){
	return a<b?a:b;
}
 
inline long long cl(long long a){
return a&1 ? (a>>1)+1 : a>>1;
}
 
inline long long cl1(long long a, long long b){
return a%b ? (a/b)+1 : a/b;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long ans=0, seats, n, m, z, l, r, b, lpr, x, y, ymod, flag;
	n=Scan_f(); m=Scan_f(); z=Scan_f(); l=Scan_f(); r=Scan_f(); b=Scan_f();
		seats = n*m;
		if( m==1 || r+l+z>=n*m || (b<=n) ){	
			ans=min(seats, z+l+r+b);
            cout << "easy...\n";
        }
		else{
			if(m%2){
				lpr=ans=l+r;
				flag=lpr & 1;	y=(lpr>>1);
				ymod=y%n; y/=n;
				ans+=min(b, ymod*cl(m-(2*(y+1))));					
				b-=min(b, ymod*cl(m-(2*(y+1))));
				ans+=min(b, (n-ymod)*cl(m-2*y));
			if(b>=(n-ymod)*cl(m-2*y) && flag==1)
				ans--;
				ans+=min(seats-ans, z);
			}
		else{
			lpr=ans=l+r;
			if(lpr<=n){
				ans+=min(b, lpr*cl(m-1));
				b-=min(b, lpr*cl(m-1));
				ans+=min(b, (n-lpr)*cl(m));
			}
			else{
				lpr-=n;	flag=lpr&1;
				y=lpr>>1; ymod=y%n;
				y/=n;
				ans+=min(b, ymod*cl( (m-1)-(2*(y+1))));
				b-=min(b, ymod*cl( (m-1)-(2*(y+1))));
				ans+=min(b, (n-ymod)*cl((m-1)-2*y));				
				if(b>=(n-ymod)*cl((m-1)-2*y) && flag==1)
					ans--;
			}
			ans+=min(seats-ans, z);  
		}   
		}
		printf("%lld\n",ans);
	}
	return 0;
}  
