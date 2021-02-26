// https://www.spoj.com/problems/DEFKIN/ 
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
    int w,h,n;
    cin>>w>>h>>n;
    int W[n],H[n];
    rep(i,0,n-1) {
        cin>>W[i]>>H[i];
    }
    if(n==0) {
        cout<<h*w<<endl;
        return;
    }
    sort(W,W+n);
    sort(H,H+n);
    int maxW=max(W[0]-1,w-W[n-1]);
    rep(i,0,n-2) maxW=max(maxW,W[i+1]-W[i]-1);
    int maxH=max(H[0]-1,h-H[n-1]);
    rep(i,0,n-2) maxH=max(maxH,H[i+1]-H[i]-1);
    cout<<(maxH*maxW)<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        solve();
    }
}