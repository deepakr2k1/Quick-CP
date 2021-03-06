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

int dp[3001][3001][2];

void solve() {
    int n;
    cin>>n;
    ip(A,n);
    rep(i,1,n) {
        rep(j,0,n-1) {
            if(i==1) {
                dp[j][j][0]=0;
                dp[j][j][1]=A[j];
            } else {
                int l=j, r=i+j-1;
                if(r>=n) continue;
                int mx1,mn1;
                mx1=A[l];
                mx1+=dp[l+1][r][0];
                mn1=dp[l+1][r][1];
                int mx2,mn2;
                mx2=A[r];
                mx2+=dp[l][r-1][0];
                mn2=dp[l][r-1][1];
                if(mx1>mx2) {
                    dp[l][r][1]=mx1;
                    dp[l][r][0]=mn1;
                } else {
                    dp[l][r][1]=mx2;
                    dp[l][r][0]=mn2;
                }
            }
        }
    }
    cout<<dp[0][n-1][1]-dp[0][n-1][0]<<endl;
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