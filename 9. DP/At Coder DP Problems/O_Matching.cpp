// DP with Bitmasking
// N men, N women we need to find no. of ways to match them so that are compatible with each other
// We can maintain two bitset for Men & women selected, and get ans in O(2^n*2^n) which will give TLE for N=21
// We can do better by one observation,
// Let k be the no. of Setted bits in bitset<21> Women, represents that we have selected 'k' Men & Women
// Mens are from 1 to K, selected Womens are ate setted bits

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
#define MOD              1000000007
// ....................  zero_bug  ....................

int n, women;
int compatible[21][21];
int dp[1<<21];

inline int getWays(int &women, int ind) {
    if(dp[women] != -1) return dp[women];
    if(ind==n) return 1;

    int ans=0;
    rep(x,0,n-1) {
        if(compatible[ind][x] && !(women&(1<<x))) {
            women |= (1<<x);
            ans += getWays(women, ind+1);
            if(ans>=MOD) ans -= MOD;
            women &= ~(1<<x);
        }
    }

    dp[women] = ans;
    return ans;
}

inline void solve() {
    cin>>n;
    rep(i,0,n-1)  rep(j,0,n-1) cin>>compatible[i][j];
    memset(dp, -1, sizeof(dp));
    int women = 0;
    cout<<getWays(women, 0);
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