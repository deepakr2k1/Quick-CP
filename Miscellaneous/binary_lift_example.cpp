// https://codeforces.com/contest/1516/problem/D
// for each i idx[i] store max index upto which it can include,
// if it can include all then idx[i] = INF
// answer each query in [l,r] via making maximum jump

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
#define op2(V,sep)        for(int _i=0;_i<V.size();_i++) {for(int _j=0;_j<V[_i].size();_j++) cout<<V[_i][_j]<<sep; cout<<endl;}
inline void readInt(int &x) {
    bool neg = false;
    register int c;
    x = 0;
    c=getchar();
    if(c=='-') neg = true, c=getchar();
    for(;(c>47 && c<58);c=getchar()) x = (x<<1) + (x<<3) +c -48;
    if(neg) x = -x;
}
// ....................  zero_bug  ....................

#define SIEVE
#define MAX 100005
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
    while (x!=1) { 
        ret.push_back(spf[x]);
        x=x/spf[x];
    } 
    return ret;
}

void solve() {
    FastIO;
    sieve();
    int n,q;
    cin>>n>>q;
    ip(A, n);

    map<int,int> mp;
    vi idx(n, INF);
    irep(i, n-1, 0) {
        vi F = getFactorization(A[i]);
        int prev = -1;
        for(int f: F) {
            if(f != prev) {
                if(mp.find(f) != mp.end())
                    idx[i] = min(idx[i], mp[f]-1);
                mp[f] = i;
            }
            prev = f;
        }
    }
    irep(i, n-2, 0) {
        idx[i] = min(idx[i], idx[i+1]);
    }

    const int LOGN = 20;
    vvi dp(n, vi(LOGN+1, INF));
    rep(j,0,LOGN) {
        rep(i,0,n-1) {
            if(j==0) {
                dp[i][j] = idx[i];
            } else {
                dp[i][j] = dp[i][j-1];
                if(dp[i][j-1]+1 <= n-1)
                    dp[i][j] = dp[dp[i][j-1]+1][j-1];
            }
        }
    }

    while(q--) {
        int L,R;
        cin>>L>>R;
        --L, --R;
        int ans = 0;
        irep(i, LOGN, 0) {
            if(L<=n-1 && dp[L][i] <= R) {
                ans += (1<<i);
                L = dp[L][i] + 1;
            }
        }
        if(L <= R) ans++;
        cout<<ans<<endl;
    }
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