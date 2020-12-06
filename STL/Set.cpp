// NOTES:
// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

#include<bits/stdc++.h>
using namespace std;
class person {
    public:
        int age;
        string name;
    bool operator < (const person& rhs) const {return age<rhs.age; }
    bool operator > (const person& rhs) const {return age>rhs.age; }
};

int main() {
    set<int,greater<>> Set1 = {1,5,3,4,2,1,1,1,2,2,3,4,4,5,5,2};
    for(auto& x: Set1)
        cout<<x<<" ";
        cout<<endl;
    set<person,greater<>> Set2 = {{23,"Rahul"}, {30,"Rohit"}, {15,"john"}};
    for(const auto& y: Set2)
        cout<<y.age<<" "<<y.name<<endl;
}