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
// Merging two sorted array in O(1) extra space, 
// and in O((m+n)*log(m+n)) time

void solve() {                      
    int n,m;
    cin>>n>>m;
    int A[n],B[m];
    rep(i,0,n-1) cin>>A[i];
    rep(i,0,m-1) cin>>B[i];
    int gap=m+n;
    
    while(gap>1) {
        gap=(gap+1)/2;
        rep(i,0,m+n-1-gap) {
            int l=i,r=i+gap;
            if(l>=n) {
                l-=n;
                r-=n;
                if(B[l]>B[r]) {
                    int temp=B[l];
                    B[l]=B[r];
                    B[r]=temp;
                }
            }
            else if(r>=n){ 
                r-=n;
                if(A[l]>B[r]) {
                    int temp=A[l];
                    A[l]=B[r];
                    B[r]=temp;
                }
            }
            else {
                if(A[l]>A[r]) {
                    int temp=A[l];
                    A[l]=A[r];
                    A[r]=temp;
                }
            }
        }
        rep(i,0,n-1) cout<<A[i]<<" ";cout<<endl;
        rep(i,0,m-1) cout<<B[i]<<" ";cout<<endl;
    }
}

int32_t main() {
    FastIO
    solve();
}