#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define all(x)           (x).begin(),(x).end()
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// .................... Author: zero_bug ....................

vi A,BIT;
int n;

void update(int ind, int val) {
    ind++; 
    while (ind <= n) { 
        BIT[ind] += val; 
        ind += ind&(-ind); 
    }
}

void build(vi& A) {
    rep(i,0,n-1)
        update(i, A[i]);
}

int query(int ind) 
{ 
    int sum = 0;
    ind++;
    while (ind>0) {
        sum += BIT[ind]; 
        ind -= ind&(-ind); 
    } 
    return sum;
}

int lowerBound(int k) {
    int pos=0, sum=0;
    irep(i,3,0) {
        if(BIT[pos+(1<<i)] + sum < k) {
            pos += (1<<i);
            sum += BIT[pos];
        }
    }
    return pos+1;
    // pos is with respect to BIT(1-based indexing)
}

int32_t main() {
    A = {1,0,2,1,1,3,0,4,2,5,2,2};
    n = A.size();
    BIT.resize(n+1, 0);
    build(A);
    op(BIT," ");
    rep(i,0,n-1) {
        cout<<i+1<<" -> "<<query(i)<<endl;
    }
    cout<<lowerBound(15);
}