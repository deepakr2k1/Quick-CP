// key observation - 
// white = ∏ all chlid (white+black) ways
// black = ∏ all chlid white ways
// Product is done as child are independent of each other

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
#define MOD              1000000007
// ....................  zero_bug  ....................

vvi adj;
bitset<100005> vis;

pii dfs(int v) {
    vis[v]=1;
    int white=1, black=1;
    for(auto x: adj[v]) {
        if(!vis[x]) {
            pii temp = dfs(x);
            white *= (temp.first+temp.second);
            black *= temp.first;
            white %= MOD;
            black %= MOD; 
        }
    }
    // cout<<white<<" "<<black<<endl;
    return {white, black};
}

void solve() {
    int n;
    cin>>n;
    adj.resize(n+1);
    rep(i,1,n-1) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pii ans = dfs(1);
    cout<< (ans.first + ans.second) % MOD <<endl;
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