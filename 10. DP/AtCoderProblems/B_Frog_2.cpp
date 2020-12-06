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
    int n,k;
    cin>>n>>k;
    ip(A,n);
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    rep(i,1,n-1) {
        rep(j,1,k) {
            if(i-j>=0)
                dp[i]=min(dp[i],dp[i-j]+abs(A[i]-A[i-j]));
            else
                break;
        }
    }
    cout<<dp[n-1];
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