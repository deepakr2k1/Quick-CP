// A Diophantine equation is a polynomial equation, usually in two or more unknowns, 
// such that only the integral solutions are required. An Integral solution is a solution 
// such that all the unknown variables take only integer values.

// Given three integers a, b, c representing a linear equation of the form : ax + by = c. 
// Determine if the equation has a solution such that x and y are both integral values.

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

int gcd_extend(int a,int b,int& x,int& y) 
{ 
	if (b==0) { 
		x=1; 
		y=0; 
		return a; 
	} 
	else { 
		int g=gcd_extend(b,a%b,x,y);
		int x1=x,y1=y;
		x=y1; 
		y=x1-(a/b)*y1; 
		return g; 
	} 
} 

bool print_solution(int a, int b, int c) 
{ 
	int x, y; 
	if (a==0 && b==0) {
		if (c==0) { 
            return true;                        // Infinite solutions
		}
		else {
            return false;                       // No solution
		}
	} 
	int gcd = gcd_extend(a, b, x, y); 
    
	if (c%gcd!= 0) { 
            return false;                       // No solution
	} 
	else {
		cout << "x = " << x * (c / gcd) << ", y = " << y * (c / gcd) << endl;
        return true;
	} 
} 

int32_t main() 
{ 
	int a,b,c;
	a=4; 
	b=18; 
	c=10; 
    
	print_solution(a,b,c); 
	return 0; 
}