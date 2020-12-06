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
#define MOD 1000000007
#define MAX 100005
#define INF 1e18
//.............. User: zero_bug   (Not to touch) ....................
bool cmp(pair<int,int>& a,pair<int,int>& b){
    if (a.first>b.first) {
        return true;
    }
    else if(a.first==b.first) {
        return (a.second<b.second);
    }
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> V;
    rep(i,0,n-1) {
        int id,deadline,profit;
        cin>>id>>deadline>>profit;
        V.push_back({profit,deadline});
    }
    sort(V.begin(),V.end(),cmp);
    set<int> deadline;
    int jobs_done=0,max_profit=0;
    rep(i,0,1000) deadline.insert(i);
    rep(i,0,n-1) {
        auto itr=upper_bound(deadline.begin(),deadline.end(),V[i].second);
        itr--;
        if((*itr)!=0) {
            deadline.erase(*itr);
            jobs_done++;
            max_profit+=V[i].first;
        }
    }
    cout<<jobs_done<<" "<<max_profit<<endl;
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