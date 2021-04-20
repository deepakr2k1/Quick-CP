// https://codeforces.com/contest/1514/problem/D
// Mo's algo example finding feq of mod in [l,r]
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
#define INF              1e18
inline void readInt(int &x) {
    bool neg = false;
    register int c;
    x = 0;
    c=getchar();
    if(c=='-') neg = true, c=getchar();
    for(;(c>47 && c<58);c=getchar()) x = (x<<1) + (x<<3) +c -48;
    if(neg) x = -x;
}
// .................... Author: zero_bug ....................

#define MAX (int)3e5+5
int A[MAX], F[MAX]={0}, FF[MAX]={0};
const int blk_sz = 600;
int mod_f;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / blk_sz, r) < make_pair(other.l / blk_sz, other.r);
    }
};

inline void add(int x) {
    if(F[x]>0) FF[F[x]]--;
    F[x]++;
    FF[F[x]]++;
    mod_f = max(mod_f, F[x]);
}

inline void remove(int x) {
    if(F[x]>0) FF[F[x]]--;
    F[x]--;
    FF[F[x]]++;
    if(FF[mod_f] == 0) {
        mod_f = F[x];
    }
}

void mosAlgorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    rep(i,0,queries.size()-1) queries[i].idx = i;
    sort(queries.begin(), queries.end());

    int l = 0;
    int r = -1;
    for (Query q : queries) {
        while (l > q.l) {
            l--;
            add(A[l]);
        }
        while (r < q.r) {
            r++;
            add(A[r]);
        }
        while (l < q.l) {
            remove(A[l]);
            l++;
        }
        while (r > q.r) {
            remove(A[r]);
            r--;
        }
        int x = mod_f;
        int y = q.r - q.l + 1 - x;
        answers[q.idx] = max((int)1, 1+x-(y+1));
    }
    op(answers,"\n");
}

int main() {
    FastIO;
    int n,q;
    readInt(n);
    readInt(q);
    rep(i,0,n-1) readInt(A[i]);
    vector<Query> Q;
    while(q--) {
        int l,r;
        readInt(l);
        readInt(r);
        Q.push_back({l-1,r-1});
    }
    mosAlgorithm(Q);
}