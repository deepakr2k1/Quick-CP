#include <bits/stdc++.h>
using namespace std;
#define int long long int 

#define MAX 100005
#define MOD 1000000009

int Fac[MAX];
int InFac[MAX];

int power(int x,int y)                      // Iterative Function to calculate (x^y)%MOD in O(logy)
{
	int res=1;
	x=x%MOD;
	while (y>0) {
		if(y&1) res=(res*x)%MOD;
		y=y>>1;
		x=(x*x)%MOD;
	}
	return res;
}

int modInverse(int n) {                     // Returns n^(-1) % MOD
	return power(n,MOD-2);
}

void preCompute() {                         // pre-compute the factorial and factorial-inverse of 0...2*10^5 in O(MAX)
	Fac[0]=1;
	for (int i=1;i<MAX;i++)
		Fac[i]=(Fac[i-1]*i)%MOD;
    for(int i=0;i<MAX;i++) 
        InFac[i]=modInverse(Fac[i]);
}

int nCrModPFermat(int n,int r)              // nCr % MOD using Fermat's little theorem in O(1)
{
	if(n<r)
		return 0;
	if(r==0)
		return 1;
	return ((Fac[n] * InFac[r])%MOD * InFac[n-r])%MOD;
}

int32_t main()
{
    preCompute();
    cout<<Fac[6]<<endl;
    cout<<InFac[3]<<endl;
    cout<<power(2,5)<<endl;
    cout<<modInverse(13)<<endl;
    cout<<nCrModPFermat(5,2)<<endl;
}
