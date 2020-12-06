// NOTES:
// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
//    a. at()
//    b. []
//    c. front()
//    d. back()
//    e. data() // gives access to the underlying array

// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.
// ELEMENT ACCESS
// at(), [], front(), back(), data()
// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include<bits/stdc++.h>
using namespace std;
int main() {
    
    array <int,5> arr;
    arr = {10,40,30,20,-50};
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";

    cout<<endl<<arr[10]<<endl;       //[] safe to use than .at()
    // cout<<arr.at(5);             //Throws Errow/Exception


    vector<int> V;
    V = {10,40,30,20};
    V.push_back(-50);
    for(int i=0;i<V.size();i++) 
        cout<<V[i]<<" ";
    cout<<endl<<V[10]<<endl;
    cout<<V.capacity();         // Total space used by vector
}