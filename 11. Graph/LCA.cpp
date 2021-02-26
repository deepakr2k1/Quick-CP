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

#define MAX 100005

vvi adj, sparse;
int N, n, logN, timer=0;
vi parent, depth, in, out, euler_tour, LPOT(MAX);

void dfs(int v) {
    in[v]=timer++;
    euler_tour.push_back(v);
    int max_c_size = 0;
    for (int c : adj[v]) {
        if(parent[c]==-2)
            parent[c]=v;
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            dfs(c);
            euler_tour.push_back(v);
            out[v]=timer++;
        }
    }
}

void preprocess() {
    n = euler_tour.size(), logN = log2(n);

    sparse.clear();
    sparse.resize(n, vi (logN+1));

    rep(i,0,n-1) sparse[i][0] = euler_tour[i];
    rep(j,1,logN) {
        rep(i,0,n-1) {
            int next = i+(1<<(j-1));
            if(next < n) {
                if(depth[sparse[i][j-1]] < depth[sparse[next][j-1]]) {
                    sparse[i][j] = sparse[i][j-1];
                } else {
                    sparse[i][j] = sparse[next][j-1];
                }
            } else {
                sparse[i][j] = sparse[i][j-1];
            }
        }
    }
}

int LCA(int l, int r) {
    l=in[l], r=in[r];
    if(l>r) {
        int temp=l;
        l=r;
        r=temp;
    }
    
    int len = r-l+1;
    int x = LPOT[len];
    if(depth[sparse[l][x]] < depth[sparse[r-(1<<x)+1][x]]) {
        return sparse[l][x];
    } else {
        return sparse[r-(1<<x)+1][x];
    }
}

void solve() {
    int N=9;
    adj.clear(), parent.clear(), depth.clear(), in.clear(), out.clear();
    adj.resize(N), parent.resize(N), depth.resize(N), in.resize(N, -1), out.resize(N, -1);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[5].push_back(1);
    adj[1].push_back(5);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(7);
    adj[7].push_back(4);
    adj[5].push_back(8);
    adj[8].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(5);

    dfs(0);
    preprocess();

    rep(i,0,8) {
        rep(j,0,8) {
            cout<<i<<" "<<j<<" "<<LCA(i,j)<<endl;
        }
    }
}

int32_t main() {
    FastIO
    LPOT[0] = -1, LPOT[1]=0;
    rep(i,2,MAX-1) LPOT[i]=1+LPOT[i>>1];
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    solve();
}