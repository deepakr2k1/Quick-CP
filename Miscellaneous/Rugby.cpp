// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027
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

//     Sub-problems
// 1. given pts. on a line bring all together at one-pt. (cost=1 to move left/right) 
//     => Median is opt. pt.
// 2. given pts. on a line bring all together in continuous line (cost=1 to move left/right) 
//     => Median is opt. pt. (before X[i]-=i & sort again)

void solve() {
    int n;
    cin>>n;
    vector<int> X(n),Y(n);
    rep(i,0,n-1) cin>>X[i]>>Y[i];
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    rep(i,0,n-1) X[i]-=i;
    sort(X.begin(),X.end());
    int moves=0;
    rep(i,0,n-1) moves+=abs(Y[i]-Y[n/2])+abs(X[i]-X[n/2]);
    cout<<moves<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}