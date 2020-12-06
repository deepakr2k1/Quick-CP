#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................

// Code Link - https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
#define MAX 200005
int spf[MAX];                           // stores smallest prime factor for every number (spf[prime_no.]=prime_no.)

void sieve()                            // O(nloglogn) 
{ 
	for(int i=1;i<MAX;i++)
		spf[i]=i; 
	for(int i=4;i<MAX;i+=2)
		spf[i]=2; 
	for(int i=3;i*i<MAX;i++) {
		if(spf[i]==i) {
			for (int j=i*i;j<MAX;j+=i)
				if (spf[j]==j) spf[j] = i; 
		} 
	} 
} 

vector<int> getFactorization(int x)     // O(logn)
{ 
	vector<int> ret; 
	while (x!=1) 
	{ 
		ret.push_back(spf[x]); 
		x=x/spf[x];
	} 
	return ret; 
}
//call sieve() in driver code

int32_t main() {
    FastIO
    sieve();
    cout<<spf[12]<<endl;
    vector<int> V=getFactorization(30);
    op(V," ");
}