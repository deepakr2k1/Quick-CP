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

vi adj[100005];
int L[100005];

void dfs(int v, vector<bool> &visit) {
    visit[v] = true;
    for(int x: adj[v]) {
        if(!visit[x])
            dfs(x, visit);
        L[v] = max(L[v], 1+L[x]);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    memset(L, 0, sizeof(L));
    while(m--) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visit(n+1, false);
    rep(i,1,n) {
        if(!visit[i])
            dfs(i, visit);
    }
    int ans=0;
    rep(i,1,n) ans=max(ans, L[i]);
    cout<<ans;
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