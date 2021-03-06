// Divide & conquer DP
// need to satisfy opt(i,j)<=opt(i,j+1) (monotonocity condition)

// DP[i][k] = min(DP[j][k-1] + cost(j+1, i)) ∀ jϵ[0,i-1]
// The complexity will be O(k*N*logN).

// problem link - https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
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

int n, k;
vvi dp;
vi pSum;

int getCost(int l, int r) {
    if(l==0) return (r+1)*pSum[r];
    return (r-l+1)*(pSum[r]-pSum[l-1]);
}

void divConqDP(int l, int r, int optl, int optr, int curr_k) {
    if(l>r) return; 
    int mid = (l+r)>>1;
    int opt = -1;

    rep(i, optl, min(mid, optr)) {
        int temp_cost = dp[i][curr_k-1] + getCost(i+1, mid);
        if(temp_cost <= dp[mid][curr_k]) {
            dp[mid][curr_k] = temp_cost;
            opt = i;
        }

    }

    divConqDP(l, mid - 1, optl, opt, curr_k);
    divConqDP(mid + 1, r, opt, optr, curr_k);
}

void solve() {
    cin>>n>>k;
    ip(A, n);
    
    dp.resize(n, vi(k+1, INF)), pSum=A;
    rep(i,1,n-1) pSum[i] += pSum[i-1];

    // all person are kept in cell
    rep(i,0,n-1) dp[i][1] = getCost(0, i);

	rep(i,2,k) divConqDP(0, n-1, 0, n-1, i);

	cout << dp[n-1][k] << endl;
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    solve();
}