// Convex Hull Trick
// dp[i] = max(dp[j-1] + b[j]*a[i]) ∀ jε[1,i-1]
// y = c + m * x

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
    int n;
    cin>>n;
    vi A(n), B(n), dp(n);
    LineContainer CHT;
    rep(i,0,n-1) {
        cin>>A[i]>>B[i];
    }
    dp[0] = A[0]*B[0];
    CHT.add(B[0], 0);
    rep(i,1,n-1) {
        if(i>1) CHT.add(B[i-1], dp[i-2]);
        dp[i] = CHT.query(A[i]);
        dp[i] = max(dp[i], dp[i-1] + A[i]*B[i]);
    }
    op(dp," ");
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