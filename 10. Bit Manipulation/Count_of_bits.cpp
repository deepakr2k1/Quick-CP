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
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................
int countBits(int n) {
    int count=0;
    while(n>0) {
        n=n&(n-1);
        count++;
    }
    return count;
}
int msb(int n) {
    int count=0;
    while(n>0) {
        n=n>>1;
        count++;
    }
    return count-1;
}
void solve() {
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<msb(n)<<endl;
    int mask=n&(~(n-1));            // mask for right most bit => if n=52(110100) => mask=4(000100)
    cout<<mask<<endl;
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