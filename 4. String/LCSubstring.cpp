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

void LCStr() {
    int n,m;
    cin>>n>>m;
    string str1,str2,LCS="";
    cin>>str1>>str2;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int maxx=0;
    int idx;
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(str1.at(i-1)==str2.at(j-1))
                dp[i][j]=1+dp[i-1][j-1];
            if(maxx<dp[i][j]) {
                maxx=dp[i][j];
                idx=i-maxx;
            }
        }
    }
    if(maxx!=0) LCS+=str1.substr(idx,maxx);
    cout<<LCS<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        LCStr();
    }
}