// Digit DP
// sum of digit is divisible by k and number also divible by k
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
// .................... User: zero_bug ....................

vector<vector<vector<vector<int>>>> dp;
int k;

int fun(string &str, int ind, int rem, int sum, int tight) {
	if(dp[ind][rem][sum][tight] != -1) 
		return dp[ind][rem][sum][tight];
	
	if(ind == str.size()) {
		if(sum%k==0 && rem==0) return 1;
		else return 0;
	}

	int maxx = str.at(ind)-'0';
	int ans=0;
	int dig_no = pow(10, str.size()-ind);
	if(!tight) {
		rep(i,0,9)
			ans += fun(str, ind+1, (rem+i*dig_no)%k, (sum+i)%k, 0);
	} else {
		rep(i,0,maxx)
			ans += fun(str, ind+1, (rem+i*dig_no)%k, (sum+i)%k, (i==maxx? 1: 0));
	}

	dp[ind][rem][sum][tight] = ans;
	return ans;
}

void solve() {
	int l,r;
	cin>>l>>r>>k;
	string L = to_string(l-1), R = to_string(r);

	dp.clear();
	dp.resize(R.size()+2, vector<vector<vector<int>>> (k+1, vector<vector<int>> (9*(R.size()+1),vi(2, -1))));
	int ans = fun(R, 0, 0, 0, 1);
	dp.clear();
	dp.resize(L.size()+2, vector<vector<vector<int>>> (k+1, vector<vector<int>> (9*(L.size()+1),vi(2, -1))));
	ans -= fun(L, 0, 0, 0, 1);
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
	int t;
	cin>>t;
	rep(tt,1,t) {
		cout<<"Case "<<tt<<":"<<" ";
		solve();
	}
}