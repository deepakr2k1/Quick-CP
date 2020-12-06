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
    ip(A,n);
    vector<int> dp(n);
    dp[0]=0;
    dp[1]=abs(A[1]-A[0]);
    rep(i,2,n-1) {
        dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]),dp[i-2]+abs(A[i]-A[i-2]));
    }
    cout<<dp[n-1]<<endl;
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