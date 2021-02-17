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
#define MAX 200005
#define MOD 998244353
const int g = 3;

int pot(int b, int p) {
    int res = 1;
    if (p < 0) p += MOD - 1;
    while (p) {
        if (p & 1)(res *= b) %= MOD;
        (b *= b) %= MOD;
        p /= 2;
    }
    return res;
}

int nearestPowerOfTwo(int n) {
    int ans = 1;
    while (ans < n) ans <<= 1;
    return ans;
}

void ntt(vi & X, int inv) {
    int n = X.size();

    for (int i = 1, j = 0; i < n - 1; ++i) {
        for (int k = n >> 1;
            (j ^= k) < k; k >>= 1);
        if (i < j) swap(X[i], X[j]);
    }

    vector < int > wp(n >> 1, 1);
    for (int k = 1; k < n; k <<= 1) {
        int wk = pot(g, inv * (MOD - 1) / (k << 1));

        for (int j = 1; j < k; ++j)
            wp[j] = wp[j - 1] * wk % MOD;

        for (int i = 0; i < n; i += k << 1) {
            for (int j = 0; j < k; ++j) {
                int u = X[i + j], v = X[i + j + k] * wp[j] % MOD;
                X[i + j] = u + v < MOD ? u + v : u + v - MOD;
                X[i + j + k] = u - v < 0 ? u - v + MOD : u - v;
            }
        }
    }

    if (inv == -1) {
        int nrev = pot(n, MOD - 2);
        for (int i = 0; i < n; ++i)
            X[i] = X[i] * nrev % MOD;
    }
}

vi convolution(vi A, vi B) {
    int sz = A.size() + B.size() - 1;
    int size = nearestPowerOfTwo(sz);

    A.resize(size), B.resize(size);
    ntt(A, 1), ntt(B, 1);

    for (int i = 0; i < size; i++)
        A[i] = (int)1 * A[i] * B[i] % MOD;

    ntt(A, -1);
    A.resize(A.size() + B.size() - 1);

    return A;
}


void solve() {
    vi a = {2,3,4,4};
    vi b = {1,4,6,10};
    vi c = convolution(a,b);
    op(c," ");
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
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}