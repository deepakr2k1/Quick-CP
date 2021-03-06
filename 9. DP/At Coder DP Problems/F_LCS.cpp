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
//..............  zero_bug   (Not to touch) ....................

void LCSubseq() {
    int n,m;
    string str1,str2;
    cin>>str1>>str2;
    n=str1.length(),m=str2.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    rep(i,1,n) {
        rep(j,1,m) {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(str1.at(i-1)==str2.at(j-1)) {
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }
        }
    }

    // cout<<dp[n][m]<<endl;

    string LCS="";
    int i=n,j=m;
    while(i>=0 && j>=0) {
        if(dp[i][j]==dp[i][j-1]) {
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]) {
            i--;
        }
        else {
            LCS+=str1.at(i-1);
            if(dp[i][j]==1) break;
            i--;
            j--;
        }
    }
    reverse(LCS.begin(),LCS.end());
    cout<<LCS<<endl;
}

int32_t main() {
    FastIO
    LCSubseq();
}