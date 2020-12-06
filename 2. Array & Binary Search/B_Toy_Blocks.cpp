// https://codeforces.com/contest/1452/problem/B

// Sometime to minimize operation, assume that u can use at most "mid" operations
// and keep continuing binary Search


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
    sort(all(A));
    int sum=0;
    rep(i,0,n-1) sum+=A[i];
    int l=0,r=1e10;
    int k;
    while(l<=r) {
        int mid=(l+r)/2;
        if(A[n-1]>mid) {
            l=mid+1;
        }
        else if(mid*(n-1)<sum) {
            l=mid+1;
        }
        else {
            k=mid;
            r=mid-1;
        }
    }
    cout<<(k*(n-1)-sum)<<endl;
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