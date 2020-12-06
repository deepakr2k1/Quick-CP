#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define int long long int
#define MOD 1000000007
//.............. User: bugger_   (Not to touch) ....................

// if i = (a*b) + (c*d) + (e*f) +...
// then, dp[i] stores the minimum value of (a+b+c+d+e+f+...)
// i.e. minimum sum of values used to form that product

#define MAXN 300005
vector<int> dp(MAXN);

void solve() {
    int n,k,x;
    cin>>n>>k>>x;
    (dp[k]<=n) ? cout<<"YES\n" : cout<<"NO\n";
}

int32_t main() {
    FastIO
    
    dp[0]=0;                            // 0 = 0*0 => sum=0
    rep(i,1,MAXN-1) {
        irep(j,sqrt(i),1) {
            if(i%j==0) {
                dp[i]=j+(i/j);          // initialize dp[i] as sum of a+b, such that i=a+b and max(a,b) is minimum possible
                break;
            }
        }
    }
    rep(i,1,MAXN-1) {
        // this is optimization from O(N^2) to O(N*sqrt(N)) 
        // as dp[n]=2*sqrt(n) is initialized and we need opt. it further only
        rep(j,1,2*sqrt(i)) {            
            dp[i]=min(dp[i],dp[j]+dp[i-j]);
        }
    }

    int t;
    cin>>t;
    rep(tt,1,t) {
        solve();
    }
}