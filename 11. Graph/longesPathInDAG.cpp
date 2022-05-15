#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define op2(V,sep)       for(int _i=0;_i<V.size();_i++) {for(int _j=0;_j<V[_i].size();_j++) cout<<V[_i][_j]<<sep; cout<<endl;}
#define all(x)           (x).begin(),(x).end()
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define pii              pair<int,int>
#define pip              pair<int, pair<int,int>>
#define ppi              pair<pair<int,int>, int>
#define int             long long

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

inline void readInt(int &x) {bool neg=false;register int c;x = 0;c=getchar();if(c=='-')neg=true,c=getchar();for(;(c>47&&c<58);c=getchar())x=(x<<1)+(x<<3)+c-48;if(neg)x=-x;}

const int INF = (int)1e18;
const int MOD = (int)1e9+7;

int longestPathInDAG(vvi &adj) {
    int n = adj.size(), count=0;
    vi in(n, 0), topo;
    rep(i,0,n-1) {
        for(int x: adj[i]) {
            in[x]++;
        }
    }
    queue<pii> Q;
    int maxLen = 0;
    rep(i,0,n-1) if(in[i]==0) Q.push({i, 1});

    while(!Q.empty()) {
        int u = Q.front().first;
        topo.push_back(u);
        int dis = Q.front().second;
        maxLen = max(maxLen, dis);
        Q.pop();
        for(int v: adj[u]) {
            in[v]--;
            if(in[v]==0) Q.push({v, dis+1});
        }
    }
    if(topo.size() != n) {
        return INF;
    }
    return maxLen;
}

void solve() {
    int n = 6;
    vvi adj(n);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[3].push_back(4);
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[4].push_back(5);
    cout << longestPathInDAG(adj);
}

int32_t main() {
    FastIO
    solve();
}

/*
     0 -> 2
     |
1 -> 3 -> 4 -> 5
|
5
*/