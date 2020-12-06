#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(int i=a;i>=b;i--)
#define ip(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep
#define int long long int
#define MOD 1000000007
//.............. User: bugger_   (Not to touch) ....................

int getCost(int l,int cut) {
    int small=l/cut;
    int large=((l%cut==0)?small:small+1);
    int cost=small*small*(cut-l%cut);
    cost+=large*large*(l%cut);
    return cost;
}
int getImprovement(int l,int cut) {
    if(cut==l) return 0;
    return (getCost(l,cut)-getCost(l,cut+1));
}
void solve() {
    int n,k;
    cin>>n>>k;
    ip(A,n);
    k-=n;
    int cost=0;
    priority_queue<pair<int,pair<int,int>>> pq;             //  {impro,{len,cuts}}
    rep(i,0,n-1) {
        int improv=getImprovement(A[i],1);
        pq.push({improv,{A[i],1}});
        cost+=A[i]*A[i];
    }
    while(k--) {
        int impro=pq.top().first;
        int len=pq.top().second.first;
        int cuts=pq.top().second.second;
        cost-=impro;                                        // new opt. cut to reduce the max cost
        pq.pop();
        cuts++;
        impro=getImprovement(len,cuts);
        pq.push({impro,{len,cuts}});
    }
    cout<<cost<<endl;
}

int32_t main() {
    FastIO
    solve();
}