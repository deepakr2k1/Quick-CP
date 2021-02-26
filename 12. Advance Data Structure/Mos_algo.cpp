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

struct Query {
    int l, r, idx;
};

inline bool cmp(Query p, Query q) {
    if (p.l / blk_sz != q.l / blk_sz) return q.r>p.r;
    return (p.l / blk_sz & 1) ? (p.r > q.r) : (p.r < q.r);
}

inline void add(int x,int& sum) {
    sum+=x;
}

inline void remove(int x,int& sum) {
    sum-=x;
}

vi mosAlgorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    rep(i,0,queries.size()-1) queries[i].idx = i;
    sort(queries.begin(), queries.end(), cmp);

    int l = 0;
    int r = -1;
    
    int sum=0;
    for (Query q : queries) {
        while (l > q.l) {
            l--;
            add(A[l],sum);
        }
        while (r < q.r) {
            r++;
            add(A[r],sum);
        }
        while (l < q.l) {
            remove(A[l],sum);
            l++;
        }
        while (r > q.r) {
            remove(A[r],sum);
            r--;
        }
        answers[q.idx] = sum;
    }
    return answers;
}

int32_t main() {
    A = {1,5,2,4,6,1,3,5,7,12};
    n = A.size();
    blk_sz = sqrt(n);
    vector<Query> Q = {{1,3},{2,5},{0,8},{7,8}};
    vi ans = mosAlgorithm(Q);
    op(ans," ");
}