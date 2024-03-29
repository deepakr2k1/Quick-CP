// Bellman-Ford is an algorithm for single source shortest path where edges can be negative,
// but if there is a cycle with negative weight, then this problem will be NP.
// T(n) = O(n^2)

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

vi bellman_ford(int v) {
    vi d(n, INF);
    d[v]=0;
    rep(steps,1,n) {
        rep(u,0,n-1) {
            for(auto X: adj[u]) {
                int v = X.first, wt = X.second;
                if(d[u] + wt < d[v]) {
                    if(steps == n) return {-1};
                    d[v] = d[u] + wt;
                }
            }
        }
    }
    return d;
}

void solve() {
    n=4;
    adj.resize(n);
    adj[0].push_back({1,11});
    adj[0].push_back({2,31});
    adj[1].push_back({2,-7});
    adj[1].push_back({3,4});
    adj[2].push_back({3,1});

    op(bellman_ford(0)," ");
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