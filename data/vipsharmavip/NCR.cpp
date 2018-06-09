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
typedef vector<int> VI;
typedef pair<int,int>PII;
//.............template...................

//.............data...................
const int N = 1000005; // 10^5
vector<ll>arr;
//.............data...................

//.............functions...................
ll power(ll a, ll b){
    if(b == 0)return 1L;
    else if(b == 1L)return a;
    ll temp = power(a, b >> 1);
    if(b % 2L == 0L)return temp * temp;
    return temp * temp * a;
}
//.............functions...................

//.............main...................
int main(){
    boost;
    pre();
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        nCr(n, r);
    }
    return 0;
    }




///////////////////////////////////////////////////////////
 
from fractions import gcd
from math import sqrt,log
import time
from random import randint
import random
from sets import Set
 
Nmax = 10 ** 6 + 10
arr = [1] * Nmax


void precal(ll p, ll e, ll m){
    arr.PB(1L);
    arr.PB(1L);
    for(int i = 2; i <= m; i++){
        if(i%p){
            arr.PB((arr[i-1] * (ll)i) % m);
        }
        else arr.PB(arr[i-1]);
    }
}
ll E(ll n, ll p){
    ll ret = 0L;
    n = n/p;
    while(n){
        ret = ret + n;
        n /= p;
    }
    return ret;
}
ll f(ll n, ll p, ll m){
    return (power(arr[m], n/m, m) * arr[n % m]) % m;
}
ll F(ll n, ll p, ll m){
    ll i = 1L;
    ll ret = 1L;
    while(i <= n){
        ret = ret * f(n/i, p, m) % m;
        i = p * i;
    }
    return ret;
}
ll mod_pem(ll n, ll r, ll p, ll e, ll m){
    ll powp = E(n, p) - E(r, p) - E(n-r, p);
    ll mod1 = F(n, p, m);
    ll mod2 = (F(r, p, m) * F(n-r, p, m) ) % m;
    return (power(p, powp, m) * mod1 * power(mod2, (m/p) * (p-1) -  1, m)) % m;
}
ll get_binom(ll n, ll r, ll p, ll e){
    ll m = power(p, e);
    pre(p, e, m);
    return mod_pem(n, r, p, e, m);
}

 
def precalculate(p, e, m):
    for i in range(2, m + 1):
        x = 1
        if i % p : x = i
        arr[i] = arr[i-1] * x % m
 
def E(n,p): # exponent of p in n!
    ret,n = 0, n / p
    while n: ret, n = ret + n, n / p
    return ret
 
def f(n, p, m): # product of numbers <=n, and coprime to p.
    return pow(arr[m], n / m, m) * arr[n % m] % m
 
def F(n, p, m): # n! / p ^ e modulo m, where p ^ e || n!
    i,ret = 1, 1
    while i <= n: ret,i = (ret * f(n / i, p, m)) % m, p * i
    return ret
 
def mod_pem(n, r, p, e, m): # nCr modulo p ^ e
    powp = E(n , p) - E(r , p) - E(n - r, p)
    mod1, mod2 = F(n, p, m), (F(r, p, m) * F(n - r, p, m)) % m
    return (pow(p, powp, m) * mod1 * pow(mod2, (m / p) * (p - 1) - 1, m)) % m
 
def get_binom(n, r, p, e):
    m = pow(p, e)
    precalculate(p, e, m)
    return mod_pem(n, r, p, e, m)

bool _try_composite(ll a, ll d, ll n, ll s){
    if(power(a, d, n) == 1){
        return false;
    }
    for(int i = 0; i < s; i++){
        if(power(a, power(2, i)*d, n) == n-1){
            return false;
        }
    return false;
    }
} 
def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2**i * d, n) == n-1:
            return False
    return True # n  is definitely composite

bool is_prime(ll n, int _precision_for_huge_n=10){
    
} 
def is_prime(n, _precision_for_huge_n=10):
    if n in _known_primes or n in (0, 1):
        return True
    for p in _known_primes:
        if n%p==0:
            return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1
    # Returns exact according to http://primes.utm.edu/prove/prove2_3.html
    if n < 1373653:
        return not any(_try_composite(a, d, n, s) for a in (2, 3))
    if n < 25326001:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5))
    if n < 118670087467:
        if n == 3215031751:
            return False
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7))
    if n < 2152302898747:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11))
    if n < 3474749660383:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13))
    if n < 341550071728321:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13, 17))
    return not any(_try_composite(a, d, n, s)
                   for a in _known_primes[:_precision_for_huge_n])
 
_known_primes = [2, 3]
_known_primes += [x for x in range(5, 1000, 2) if is_prime(x)]

def brent(N): #Fails for perfect squares,primes
        if N%2==0:
                return 2
        y,c,m = random.randint(1, N-1),random.randint(1, N-1),random.randint(1, N-1)
        g,r,q = 1,1,1
        while g==1:
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if g==N:
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break
 
        return g
def floor_sqrt(n):
    x = max(0,int(sqrt(n))-1)
    while x*x<=n:
        x+=1
    return x-1
def prime_factors(n):# Returns all prime factors of n
    ret = Set()
    if n==1:
        return ret
    if is_prime(n):
        ret.add(n)
        return ret
    x = floor_sqrt(n)
    if x*x == n:
        return prime_factors(x)
    x = brent(n)
    n/=x
    while n%x == 0:
        n/=x
    r1 = prime_factors(x)
    r2 = prime_factors(n)
    for i in r1:
        ret.add(i)
    for i in r2:
        ret.add(i)
    return ret
def factorization(n):
    X = prime_factors(n)
    Arr = []
    for i in X:
        Arr.append(i)
    ret = {}
    for i in range(0,len(Arr)):
        val = 0
        p = Arr[i]
        while n%p == 0:
            val+=1
            n/=p
        ret[p] = val
    assert(n==1)
    return ret
tot = [1] * Nmax
def inv(a, b): return pow(a, tot[b] - 1, b)
def crt(A,B):# all elements of A are mutually coprime
    N = 1
    for i in range(0,len(A)):
        N*=A[i]
    ret = 0
    for i in range(0,len(A)):
        val = A[i]
        md = B[i]
        prod_rem = N/val
        ret += md * (prod_rem*inv(prod_rem,val))
    ret %= N
    for i in range(0,len(A)):
        assert ret % A[i] == B[i]
    return ret
 
ll solve(ll n, ll r, ll m){
    vector<ll>A;
    vector<ll>B;
    X = factorization(m)
    for(int i = 0; i < X.size(); i++){
        int e = X[i];
        A.PB(power(p, e));
        B.PB(get_binom(n, r, p, e));
        tot[power(p, e)] = power(p, e-1) * (p-1);
    }
    crt(A, B);
}
def ans(n, r, m):
    X = factorization(m)
    A, B = [], []
    for p in X:
        e = X[p]
        A.append(p ** e)
        B.append(get_binom(n, r, p, e))
        tot[p ** e] = (p ** (e - 1) * (p - 1))
    return crt(A, B)
for t in range(input()):
    n, k, m = map(int, raw_input().split())  
    #C(r*k - N + r - 1, r - 1)
    r = (n - 1) / k + 1
    print r, ans(r * k - n + r - 1, r - 1, m)   