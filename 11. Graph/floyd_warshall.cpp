// Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.
// T(n) = O(n^3)

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

vector<vector<pii>> adj;
int n;

vvi floydWarshall() {
    vvi dp(n, vi(n, INF));
    rep(i,0,n-1) dp[i][i]=0;
    rep(u,0,n-1) {
        for(auto x: adj[u]) {
            int v = x.first, wt = x.second;
            dp[u][v] = wt;
        }
    }
    rep(k,0,n-1) {
        rep(i,0,n-1) {
            rep(j,0,n-1) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    return dp;
}

void solve() {
    n=4;
    adj.resize(n);
    adj[0].push_back({1,11});
    adj[0].push_back({2,31});
    adj[1].push_back({2,7});
    adj[1].push_back({3,4});
    adj[2].push_back({3,1});
    
    vvi dp = floydWarshall();
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
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