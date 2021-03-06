// Iterative Segment tree is implemented
// Key Concept is that to sort the node {Height, Beauty, index}
// Sorting by H[i] helps us to ensure that is in increasing order
// dp[i] stores the maximum beauty can get if ith element is selected & elements till ith index of original arr is there
// at curr ind, find max dp[0...ind-1] using segment tree,
// and then update the new node

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
// ....................  zero_bug  ....................

int n;
vector<pair<pii, int>> A;
vi dp;

void solve() {
    cin>>n;
    ip(H, n);
    ip(B, n);
    int sz = 1;
    while(sz<n) sz<<=1; sz<<=1;
    dp.resize(sz, 0);
    rep(i,0,n-1) A.push_back({{H[i], B[i]}, i});
    sort(all(A));
    
    rep(i,0,n-1) {
        int prev_max = 0;

        // get max in dp[0...i-1] in prev_max
        if(i!=0) {
            int l=sz-n, r=l+A[i].second;
            while(l<r) {
                if(l&1) {
                    l--;
                    prev_max = max(prev_max, dp[l]);
                }
                if(r&1) {
                    r--;
                    prev_max = max(prev_max, dp[r]);
                }
                l>>=1;
                r>>=1;
            }
        }

        dp[sz-n+A[i].second] = A[i].first.second + prev_max;

        // Update
        int pos = sz-n+A[i].second;
        while(pos>1) {
            pos >>= 1;
            dp[pos] = max(dp[pos<<1], dp[(pos<<1)+1]);
        }
    }
    cout<<*max_element(all(dp))<<endl;
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