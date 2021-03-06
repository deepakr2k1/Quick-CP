
{\displaystyle F_{kn+c}=\sum _{i=0}^{k}{k \choose i}F_{c-i}F_{n}^{i}F_{n+1}^{k-i}.}
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

// Approximate value of golden ratio
double PHI = 1.6180339;
int f[6] = {0,1,1,2,3,5};

int fib (int n) {
	if (n<6) return f[n];
	int t=5, fn=5;

	while(t<n) {
		fn = round(fn*PHI);
		t++;
	}

	return fn; 
}

void solve() {
    int l;
    cin>>l;
    cout<<fib(l)<<endl;
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