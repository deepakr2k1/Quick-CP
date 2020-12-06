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

void solve() {
    int n,W;
    cin>>n>>W;
    int w[n],v[n];
    rep(i,0,n-1) {
        cin>>w[i]>>v[i];
    }
    vector<vector<int>> dp(n,vector<int> (W+1,0));
    rep(i,0,n-1) {
        rep(j,1,W) {
            if(i==0) {
                if(w[i]<=j)
                    dp[i][j]=v[i];
            }
            else if(j>=w[i]) {
                dp[i][j]=max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][W]<<endl;
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