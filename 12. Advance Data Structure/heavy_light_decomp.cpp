// Heavy Light Decomposition with segment Tree
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

#define lc x<<1
#define rc (x<<1)|1

vvi adj;
vector<int> A, wt, ST;
int n;

// indexing for segment-tree is 1-based
void build(int l,int r,int x) {             // O(n) time complexity, O(4n) space complexity
    if(l>r) return;
    if(l==r) {                              // leaf node
        ST[x]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,lc);
    build(mid+1,r,rc);
    ST[x] = min(ST[lc],ST[rc]);
}

// [start,end] is given range, [l,r] is the range for which ans is to be found
int seg_query(int x,int start,int end,int l,int r) {

    if(l>end || r<start)                // Not Overlap
        return INT_MAX;
    
    if(l<=start && r>=end)              // Complete query
        return ST[x];

    int mid = (start+end)/2;            // Partial Overlap
    int left_ans = seg_query(lc,start,mid,l,r);
    int right_ans = seg_query(rc,mid+1,end,l,r);
    return min(left_ans,right_ans);
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
    ST[x] = min(ST[lc],ST[rc]);
    return;
}

vi parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if(parent[c]==-2)
            parent[c]=v;
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c);
    }
}

int query(int a, int b) {
    int res = INT_MAX;
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = seg_query(1, 0, n-1, pos[head[b]], pos[b]);
        res = min(res, cur_heavy_path_max);
        b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = seg_query(1, 0, n-1, pos[a], pos[b]);
    res = min(res, last_heavy_path_max);
    return res;
}

void init() {
    parent.clear(), depth.clear(), heavy.clear(), head.clear();

    parent = vector<int>(n, -2);
    parent[0]=-1;
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0);
    decompose(0, 0);
}

void solve() {
    adj.clear(), A.clear(), wt.clear(), ST.clear();

    // INPUT
    n=9;
    adj.resize(n), A.resize(n), ST.resize(4*n), wt.resize(n);
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
    wt = {11,2,4,2,3,31,4,7,1};

    // Heavy Light Decomposition(Tree Flattening / Linearize)
    init();

    // build segment tree on HLD 
    rep(i,0,n-1) A[pos[i]] = wt[i];
    build(0,n-1,1);
    
    op(A," ");
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            cout<<i<<" "<<j<<" "<<query(i,j)<<endl;
        }
    }
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