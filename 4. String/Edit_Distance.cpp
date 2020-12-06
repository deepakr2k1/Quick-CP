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

int editDistance(string s, string t)
{
    int n=s.length();
    int m=t.length();
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++) dp[0][i]=i;
    for(int i=0;i<=n;i++) dp[i][0]=i;
    
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s.at(i-1)==t.at(j-1))
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    
    return dp[n][m];
}

int32_t main() {
    FastIO
    cout<<editDistance("dsfds","sgdhvag");
}