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
#define MOD              1000000007

string num;
int n,d;
int dp[10001][100][2];

int getWays(int ind, int rem, int tight) {
    if(dp[ind][rem][tight] != -1) return dp[ind][rem][tight];
    if(ind == n) return ((rem==0)? 1: 0);
    int maxx = num.at(ind)-'0', ans=0;
    if(!tight) {
        rep(i,0,9) {
            ans += getWays(ind+1, (rem+i)%d, 0);
            ans %= MOD;
        }
    } else {
        rep(i,0,maxx) {
            ans += getWays(ind+1, (rem+i)%d, (i==maxx)? 1: 0);
            ans %= MOD;
        }
    }
    dp[ind][rem][tight] = ans;
    return ans;
}

void solve() {
    cin>>num>>d;
    n=num.size();
    memset(dp, -1, sizeof(dp));
    cout<<(getWays(0, 0, 1)-1+MOD)%MOD;
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