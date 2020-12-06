// NOTES:
// 1. std::multiset is an Associative Container that contains a sorted set of duplicate objects of type Key.
// 2. It is usually implemented using Red-Black Tree (AVL).
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in multiset then we will have to provide 
//    compare function so that multiset can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// multiset is similar to set except it can have multiple elements with same value.

#include<bits/stdc++.h>
using namespace std;
int main() {
    multiset<int> ms ={-5,4,2,6,3,4,2,5};
    ms.insert(0);
    for(const auto& x: ms) {
        cout<<x<<" ";
    }
}