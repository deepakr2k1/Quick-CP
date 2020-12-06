// In this video we will learn about std::pair.
// NOTES:
// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<char,int>> V;
    V.push_back(make_pair('A',10));
    V.push_back(make_pair('A',29));
    V.push_back(make_pair('B',78));
    V.push_back(make_pair('C',66));
    V.push_back(make_pair('A',22));
    V.push_back(make_pair('B',7));
    for(int i=0;i<V.size();i++)
    cout<<V[i].first<<" "<<V[i].second<<endl;

    cout<<"Sorted Order:\n";
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++)
    cout<<V[i].first<<" "<<V[i].second<<endl;

}