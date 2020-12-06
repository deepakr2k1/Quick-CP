// NOTES:
// 1. Multimap is an associative container that contains a sorted list of key-value pairs, 
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We dont have at() and [] functions to get element like we had in std::map.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<string,int> mp;
    mp.insert(make_pair("GIT",10));
    mp.insert(make_pair("GIT",1));
    mp.insert(make_pair("CODE",10));
    mp.insert(make_pair("CODE",20));
    mp.insert(make_pair("KICK",-30));
    mp.insert(make_pair("KICK",10));
    for(auto &x : mp) cout<<x.first<<" "<<x.second<<endl;

    cout << mp.count("GIT") <<endl;

    auto it = mp.find("KICK");
    cout << it->first << " " << it->second <<endl;

}