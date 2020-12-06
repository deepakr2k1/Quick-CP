// Find the largest rectangular area possible in a given histogram where the 
// largest rectangle can be made of a number of contiguous bars. 
// For simplicity, assume that all bars have same width and the width is 1 unit.

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

void solve() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int next[n],prev[n];
    stack<int> st; 
    for(int i=0;i<n;i++) {
        while(!st.empty()) {
            if(st.size()==0) break;
            if(arr[st.top()]>=arr[i]) {
                st.pop();
            }
            else break;
        }
        if(st.size()==0) {
            prev[i]=-1;
        }
        else {
            prev[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--) {
        while(!st.empty()) {
            if(st.size()==0) break;
            if(arr[st.top()]>=arr[i]) {
                st.pop();
            }
            else break;
        }
        if(st.size()==0) {
            next[i]=n;
        }
        else {
            next[i]=st.top();
        }
        st.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        ans=max(ans,(next[i]-prev[i]-1)*arr[i]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        solve();
    }
}