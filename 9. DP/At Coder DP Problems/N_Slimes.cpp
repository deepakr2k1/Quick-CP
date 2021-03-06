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

int dp[401][401];
// dp(i,j) = min(dp(i,x) + dp(x,j)) ∀ xϵ[i,j] + ∑A[x] ∀ xϵ[i,j]
// T(n) = O(N^2)
// This problem is similar to matrix chain multiplication

vi sum(401, 0);
inline int getSum(int l, int r) {
    if(l==0) return sum[r];
    return sum[r]-sum[l-1];
}

void solve() {
    int n;
    cin>>n;
    ip(A,n);
    
    sum=A;
    rep(i,1,n-1) sum[i]+=sum[i-1];

    rep(len,1,n) {
        for(int l=0, r=l+len-1; r<n; l++, r++) {
            if(len==1) {
                dp[l][r]=0;
                continue;
            }
            
            dp[l][r] = INF;
            rep(x,l,r-1) {
                dp[l][r] = min(dp[l][r], dp[l][x] + dp[x+1][r] + getSum(l,r));
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
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