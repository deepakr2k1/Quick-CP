#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define MOD 1000000007
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

void solve() {
    int n,m;
    cin>>n>>m;
    string str[n];
    rep(i,0,n-1) cin>>str[i];
    vector<vector<int>> dp(n,vector<int>(m,0));
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(i==0 && j==0) {
                dp[i][j]=1;
            }
            else if(i==0) {
                if(str[i].at(j)=='.')
                    dp[i][j]=dp[i][j-1];
                else   
                    dp[i][j]=0;
            }
            else if(j==0) {
                if(str[i].at(j)=='.')
                    dp[i][j]=dp[i-1][j];
                else   
                    dp[i][j]=0;
            }
            else {
                if(str[i].at(j)=='.')
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                else
                    dp[i][j]=0;
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}

int32_t main() {
    FastIO
    // int t;
    // cin>>t;
    // rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    // }
}