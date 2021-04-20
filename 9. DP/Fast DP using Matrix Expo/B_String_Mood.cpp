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
#define MOD              (int)1e9+7
// ....................  zero_bug  ....................

inline vvi multiply(vvi A, vvi B) {
    int n = A.size(), m = A[0].size(), l = B[0].size();
    vvi C(n, vi(l, 0));
    rep(i,0,n-1) {
        rep(k,0,l-1) {
            rep(j,0,m-1) {
                C[i][k] += A[i][j] * B[j][k];
                C[i][k] %= MOD;
            }
        }
    }
    return C;
}

inline vvi matrixExpo(vvi M, int y) {
    vvi res = {
        {1, 0},
        {0, 1},
    };
    while(y>0) {
        if(y&1) {
            res = multiply(M, res);
        }
        M = multiply(M, M);
        y>>=1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vvi M = {
        {19, 7},
        {6, 20},
    };
    vvi ans = matrixExpo(M, n);
    // rep(i,0,ans.size()-1) {
    //     rep(j,0,ans[0].size()-1) {
    //         cout<<ans[i][j]<<" ";
    //     } cout<<endl;
    // }
    cout<<ans[0][0];
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