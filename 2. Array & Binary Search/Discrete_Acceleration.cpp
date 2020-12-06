#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define irep(i,a,b) for(ll i=a;i>=b;i--)
#define op(V) for(ll _i=0;_i<V.size();_i++) cout<<V[_i]<<" "
#define ip(V,n) vector<double> V(n); for(ll _i=0;_i<n;_i++) cin>>V[_i]
#define ll long long int
#define double long double
#define MOD 1000000007

void solve() {
    double n,max;
    cin>>n>>max;
    ip(d,n);
    vector<double> LT(n),RT(n);

    LT[0]=d[0];
    rep(i,1,n-1) {
        LT[i]=(d[i]-d[i-1])/(i+1);
        LT[i]+=LT[i-1];
    }
    RT[n-1]=max-d[n-1];
    irep(i,n-2,0) {
        RT[i]=(d[i+1]-d[i])/(n-i);
        RT[i]+=RT[i+1];
    }

    double l=0,r=max;
    while(l<r) {
        double mid=(l+r)/2.0;
        double t1,t2;
        auto it = upper_bound(d.begin(),d.end(),mid);

        if(it==d.begin()) {
            t1=mid;
            t2=RT[0]+((d[0]-mid)/(n+1));
        }
        else {
            --it;
            int index = it-d.begin();
            t1=LT[index];
            t1+=(mid-d[index])/(index+2);
            if(index==n-1) {
                t2=max-mid;
            }
            else {
                index++;
                t2=RT[index];
                t2+=(d[index]-mid)/(n-index+1);

            }
        }

        if(abs(t1-t2)<=0.0000005) {
            cout<<fixed<<setprecision(15)<<((t1+t2)/2.0)<<endl;
            return;
        }
        (t1<t2)?l=mid:r=mid;
    }
}

int main() {
    FastIO
    int t;
    cin>>t;
    rep(tt,1,t) {
        solve();
    }
}