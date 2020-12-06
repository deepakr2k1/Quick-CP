#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define int long long int
#define pii pair<int,int>
#define MOD 1000000007
#define INF 1e18
#define MAX 100000
//.............. User: zero_bug   (Not to touch) ....................

// given a 2D matrix choose a element for each row and
// minimize the difference b/w max and min of all chosen elemenet
// 10 12 14 16 18
// 23 14 15 17 24
// 13 87 45 91 11
// 12 20 23 11 19
// opt. sel(may be) 12,12,14,11,11 => diff= 14-11= 3(minimized)

void solve() {
    ip(A,6);
    int n;
    cin>>n;
    ip(B,n);
    int V[n][6];
    set<pii> st;
    rep(i,0,n-1) {
        rep(j,0,5) {
            st.insert(make_pair(B[i]-A[j],i));
        }
    }
    int count[n];
    memset(count,0,sizeof(count));
    int unique = 0;
    int ans=INT_MAX;
    auto l = st.begin();
    auto r = st.begin();
    count[(*r).second]++;
    unique++;
    while(l!=st.end()) {
        while(unique<n) {
            if(r==st.end())
                break;
            ++r;
            if(r==st.end())
                break;
            if(count[(*r).second]==0) unique++;
            count[(*r).second]++;
        }
        if(unique==n) {
            ans=min(ans,(*r).first-(*l).first);
        }
        if(count[(*l).second]==1) unique--;
        count[(*l).second]--;
        ++l;
    }
    cout<<ans<<endl;
}

int32_t main() {
    FastIO
    solve();
}