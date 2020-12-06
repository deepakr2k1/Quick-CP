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

vector<int> lps(string str) {
    int n=str.length();
    vector<int> LPS(n);
    LPS[0]=0;
    int idx=0;
    rep(i,1,n-1) {
        if(str.at(idx)==str.at(i)) {
            LPS[i]=++idx;
        }
        else {
            if(i==0) LPS[i]=0;
            else if(idx==0) {
                LPS[i]=0;
            }
            else {
                idx=LPS[idx-1];
                i--;
            }
        }
    }
    return LPS;
}

int KMP(string str,string pattern) {
    vector<int> LPS=lps(pattern);
    int n=str.length();
    int m=pattern.length();
    int count=0;

    int idx=-1;
    rep(i,0,n-1) {
        if(str.at(i)!=pattern.at(idx+1)) {
            if(idx!=-1) {
                idx=LPS[idx]-1;
                i--;
            }
        }
        else idx++;
        if(idx==m-1) {
            cout<<i-m+1<<" ";
            count++;
            idx=LPS[idx-1];
        }
    }
    cout<<endl;
    return count;
}

int32_t main() {
    FastIO
    cout<<KMP("abababdbbababd","abab")<<endl;
}