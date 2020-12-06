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

void permute(vector<int>& A,int l,int r,int& count) {
    if(l==r) {
        // op(A," ");
        count++;
    }
    else {
        rep(i,l,r) {
            swap(A[i],A[l]);
            permute(A,l+1,r,count);
            swap(A[i],A[l]);
        }
    }
}

void solve() {
    int count=0;
    int n=5;
    vector<int> A(10);
    rep(i,0,n-1) A[i]=i+1;
    permute(A,0,n-1,count);
    cout<<count<<endl;
}

int32_t main() {
    FastIO
    solve();
}