// Kruskal's algorithm to find MST
// insert all nodes into the min Heap as {wt, {u,v}};
// choose an arbitrary vertex & relax all neighbour vertex
// Repeat it till all vertices get selected

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

int n;
vector<vector<pii>> adj;

int primsMST() {
    int mst_wt = 0;
    vi d(n, INF);
    d[0]=0;
    set<pii> S;
    set<int> mst_set;
    rep(i,0,n-1) S.insert({d[i],i});
    
	while(!S.empty()) {
		int v = S.begin() -> second;
        mst_set.insert(v);
        mst_wt += S.begin() -> first;
        
		S.erase(S.begin());
		for(auto x : adj[v]) {
			int u = x.first, w = x.second;
			if(d[u]>w && mst_set.find(u) == mst_set.end()){
				S.erase({d[u], u});
				d[u] = w;
				S.insert({d[u], u});
			}
		}
	}
    return mst_wt;
}

void solve() {
	n=7;
    adj.resize(n);
	adj[1].push_back({6,10});
	adj[6].push_back({1,10});
	adj[6].push_back({5,25});
	adj[5].push_back({6,25});
	adj[5].push_back({0,24});
	adj[0].push_back({5,24});
	adj[4].push_back({0,18});
	adj[0].push_back({4,18});
	adj[5].push_back({4,22});
	adj[4].push_back({5,22});
	adj[3].push_back({4,12});
	adj[4].push_back({3,12});
	adj[2].push_back({3,16});
	adj[3].push_back({2,16});
	adj[2].push_back({0,14});
	adj[0].push_back({2,14});
	adj[1].push_back({2,28});
	adj[2].push_back({1,28});
	cout<<primsMST();
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