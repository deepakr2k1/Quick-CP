// Kruskal's algorithm to find MST
// choose an edge having minimum wt. such that it does not form the cycle
// Repeat it till n-1 edges get selected

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

class DisjointSet { 
	int *rank, *parent, n; 
	public:
	DisjointSet(int n) 
	{ 
		rank = new int[n]; 
		parent = new int[n]; 
		this->n = n; 
		makeSet(); 
	} 
	void makeSet() 
	{ 
		for (int i = 0; i < n; i++) { 
			parent[i] = i; 
		} 
	} 
	int find(int x) 
	{
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		} 
		return parent[x]; 
	} 
	void Union(int x, int y) 
	{ 
		int xset = find(x); 
		int yset = find(y); 
		if (xset == yset) 
			return;
		if (rank[xset] < rank[yset]) { 
			parent[xset] = yset; 
		} 
		else if (rank[xset] > rank[yset]) { 
			parent[yset] = xset; 
		}  
		else { 
			parent[yset] = xset; 
			rank[xset] = rank[xset] + 1; 
		} 
	} 
}; 

int n;
vector<pair<int, pii>> edges;

int kruskalMST() {
	sort(all(edges));
	int count=0, mst_wt=0;
	DisjointSet ds(n);
	for(auto it: edges) {
		int u = it.second.first;
		int v = it.second.second;

		int set_u = ds.find(u); 
        int set_v = ds.find(v);

		if(set_u != set_v) {
			mst_wt += it.first;
			ds.Union(u, v);
			if(++count == n-1) return mst_wt;
		}
	}
}

void solve() {
	n=7;
	edges.push_back({10,{1,6}});
	edges.push_back({25,{6,5}});
	edges.push_back({24,{5,0}});
	edges.push_back({18,{4,0}});
	edges.push_back({22,{5,4}});
	edges.push_back({12,{3,4}});
	edges.push_back({16,{2,3}});
	edges.push_back({14,{2,0}});
	edges.push_back({28,{1,2}});
	cout<<kruskalMST();
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