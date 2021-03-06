#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x)           (x).begin(),(x).end()
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// ....................  zero_bug  ....................

// probability of collision in k comparsion is k/MOD < 10^-3 then its ok,
// but if it exceeds 10^-3, then we need to use hashed pair on different MODS {hash(str, MOD1), hash(str, MOD2)}
// MOD1 1e9+7
// MOD2 1e9+9

#define N 100005
#define MOD 1000000007
#define base 101

int pw[N];
int inv[N];
int pHash[N];

int power(int x,int y) {                      // Iterative Function to calculate (x^y)%MOD in O(logy)
    int res=1;
    x %= MOD;
    while (y>0) {
        if(y&1) res=(res*x)%MOD;
        y=y>>1;
        x=(x*x)%MOD;
    }
    return res;
}

void preCalc() {
    pw[0] = inv[0] = 1;
    int pw_inv = power(base, MOD-2);
    rep(i,1,N-1) pw[i] = (pw[i-1]*base) % MOD;
    rep(i,1,N-1) inv[i] = (inv[i-1]*pw_inv) % MOD;
}

void build(string &str) {
    int n = str.length();
    pHash[0] = (str[0]-'a')+1;
    rep(i,1,n-1) {
        pHash[i] = pHash[i-1] + ((str[i]-'a')+1) * pw[i];
        pHash[i] %= MOD;
    }
}

int getHash(int l, int r) {
    if(l==0) return pHash[r];
    int ans = (pHash[r]-pHash[l-1]) % MOD;
    ans = (ans*inv[l]) % MOD;
    if(ans<0) ans+=MOD;
    return ans;
}

void solve() {
    int n;
    cin>>n;
    string t, str;
    cin>>t>>str;
    build(t);
    int patter_hash_val = getHash(0, n-1);
    
    build(str);
    int ans=0;
    int l=0, r=n-1;
    while(r<str.length()) {
        if(getHash(l,r) == patter_hash_val) {
            ans++;
            cout<<l<<endl;
        }
        l++,r++;
    }
    if(ans==0) cout<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    preCalc();
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}