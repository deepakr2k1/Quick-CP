// DP with Bitmasking

#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define vii              vector<int>
#define all(x)           (x).begin(),(x).end()
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define INF              1e18
// .................... User: zero_bug ....................

int N,ans=1;
map<pair<int,int>,int> dp;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

void fun(vector<int>& A, int val,int &bset,int used) {

    if(dp[make_pair(bset,val)] != 0) return;

    if(used == N) {
        ans=max(ans,val);
        return;
    }

    int n=A.size();
    int last = A[n-1];

    if(bset&(1<<(n-1))) {
        A.pop_back();
        fun(A,val,bset,used);
        A.push_back(last);
    } else {
        rep(i,0,n-2) {
            if(!(bset&(1<<i))) {
                bset|=(1<<i);
                bset|=(1<<n-1);
                A[i]+=last;
                A.pop_back();
                used+=2;
                fun(A,gcd(A[i],val),bset,used);
                used-=2;
                bset&=~(1<<i);
                bset&=~(1<<n-1);
                A.push_back(last);
                A[i]-=last;
            }
        }
    }
    dp[make_pair(bset,val)] = ans;
}

int32_t main() {
    FastIO
    cin>>N;
    ip(A,N);
    int bset=0;
    fun(A,0,bset,0);
    cout<<ans<<endl;
}