// 1d-1d-DP-optimization
// need to satisfy k(i)<=k(i+1) (derived from of quadrangle inequality)

// DP[i] = min(DP[j] + cost(j+1, i)) ∀ jϵ[0,i-1]
// This can be solved in O(n*logn)

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

// Given two arr A[], B[] in inc. & dec. order respectively
// You have to divide the arr int some contiguous segments, find minimum sum of cost of segments
// if cost of segment is max(Ai)*max(Bi)

int n;
vi A, B, dp;

int getCost(int l, int r) {
    return A[r]*B[l];
}

void DP_1d_1d() {
    dp.resize(n+1, (int)0);

    vector<pii> k_arr; // start pos, best-k
    k_arr.push_back({(int)0, (int)0});

    rep(i,1,n) {
        // find dp[x]
        int k = (--lower_bound(all(k_arr), mp(i+1, (int)0)))->second;
        dp[i] = dp[k] + getCost(k+1, i);

        // update the segments
        irep(j, k_arr.size()-1, 0) {
            int y = k_arr[j].first, old_k = k_arr[j].second;

            if(y>i && dp[i]+getCost(i+1, y) < dp[old_k]+getCost(old_k+1, y)) {
                k_arr.pop_back();
            } else {
                int l=y+1, r=n+1;
                while(l<r) {
                    int mid = (l+r)/2;
                    if(dp[i]+getCost(i+1, mid) <= dp[old_k]+getCost(old_k+1, mid)) {
                        r=mid;
                    } else {
                        l=mid+1;
                    }
                }
                if(r!=n+1) k_arr.push_back({r, i});
                break;
            }
        }
        if(k_arr.size() == 0)
            k_arr.push_back({(int)0, i});
    }
}

void solve() {
    cin>>n;
    A.resize(n+1, INF), B.resize(n+1, INF);
    rep(i,1,n) cin>>A[i];
    rep(i,1,n) cin>>B[i];
    
    DP_1d_1d();
    cout<<dp[n]<<endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | nCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    solve();
}