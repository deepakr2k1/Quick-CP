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
const int MOD = 1e9+7;

int dp[101][100001];
// Recurrence Relation
// dp(n,k) = Σ dp(n-1,k-i) ∀ iϵ[0, A(i)]

void solve() {
    memset(dp, 0, sizeof(dp));
    int n,k;
    cin>>n>>k;
    vi A(n+1);
    rep(i,1,n) cin>>A[i];
    rep(i,0,n) {
        rep(j,0,k) {
            if (j==0) {
                dp[i][j] = 1;
            } else if (i==0) {
                dp[i][j] = 0;
            } else {
                // Without Prefix sum technique => O(K*N^2)
                // rep(x,0,A[i])
                //     if(j-x>=0)
                //         dp[i][j] += dp[i-1][j-x];

                // With Prefix sum technique => O(K*N)
                int l=max((int)0, j-A[i]), r=j;
                dp[i][j] = dp[i-1][r];
                if(l>0) dp[i][j] -= dp[i-1][l-1];
                dp[i][j] = ((dp[i][j] % MOD) + MOD) % MOD;
            }
            if(i>0 && j>0) dp[i][j] += dp[i][j-1];   // Prefix Sum to make solution for O(K*N^2) to O(K*N)
            dp[i][j] %= MOD;
        }
    }
    cout<<dp[n][k]<<endl;
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