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

void solve() {
    int n;
    cin>>n;
    priority_queue<int> maxPq;
    priority_queue<int,vector<int>,greater<int>> minPq;
    rep(i,0,n-1) {
        int x;
        cin>>x;
        if(i==0) {
            maxPq.push(x);
            cout<<x<<" ";
            continue;
        }
        
        if(minPq.size()==maxPq.size()) {
            if(x>maxPq.top()) {
                int top=minPq.top();
                minPq.pop();
                minPq.push(x);
                maxPq.push(top);
            }
            else {
                maxPq.push(x);
            }
            cout<<maxPq.top()<<" ";
        }
        else {
            if(x>maxPq.top()) minPq.push(x);
            else {
                int top=maxPq.top();
                maxPq.pop();
                maxPq.push(x);
                minPq.push(top);
            }
            cout<<((float)((float)maxPq.top()+(float)minPq.top())/2)<<" ";
        }
    }
}

int32_t main() {
    FastIO
    solve();
}