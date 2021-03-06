// CHT wiith different implementation

// Different implementation of Convex hull Trick
// dp[i] = max(dp[j]+ X[i]*Y[i] - X[j]*Y[i] - c)
// y = dp[i]
// c = dp[j] (X[i][i] - c : It is already included in dp[i])
// m = X[j]
// x = Y[i]
// dp[i] = x*y - c + CHT.query(-y);
// CHT.add(x, dp[i]);

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
 
struct Line {
	mutable int m, c, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(int x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	int div(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }
 
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = INF, 0;
		if (x->m == y->m) x->p = x->c > y->c ? INF : -INF;
		else x->p = div(y->c - x->c, x->m - y->m);
		return x->p >= y->p;
	}
 
	void add(int m, int c) {
		auto z = insert({m, c, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
 
	int query(int x) {
		auto l = *lower_bound(x);
		return l.m * x + l.c;
	}
};

int n;

void solve() {
    cin>>n;
    vector<vi> A(n, vi(3));
    rep(i,0,n-1) {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
    }
    sort(all(A));

    LineContainer CHT;
    vi dp(n);
    CHT.add(0,0);   // This is as none in between is added
    dp[0] = A[0][0]*A[0][1]-A[0][2];
    CHT.add(A[0][0] ,dp[0]);
    int ans = dp[0];
    rep(i,1,n-1) {
        dp[i] = A[i][0] * A[i][1] - A[i][2] + CHT.query(-A[i][1]);
        CHT.add(A[i][0], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
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