#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define all(x)           (x).begin(),(x).end()
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// .................... Author: zero_bug ....................

vi A;
int n,n_blks,blk_sz;

// [l,r] is query range, t is no. of updates occured before this query, indx is index of query used for arranging answer
// lb - block no. of l, rb - block no. of r
struct Query {
    int l, r, t, idx;
    int lb, rb;
};

// ind - index at which update needs to be done, val - new value at ind, prev - old value at ind
struct Update {
    int ind, val, prev;
};

vector<Query> Q;
vector<Update> U;
int l=0, r=-1, sum=0;

inline bool cmp(Query p, Query q) {
    return (p.lb<q.lb) || (p.lb==q.lb && p.rb<q.rb) || (p.lb==q.lb && p.rb==q.rb && p.t<q.t);
}

inline void add(int ind) {
    sum+=A[ind];
}

inline void remove(int ind) {
    sum-=A[ind];
}

inline void doUpdate(int t) {
    if(U[t].ind < l || U[t].ind > r) {
        A[U[t].ind]=U[t].val;
    } else {
        remove(U[t].ind);
        A[U[t].ind]=U[t].val;
        add(U[t].ind);
    }
}

inline void undoUpdate(int t) {
    if(U[t].ind < l || U[t].ind > r) {
        A[U[t].ind]=U[t].prev;
    } else {
        remove(U[t].ind);
        A[U[t].ind]=U[t].prev;
        add(U[t].ind);
    }
}

vi mosAlgorithm() {
    vector<int> answers(Q.size());
    sort(Q.begin(), Q.end(), cmp);
    rep(i,0,Q.size()-1) {
        cout<<Q[i].l<<" "<<Q[i].r<<endl;
    }

    int t=0;
    l=0, r=-1, sum=0;
    for (Query q : Q) {
        while(t < q.t) doUpdate(t++);
        while(t > q.t) undoUpdate(--t);
        while(l > q.l) add(--l);
        while(r < q.r) add(++r);
        while(l < q.l) remove(l++);
        while(r > q.r) remove(r--);
        answers[q.idx] = sum;
        cout<<sum<<" ";
    }
    return answers;
}

void solve() {
    A.clear(),Q.clear(),U.clear();
    A = {1,5,2,4,6,1,3,5,7,12};
    n = A.size(), blk_sz = sqrt(n);
    Q = {{1,3,0}, {0,9,2}, {2,5,2}, {0,8,4}};
    U = {{0,4,1}, {2,15,2}, {5,100,1}, {9,18,12}};
    // Set Prev in Updates while taking input

    rep(i,0,Q.size()-1) {
        Q[i].idx = i;
        Q[i].lb = Q[i].l / blk_sz;
        Q[i].rb = Q[i].r / blk_sz;
    }

    vi ans = mosAlgorithm();
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
    solve();
}