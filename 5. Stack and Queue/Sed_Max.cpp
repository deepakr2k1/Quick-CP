// Given an Array of integer find no. of unique difference of max & second_max, over all subarrays
// Key idea is to let the A[i] element is max_element & keep an stack maintaining greater values then A[i]
// while removing element push the A[i]-stack.top() to costs
// Repeat the process for left second_max, and right send_max independently

#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x)           (x).begin(),(x).end()
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// ....................  zero_bug  ....................

void solve() {
    int n;
    cin>>n;
    ip(A, n);
    set<int> costs;
    rep(it,0,1) {
        stack<int> mxx;
        for(auto x: A) {
            while(!mxx.empty() && mxx.top() <= x) {
                costs.insert(x - mxx.top());
                mxx.pop();
            }
            mxx.push(x);
        }
        reverse(all(A));
    }
    cout<<costs.size()<<endl;
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