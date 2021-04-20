// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd
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

int n,a,b,ans;
vvi adj;
bitset<500000> vis;
vi disA, disB, curr;

void dfs(int node) {
    vis[node]=1;
    curr.push_back(node);
    disA[node]=1, disB[node]=1;
    for(auto x: adj[node]) {
        if(!vis[x]) dfs(x);
    }
    ans += disA[node]*n + disB[node]*n - disA[node]*disB[node];
    curr.pop_back();
    if(!curr.empty()) {
        if(curr.size()>=a) disA[curr[curr.size()-a]] += disA[node];
        if(curr.size()>=b) disB[curr[curr.size()-b]] += disB[node];
    }
}

void solve() {
    cin>>n>>a>>b;
    adj.clear(), adj.resize(n), vis.reset(), disA.clear(), disB.clear(), disA.resize(n, 0), disB.resize(n, 0), curr.clear();
    rep(i,1,n-1) {
        int x;
        cin>>x;
        --x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    ans = 0;
    dfs(0);
    cout<<(double)ans/(n*n)<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    int t;
    cin>>t;
	cout<<setprecision(9);
	cout<<fixed;
    rep(tt,1,t) {
        cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}