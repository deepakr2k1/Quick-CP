// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a885
// Tree + Segment tree
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

vvi adj;
vi vis, par;
map<pii, int> AA, L;
vector<vector<pii>> Q;
vi ans;

int gcd2(int a, int b) {
    if (b == 0) return a;
    return gcd2(b, a % b);
}
int gcd(int a, int b) {
    if(a==0 || b==0) return 0;
    return gcd2(a, b);
}

#define lc x<<1
#define rc (x<<1)|1
vector<int> ST;

// [start,end] is given range, [l,r] is the range for which ans is to be found
int query(int x,int start,int end,int l,int r) {

    if(l>end || r<start)                // Not Overlap
        return 0;
    
    if(l<=start && r>=end)              // Complete query
        return ST[x];

    int mid = (start+end)/2;            // Partial Overlap
    int left_ans = query(lc,start,mid,l,r);
    int right_ans = query(rc,mid+1,end,l,r);
    return gcd2(left_ans, right_ans);
}

// [start,end] is given range, ind - index, val - value
void update(int x,int start,int end,int ind,int val) {
    if(ind<start || ind>end) return;    //No Overlap

    if(start==end) {                    // Leaf-node
        ST[x]=val;
        return;
    }

    int mid = (start+end)/2;
    update(lc, start, mid, ind, val);
    update(rc, mid+1, end, ind, val);
    ST[x] = gcd2(ST[lc],ST[rc]);
    return;
}

void dfs(int node) {
    vis[node] = 1;
    for(auto x: adj[node]) {
        if(vis[x] == 0) {
            par[x] = node;
            int l = L[{x,par[x]}];
            int a = AA[{x,par[x]}];
            update(1,0,200002,l,a);
            for(auto y: Q[x]) {
                int idx = y.first;
                int qw = y.second;
                ans[idx] = query(1,0,200002,0, qw);
            }
            dfs(x);
            update(1,0,200002,l,0);
        }
    }
}

void solve() {
    int n, q;
    cin>>n>>q;
    adj.clear(), adj.resize(n + 1);
    vis.clear(), vis.resize(n, 0);
    par.clear(), par.resize(n, -1);
    rep(i,0,n-2) {
        int x,y,W,C;
        cin>>x>>y>>W>>C;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        L[{x,y}] = W;
        L[{y,x}] = W;
        AA[{x,y}] = C;
        AA[{y,x}] = C;
    }
    
    ST.clear(), ST.resize(4*200005);
    Q.clear(), Q.resize(n);
    ans.clear(), ans.resize(q);

    rep(i,0,q-1) {
        int node, wt;
        cin>>node>>wt;
        node--;
        Q[node].push_back({i, wt});
    }
    dfs(0);
    op(ans," ");
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
    rep(tt,1,t) {
        cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}