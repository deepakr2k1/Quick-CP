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
#define op2(V,sep)        for(int _i=0;_i<V.size();_i++) {for(int _j=0;_j<V[_i].size();_j++) cout<<V[_i][_j]<<sep; cout<<endl;}
inline void readInt(int &x) {
    bool neg = false;
    register int c;
    x = 0;
    c=getchar();
    if(c=='-') neg = true, c=getchar();
    for(;(c>47 && c<58);c=getchar()) x = (x<<1) + (x<<3) +c -48;
    if(neg) x = -x;
}
// ....................  zero_bug  ....................

int ans=0;

void fun(vi &A, int idx, int sum) {
    if(idx == A.size()) {
        if(sum == idx) ans++;
        return;
    }
    fun(A,idx+1,sum);
    fun(A,idx+1,sum+A[idx]);
}

void solve() {
    vi A;
    rep(i,1,10) A.push_back(i);
    fun(A, 0, 0);
    cout<<ans<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    // int t;
    // cin>>t;
    // rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    // }
}