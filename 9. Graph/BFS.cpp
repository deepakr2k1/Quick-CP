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
    bool visit[n+1];
    memset(visit,false,sizeof(visit));

    bool isCycle=false;

    queue<int> Q;
    rep(i,1,n) {
        if(!visit[i]) {
            Q.push(i);
            while(!Q.empty()) {
                cout<<Q.front()<<" ";
                visit[Q.front()]=true;
                // action to perform
                for(auto x: adj[Q.front()]) {
                    if(!visit[x])
                        Q.push(x);
                    else isCycle|=(Q.front()!=x);
                }
                Q.pop();
            }
        }
    }
}

int32_t main() {
    FastIO
    solve();
}