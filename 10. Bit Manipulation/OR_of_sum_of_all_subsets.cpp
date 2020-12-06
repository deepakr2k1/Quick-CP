#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define MOD 1000000007
#define MAX 100005
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

void solve() {
    int n;
    cin>>n;
    ip(A,n);
    int dp[50];
    memset(dp,0,sizeof(dp));
    int ans=0;
    rep(i,0,n-1) {
        int temp=A[i];
        int count=0;
        while(temp>0) {
            dp[count]+=(temp&1);
            temp = temp>>1;
            count++;
        }
    }
    rep(i,1,49) {
        dp[i]+=dp[i-1]/2;
    }
    rep(i,0,49) {
        if(dp[i]>0) {
            ans+=(1LL<<i);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}