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
#define op2(V,sep)        for(int _i=0;_i<V.size();_i++) {for(int _j=0;_j<V[_i].size();_j++) cout<<V[_i][_j]<<sep; cout<<endl;}
inline void readInt(int &x) {
    bool neg = false;
    register int c;
    x = 0;
    c=getchar();
    if(c=='-') neg = true, c=getchar();
    for(;(c>47 && c<58);c=getchar()) x = (x<<1) + (x<<3) +c -48;
    if(neg) x = -x;
}
// ....................  zero_bug  ....................

int moves[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

vvi bfs(pii start, vvi &A) {
    int n=A.size(), m=A[0].size();
    int i=start.first, j=start.second, dis=A[i][j];
    vvi d(n, vi (m, INF));
    vvi vis(n, vi(m, 0));
    vis[i][j]=1;

    queue<pair<int,pii>> Q;
    Q.push({0, {i, j}});
    while(!Q.empty()) {
        pair<int,pii> front = Q.front();
        i=front.second.first, j=front.second.second, dis=front.first;
        d[i][j] = dis;
        rep(k,0,3) {
            int x1 = i+moves[k][0], y1 = j+moves[k][1];
            if(x1<0 || x1>=n || y1<0 || y1>=m) continue;
            if(A[x1][y1] == -1) continue;
            if(vis[x1][y1] == 1) continue;
            Q.push({dis+1, {x1, y1}});
            vis[x1][y1]=1;
        }
        Q.pop();
    }
    return d;
}

void solve() {
    int n,m,w;
    cin>>n>>m>>w;
    vvi A(n, vi(m));
    rep(i,0,n-1) rep(j,0,m-1) cin>>A[i][j];
    vvi S_cost(n, vi(m, INF));

    vvi d1 = bfs({0,0}, A);
    vvi d2 = bfs({n-1,m-1}, A);

    int cost = INF;
    if(d1[n-1][m-1] != INF) {
        cost = min(cost, d1[n-1][m-1]*w);
    }
    int S = INF, E = INF;
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(A[i][j] >= 1) {
                if(d1[i][j] != INF)
                    S = min(S, d1[i][j]*w + A[i][j]);
                if(d2[i][j] != INF)
                    E = min(E, d2[i][j]*w + A[i][j]);
            }
        }
    }
    cost = min(cost, S+E);
    if(cost>=INF) cost=-1;
    cout<<cost<<endl;
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