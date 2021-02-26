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
// .................... User: zero_bug ....................

vvi adj;
vi E, in, out; 
vector<bool> visit;
int timer = 0;

void dfs(int v) {
    visit[v] = true;
    in[v]=timer++;
    E.push_back(v);

    for(int x: adj[v]) {
        if(!visit[x]) {
            dfs(x);
        }
    }

    out[v]=timer++;
    E.push_back(v);
}

void solve() {
    adj.clear(), E.clear(), in.clear(), out.clear(), visit.clear(), timer = 0;
    int n = 5;
    adj.resize(n), in.resize(n), out.resize(n), visit.resize(n, false);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(4);
    adj[4].push_back(1);
    
    dfs(0);
    op(E, " ");
    op(in, " ");
    op(out, " ");
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