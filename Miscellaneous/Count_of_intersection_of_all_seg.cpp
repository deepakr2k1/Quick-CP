// Count of number of intersection of all segment

#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define vii              vector<int>
#define all(x)           (x).begin(),(x).end()
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// .................... User: zero_bug ....................

void solve() {
    int n;
    cin>>n;
    vector<pii> V;
    vii l,r;
    rep(i,0,n-1) {
        int x,y;
        cin>>x>>y;
        V.push_back({x,y});
        l.push_back(x);
        r.push_back(y);
    }
    sort(all(l));
    sort(all(r));
    vii intersect(n);
    rep(i,0,n-1) {
        int gre=n-(upper_bound(all(l),V[i].second)-l.begin());
        int less=(lower_bound(all(r),V[i].first)-r.begin());
        intersect[i]=n-gre-less;
    }
    int ans=n;
    cout<<ans-*max_element(all(intersect))<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}