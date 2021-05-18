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
#define int              long long

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
const int MAX = (int)1e6+9;

vvi F(MAX+1);

void precalc() {                        // O(N*logN) 
    // calciulate all factors <= sqrt(MAX)
    rep(i,1,2000) {
        int j = i;
        while(j<=MAX) {
            F[j].push_back(i);
            j += i;
        }
    }
    
    // calciulate all factors > sqrt(MAX)
    rep(i,1,MAX) {
        int last = *F[i].rbegin();
        irep(k,F[i].size()-1, 0) {
            int f = i/F[i][k];
            if(f > F[i][k] && f>last) {
                F[i].push_back(f);
            }
        }
    }
}

void solve(int x) {
    dbg(F[x]);
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    precalc();
    solve(1000000);
    solve(45);
    solve(999999);
}