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

void LCStr() {
    string str,LCS="";
    cin>>str;
    int n=str.length();
    int len=0,idx;
    rep(i,0,n-1) {
        int curr_len=0;
        rep(j,0,min(i,n-i-1)) {
            if(str.at(i+j)==str.at(i-j)) {
                if(j==0) curr_len++;
                else curr_len+=2;
                if(curr_len>len) {
                    len=curr_len;
                    idx=i-j;
                }
            }
            else break;
        }
    }
    rep(i,0,n-2) {
        if(str.at(i)==str.at(i+1)) {
            int curr_len=2;
            if(curr_len>len) {
                len=curr_len;
                idx=i;
            }
            rep(j,1,min(n-2-i,i)) {
                if(str.at(i-j)==str.at(i+j+1)) {
                    curr_len+=2;
                    if(curr_len>len) {
                        len=curr_len;
                        idx=i-j;
                    }
                }
                else break;
            }
        }
    }
    LCS=str.substr(idx,len);
    cout<<LCS<<endl;
}

int32_t main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        // cout<<"Case #"<<tt<<":"<<" ";
        LCStr();
    }
}