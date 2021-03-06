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
double A[3001], dp[3001][3001];

void solve() {
    int n;
    cin>>n;
    rep(i,1,n) cin>>A[i];

    rep(i,0,n) dp[0][i]=0;
    rep(i,0,n) dp[i][0]=1;

    rep(i,1,n) {
        rep(j,0, n) {
            dp[i][j]=0;
            dp[i][j]+=dp[i-1][j]*(1-A[i]);
            dp[i][j]+=dp[i-1][j-1]*A[i];
        }
    }
    
    double ans=0;
    rep(i,n/2+1,n) ans+=dp[n][i];
    cout<<fixed<<setprecision(9)<<ans<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    solve();
}