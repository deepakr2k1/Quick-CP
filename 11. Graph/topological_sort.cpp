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

vvi adj;

vi kahnAlgorithm() {
    int n = adj.size(), count=0;
    vi in(n, 0), topo;
    rep(i,0,n-1) {
        for(int x: adj[i]) {
            in[x]++;
        }
    }
    queue<int> Q;
    rep(i,0,n-1) if(in[i]==0) Q.push(i);

    while(!Q.empty()) {
        int u = Q.front();
        topo.push_back(u);
        Q.pop();
        for(int v: adj[u]) {
            in[v]--;
            if(in[v]==0) Q.push(v);
        }
    }
    if(topo.size() != n) {
        cout<<"Cycle exists";
        return {-1};
    }
    return topo;
}

void solve() {
    int n = 6;
    adj.resize(n);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[3].push_back(4);
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[4].push_back(5);

    op(kahnAlgorithm()," ");
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