#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................
#define MAX 200005
bool visit[MAX+1];

void dfs(vector<vector<int>>& adj,int start) {
    visit[start]=true;
    cout<<start<<" ";
    for(auto x: adj[start]) {
        if(!visit[x]) {
            dfs(adj,x);
            // action to perform
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    rep(i,1,m) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,0,n) visit[i]=false;
    rep(i,1,n) {
        if(!visit[i])
        dfs(adj,i);
    }
}

int32_t main() {
    FastIO
    solve();
}