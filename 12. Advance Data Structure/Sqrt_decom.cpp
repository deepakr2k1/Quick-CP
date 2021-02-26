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

vi A,B;
int n,n_blks,blk_sz;

// Build Decomposed Array
void preCompute() {
    B.resize(n_blks, 0);
    
    int blk_ind = -1;
    rep(i,0,n-1) {
        if (i%blk_sz == 0) blk_ind++;
        B[blk_ind] += A[i];
    }
}

int query(int l, int r) {
    int sum = 0; 
    while (l<=r && l%blk_sz!=0) {
        sum += A[l];
        l++; 
    }
    while (l+blk_sz <= r) {
        sum += B[l/blk_sz];
        l += blk_sz;
    } 
    while (l<=r) { 
        sum += A[l];
        l++; 
    } 
    return sum; 
}

void update(int ind, int val) {
    // It can also be updated in O(1)
    A[ind]=val;
    int blk_ind = ind/blk_sz;
    B[blk_ind] = 0;
    rep(i,blk_ind*blk_sz,min((blk_ind+1)*blk_sz-1,n-1)) {
        B[blk_ind]+=B[i];
    }
}

int32_t main() {
    A = {1,5,2,4,6,1,3,5,7,12};
    n = A.size();
    n_blks = sqrt(n);
    blk_sz = (n + n_blks-1) / n_blks;
    preCompute();
    cout<<query(1,7)<<endl;
    update(5,12);
    cout<<query(1,7)<<endl;
}