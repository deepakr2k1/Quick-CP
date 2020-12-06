#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(ll i=a;i>=b;i--)
#define output(V) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<" "
#define input(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define MOD 1000000007
#define ll long long int
ll catalan[101];
ll rec(int n) {
    if(catalan[n]!=-1)
        return catalan[n];
    catalan[n]=0;
    for(int i=0;i<=n-1;i++) {
        catalan[n]+=rec(i)*rec(n-1-i);
    }
    return catalan[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(catalan,-1,sizeof(catalan));
    catalan[0]=1;
    catalan[1]=1;
    rec(100);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<catalan[n]<<endl;
    }
}