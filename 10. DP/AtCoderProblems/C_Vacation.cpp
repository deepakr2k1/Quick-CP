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
    int n;
    cin>>n;
    int A[n],B[n],C[n];
    rep(i,0,n-1) {
        cin>>A[i]>>B[i]>>C[i];
    }
    vector<vector<int>> dp(n,vector<int> (3));
    dp[0][0]=A[0];
    dp[0][1]=B[0];
    dp[0][2]=C[0];
    rep(i,1,n-1) {
        dp[i][0]=A[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=B[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=C[i]+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
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