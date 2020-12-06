#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for(ll i=a;i>=b;i--)
#define output(V) for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<" "
#define input(V,n) vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define MOD 1000000007
#define ll long long int
string catalan[101];

string add(string a, string b)
{
    int l1=a.length();
    int l2=b.length();
    if(l1<l2)
    {
        for(int i=0;i<l2-l1;i++)
          a="0"+a;
    }
    else
    {
        for(int i=0;i<l1-l2;i++)
        b="0"+b;
    }
    string res="";
    int carry=0;
    int i=a.length()-1;
    //cout<<i<<endl;
    while(i>=0)
    {

            int d1=a[i]-'0';
            int d2=b[i]-'0';
            //cout<<d1<<" "<<d2<<endl;
           // break;
            int sum=d1+d2+carry;
            //cout<<sum<<endl;
            carry=sum/10;
            int dig=sum%10;
            string x=to_string(dig);
            res+=x;
            //cout<<res<<endl;
        i--;

    }
    if(carry>0)
    {
    string x=to_string(carry);
    res+=x;
    }

    reverse(res.begin(),res.end());

    return res;



}

string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

string rec(int n) {
    if(catalan[n]!="")
        return catalan[n];
    catalan[n]="0";
    for(int i=0;i<=n-1;i++) {
        catalan[n]=add(catalan[n],multiply(rec(i),rec(n-1-i)));
    }
    return catalan[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 //   memset(catalan,"",sizeof(catalan));

 for(int i=0;i<=100;i++)
    catalan[i]="";


    catalan[0]="1";
    catalan[1]="1";
    rec(100);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<catalan[n]<<endl;
    }
}