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

#define MAX 100005

vi A, LPOT(MAX);
int n, logN;
vvi sparse;


// query in O(1) if A op A = A (Idempotent)
int query1(int l, int r) {
    int len = r-l+1;
    int x = LPOT[len];
    int ans = min(sparse[l][x], sparse[r-(1<<x)+1][x]);
    return ans;
}

// query in O(logN) for all functions
int query2(int l,int r) {
    int len = r-l+1;
    int ans=INT_MAX;
    while(len>0) {
        int x = LPOT[len];
        ans=min(ans,sparse[l][x]);
        len-=(1<<x);
        l+=(1<<x);
    }
    return ans;
}

void solve() {
    A = {1,4,3,2,7,5,23,4,10,-11};
    n = A.size(), logN = log2(n);
    sparse.resize(n, vi (logN+1, INT_MAX));

    rep(i,0,n-1) sparse[i][0] = A[i];
    rep(j,1,logN) {
        rep(i,0,n-1) {
            int next = i+(1<<j-1);
            if(next < n) {
                sparse[i][j] = min(sparse[i][j-1], sparse[next][j-1]);
            } else {
                sparse[i][j] = sparse[i][j-1];
            }
        }
    }
    
    // rep(i,0,n-1) {
    //     rep(j,0,logN) {
    //         cout<<sparse[i][j]<<" ";
    //     } cout<<endl;
    // }

    cout<<query1(3,9)<<endl;
    cout<<query2(3,9)<<endl;
}

int32_t main() {
    FastIO
    LPOT[0] = -1, LPOT[1]=0;
    rep(i,2,MAX-1) LPOT[i]=1+LPOT[i>>1];
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