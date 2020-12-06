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
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

// 1<=N<=100
// 1<=w<=10^9
// 1<=w[i]<=10^9
// 1<=v[i]<=1000

void solve() {
    int n,w;
    cin>>n>>w;
    int W[n],V[n];
    rep(i,0,n-1) cin>>W[i]>>V[i];
    vector<vector<bool>> dp(n,vector<bool> (100001,false));
    vector<vector<int>> curr(n,vector<int> (100001,0));
    rep(i,0,n-1) {
        dp[i][0]=true;
        curr[i][0]=0;
    }
    rep(i,0,n-1) {
        rep(j,1,100000) {
            if(i==0) {
                if(W[i]<=w && V[i]==j) {
                    dp[i][j]=true;
                    curr[i][j]=W[i];
                }
                continue;
            }
            dp[i][j]=dp[i-1][j];
            curr[i][j]=curr[i-1][j];
            if(j-V[i]>=0) {
                if(dp[i-1][j-V[i]] && (curr[i-1][j-V[i]]+W[i]<=w)) {
                    dp[i][j]=true;
                    curr[i][j]=min(curr[i][j],W[i]+curr[i-1][j-V[i]]);
                    if(curr[i][j]==0) curr[i][j]=W[i]+curr[i-1][j-V[i]];
                }
            }
        }
    }
    irep(i,100000,0) {
        if(dp[n-1][i]) {
            cout<<i<<endl;
            return;
        }
    }
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