#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................
#define MAX 200005
#define MOD 1000000009

int Fac[MAX];
int InFac[MAX];

int power(int x,int y)                      // Iterative Function to calculate (x^y)%MOD in O(logy)
{
    int res=1;
    x=x%MOD;
    while (y>0) {
        if(y&1) res=(res*x)%MOD;
        y=y>>1;
        x=(x*x)%MOD;
    }
    return res;
}

int modInverse(int n) {                     // Returns n^(-1) % MOD
    return power(n,MOD-2);
}

void preCompute() {                         // pre-compute the factorial and factorial-inverse of 0...2*10^5 in O(MAX)
    Fac[0]=1;
    for (int i=1;i<MAX;i++)
        Fac[i]=(Fac[i-1]*i)%MOD;
    for(int i=0;i<MAX;i++)
        InFac[i]=modInverse(Fac[i]);
}

int Rabin_Carp(string text,string pattern) {
    int count=0;
    int n=text.length();
    int m=pattern.length();
    int patt_val=0;
    rep(i,0,m-1) {
        patt_val=(patt_val*10)%MOD;
        patt_val=(patt_val+pattern.at(i)-'a'+1);
    }
    cout<<patt_val<<endl;
    int value=0;
    rep(i,0,n-m-1) {
        if(i<m) {
            value=(value*10)%MOD;
            value=(value+text.at(i)-'a'+1)%MOD;
            continue;
        }
        value=(value-(power(10,m-1)*(text.at(i-m)-'a'+1)%MOD)%MOD);
        value=(value*10)%MOD;
        value=(value+text.at(i)-'a'+1)%MOD;
        value=(value+MOD)%MOD;
        if(value==patt_val) {
            bool isMatch=true;
            rep(j,0,m-1) {
                if(text.at(i-m+1+j)!=pattern.at(j))
                    isMatch=false;
            }
            if(isMatch) count++;
        }
        // cout<<i<<" "<<value<<" "<<count<<endl;
    } 
    return count;
}
int32_t main() {
    FastIO
    preCompute();
    cout<<Rabin_Carp("abcbcbcdcdca","bc");
}