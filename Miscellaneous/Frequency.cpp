#include <bits/stdc++.h> 
using namespace std;
vector<int> frequency(vector<int> V) {
    vector<int> freq;
    int prev=V[0];
    int count=1;
    for(int i=1;i<V.size();i++) {
        if(V[i]==prev) count++;
        else {
            freq.push_back(count);
            count=1;
        }
        prev=V[i];
    }
    freq.push_back(count);
    return freq;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>V,f;
    V.push_back(1);
    V.push_back(2);
    V.push_back(4);
    V.push_back(2);
    V.push_back(2);
    V.push_back(1);
    V.push_back(4);
    V.push_back(1);
    f=frequency(V);
    for(int i=0;i<f.size();i++) {
        cout<<f[i]<<" ";
    }
}