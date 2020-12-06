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
    int S[n],F[n];
    rep(i,0,n-1) cin>>S[i];
    rep(i,0,n-1) cin>>F[i];
    vector<pair<pair<int,int>,int>> V;
    rep(i,0,n-1) {
        V.push_back({{F[i],S[i]},i+1});
    }
    sort(V.begin(),V.end());
    vector<int> ans;
    int last=-1;
    rep(i,0,n-1) {
        if(last<V[i].first.second) {
            ans.push_back(V[i].second);
            last=V[i].first.first;
        }
    }
    rep(i,0,ans.size()-1) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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