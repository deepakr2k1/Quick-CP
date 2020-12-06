#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define MOD 1000000007
#define MAX 100005
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

int merge(vector<int>& A,int l,int r,int mid) {
    int count=0;
    vector<int> temp;
    int p1=l,p2=mid+1;
    while(p1<=mid && p2<=r) {
        if(A[p1]>A[p2]) {
            temp.pb(A[p2]);
            count+=mid-p1+1;
            p2++;
        }
        else {
            temp.pb(A[p1]);
            p1++;
        }
    }
    while(p1<=mid) {
        temp.pb(A[p1]);
        p1++;
    }
    while(p2<=r) {
        temp.pb(A[p2]);
        p2++;
    }
    rep(i,0,temp.size()-1) {
        A[i+l]=temp[i];
    }
    return count;
}

int inv_count(vector<int>& A,int l,int r) {
    if(l==r) return 0;
    int mid=(l+r)/2;
    int count=0;
    count+=inv_count(A,l,mid);
    count+=inv_count(A,mid+1,r);
    count+=merge(A,l,r,mid);
    return count;
}

void solve() {
    int n;
    cin>>n;
    ip(A,n);
    cout<<inv_count(A,0,n-1)<<endl;
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