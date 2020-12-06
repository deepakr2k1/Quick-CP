#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define pii pair<int,int>
#define int long long int
#define MOD 1000000007
#define MAX 100005
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

void solve() {
    int n;
    cin>>n;
    ip(A,n);
    if(n==1) {
        cout<<"0\n";
        return;
    }
    if(A[0]==0) {
        cout<<"-1\n";
        return;
    }
    int reach=A[0];
    int jumps=1;
    int steps=A[0];
    rep(i,1,n-1) {
        if(i==n-1) {
            cout<<jumps<<endl;
            return;
        }
        reach=max(reach,A[i]+i);
        steps--;
        if(steps==0) {
            jumps++;
            steps=reach-i;
            if(steps<=0) {
                cout<<"-1\n";
                return;
            } 
        }
    }
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