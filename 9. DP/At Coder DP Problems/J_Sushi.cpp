// Expected no. of moves
// E(x) = P(x)*x
// if we have 'k' states in dp table where one of them can be derived from other k-1 states, then we can remove that particular state
// if dp(i,j) = x*dp(i,j) + y*dp(i-1,j) + z*dp(i,j-1) i.e. dp(i,j) depends on dp(i,j) => self dependency
// then it may be fixed by simple maths => dp(i,j) = ( y*dp(i-1,j) + z*dp(i,j-1) ) / (1-x)

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

double dp[301][301][301];

void solve() {
    int n;
    cin>>n;
    ip(A, n);
    vi cnt(4, 0);
    rep(i,0,n-1) cnt[A[i]]++;
    rep(three, 0, n) {
        rep(two, 0, n) {
            rep(one, 0, n) {
                int zeroes = n-(three + two + one);
                if(zeroes == n) {
                    dp[three][one][two] = 0;
                    continue;
                }
                if(zeroes<0 || zeroes>n) {
                    continue;
                }

                double p0 = (double)zeroes/n, p1 = (double)one/n, p2 = (double)two/n, p3 = (double)three/n;
                dp[three][two][one] = 1;
                if(one>0) dp[three][two][one] += p1*dp[three][two][one-1];
                if(two>0) dp[three][two][one] += p2*dp[three][two-1][one+1];
                if(three>0) dp[three][two][one] += p3*dp[three-1][two+1][one];
                dp[three][two][one] /= (1-p0);
            }
        }
    }
    cout<<setprecision(10)<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;
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