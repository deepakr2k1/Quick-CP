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


int bru(int r) {
    // l=1;
    // r=X;
    int cont=0;
    rep(i,1,r) {
        int temp=i;
        bool ans=true;
        int odd=1;
        int prev=-1;
        int dig;
        while(temp>0) {
            dig=temp%10;
            temp=temp/10;
            if(prev!=-1) {
                if(prev==(dig&1)) ans=false;
            }
            prev=dig&1;
        }
        if(ans && (dig&1)==1) {  cont++;}
    }
    return cont;
}

int fun(string &num, int ind, int parity, int tight, int zeroes) {
    // Base Condition
    if(ind == num.size()) {
        if(zeroes) return 0;
        return 1;
    }
    
    // Recursive Case
    int maxx = num.at(ind)-'0';
    int ans = 0;
    if(!tight) {
        int temp=1;
        rep(i,ind,num.size()-1) {
            temp*=5;            
        }
        ans+=temp;
        if(zeroes) ans+=fun(num, ind+1, 1, 0, 1);
    } else {
        if(!zeroes) {
            for(int i=parity; i<=maxx; i+=2) {
                ans += fun(num, ind+1, parity^1, ((i==maxx) ?1 :0), 0);
            }
        } else {
            for(int i=1; i<=maxx; i+=2) {
                ans += fun(num, ind+1, parity^1, ((i==maxx) ?1 :0), 0);
            }
            ans += fun(num, ind+1, 1, 0, 1);
        }
    }
    return ans;
}

void solve() {
    int l, r;
    cin>>l>>r;
    string L=to_string(l-1), R=to_string(r);
    int ans=0;
    ans += fun(R, 0, 1, 1, 1);
    ans -= fun(L, 0, 1, 1, 1);
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
        cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}