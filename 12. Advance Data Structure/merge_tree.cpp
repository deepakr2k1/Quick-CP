// Merge Sort Tree
// https://www.hackerearth.com/challenges/competitive/april-circuits-21/algorithm/smallest-subarray-2-d6530e0b/

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

vector<int> A;
vector<vector<int>> ST;
int n;

#define lc x<<1
#define rc (x<<1)|1

// indexing for segment-tree is 1-based
void build(int l,int r,int x) {             // O(n) time complexity, O(4n) space complexity
    if(l>r) return;
    if(l==r) {                              // leaf node
        ST[x].push_back(A[l]);
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,lc);
    build(mid+1,r,rc);
    int sz = r-l+1;
    ST[x].resize(sz);
    merge(ST[lc].begin(), ST[lc].end(), ST[rc].begin(), ST[rc].end(), ST[x].begin());
}

// [start,end] is given range, [l,r] is the range for which ans is to be found
int query(int x,int start,int end,int l,int r, int val) {

    if(l>end || r<start)                // Not Overlap
        return 0;
    
    if(l<=start && r>=end) {              // Complete query
        auto lb = lower_bound(ST[x].begin(), ST[x].end(), val);
        auto ub = ST[x].end();
        int count = ub-lb;
        return count;
    }
    
    int mid = (start+end)/2;            // Partial Overlap
    int left_ans = query(lc, start, mid, l, r, val);
    int right_ans = query(rc, mid+1, end, l, r, val);
    return (left_ans + right_ans);
}

// [start,end] is given range, ind - index, val - value
void update(int x,int start,int end,int ind,int val) {
    if(ind<start || ind>end) return;    //No Overlap

    if(start==end) {                    // Leaf-node
        ST[x][0] = val;
        return;
    }

    int mid = (start+end)/2;
    update(lc, start, mid, ind, val);
    update(rc, mid+1, end, ind, val);
    int sz = end-start+1;
    ST[x].resize(sz);
    merge(ST[lc].begin(), ST[lc].end(), ST[rc].begin(), ST[rc].end(), ST[x].begin());
    return;
}

void solve() {
    cin>>n;
    A.resize(n);
    rep(i,0,n-1) cin>>A[i];
    ip(B,n);

    ST.resize(4*n);
    build(0,n-1,1);

    rep(i,0,n-1) {
        int ans = -1;
        int l=i, r=n-1, k=B[i];
        while(l<=r) {
            int mid = (l+r)/2;
            if(query(1, 0, n-1, i, mid, A[i]) >= k) {
                ans = mid-i+1;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout<<ans<<" ";
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
    int t=1;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}