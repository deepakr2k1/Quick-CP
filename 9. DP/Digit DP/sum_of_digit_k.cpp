// Digit DP
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
// .................... User: zero_bug ....................

int dp[20][200][2];

int fun(int n, int sum) {
    string str = to_string(n) + "_";
    reverse(all(str));
    n=str.length()-1;
    rep(i,1,n) str[i]-='0';
    
    memset(dp, 0, sizeof(dp));
    rep(j,0,sum) {
        if(j<=9) dp[1][j][0]=1;
        else dp[1][j][0] = 0;
        if(j<=str.at(1)) dp[1][j][1]=1;
        else dp[1][j][1] = 0;
    }
    rep(i,2,n) {
        rep(j,0,sum) {
            rep(k,0,9) {                        // Loose Bound i.e. all i digit no. having sum=j
                if(j-k>=0)
                    dp[i][j][0] += dp[i-1][j-k][0];
            }
            int maxx = str.at(i);
            rep(k,0,maxx-1) {                   // Tight Bound
                if(j-k>=0)
                    dp[i][j][1] += dp[i-1][j-k][0];
            }
            if(j-maxx>=0) dp[i][j][1] += dp[i-1][j-maxx][1];      
        }
    }
    return dp[n][sum][1];
}

void solve() {
    cout<<fun(100, 5)<<endl;
    cout<<fun(50, 5)<<endl;
    cout<<fun(49, 5)<<endl;
    cout<<fun(100011, 2)<<endl;
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