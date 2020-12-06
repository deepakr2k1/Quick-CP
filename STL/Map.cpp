// NOTES:
// 1. std::map is associative container that store elements in key value combination
//    where key should be unique, otherwise it overrides the previous value.
// 2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
// 3. It store key value pair in sorted order on the basis of key (assending/decending).
// 4. std::map is generally used in Dictionay type problems.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> mp;
    mp.insert(make_pair("GIT",0));
    mp["Codeforces"]=20;
    mp["Topcoder"]=30;
    mp["Hackerrank"]=5;
    mp["CodeChef"]=10;
    for(auto &x : mp) cout<<x.first<<" "<<x.second<<endl;

}