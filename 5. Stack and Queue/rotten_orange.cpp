// Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

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
    int r,c;
    cin>>r>>c;
    int M[r][c];
    int T[r][c];
    int V[r][c];
    rep(i,0,r-1) rep(j,0,c-1) cin>>M[i][j];
    queue<pii> Q;
    rep(i,0,r-1) rep(j,0,c-1) {
        if(M[i][j]==2) {
            Q.push({i,j});
            T[i][j]=0;
            V[i][j]=1;
        }
        else if(M[i][j]==1) {
            T[i][j]=INT_MAX;
            V[i][j]=0;
        }
        else {
            T[i][j]=0;
            V[i][j]=0;
        }
    }
    while(!Q.empty()) {
        pii cell=Q.front();
        int i=cell.first,j=cell.second;
        if(i!=0) {
            if(M[i-1][j]==1 && V[i-1][j]==0) {
                Q.push({i-1,j});
                T[i-1][j]=1+T[i][j];
                V[i-1][j]=1;
            }
        }
        if(i!=r-1) {
            if(M[i+1][j]==1 && V[i+1][j]==0) {
                Q.push({i+1,j});
                T[i+1][j]=1+T[i][j];
                V[i+1][j]=1;
            }
        }
        if(j!=0) {
            if(M[i][j-1]==1 && V[i][j-1]==0) {
                Q.push({i,j-1});
                T[i][j-1]=1+T[i][j];
                V[i][j-1]=1;
            }
        }
        if(j!=c-1) {
            if(M[i][j+1]==1 && V[i][j+1]==0) {
                Q.push({i,j+1});
                T[i][j+1]=1+T[i][j];
                V[i][j+1]=1;
            }
        }
        Q.pop();
    }
    int min_time=0;
    rep(i,0,r-1) rep(j,0,c-1) min_time=max(min_time,T[i][j]);
    if(min_time==INT_MAX) {
        cout<<"-1\n";
    }
    else {
        cout<<min_time<<endl;
    }
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