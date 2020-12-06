// NOTES:
// 0. std::priority_queue is a container adaptor that provides constant time lookup of the 
//    largest OR smallest element.
// 1. By default std::vector is the container used inside.
// 2. Cost of insertion and extraction is logarithmic.
// 3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

#include<bits/stdc++.h>
using namespace std;
template<typename T> void print(T& q) {
    while(!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    priority_queue<int> q;                              //max on top
    for(int i : {2,4,3,5,2,5,6,56,67,23,5})         
        q.push(i);
    print(q);

    priority_queue<int,vector<int>,greater<int>> q2;
    for(int i : {2,4,3,5,2,5,6,56,67,23,5})
        q2.push(i);
    print(q2);

    auto cmp = [](int left, int right) {
        return abs(left) < abs(right) ; 
    };
    priority_queue<int,vector<int>,decltype(cmp)> q3(cmp);

    for(int i : {2,4,3,5,-2,5,6,-56,67,-23,5})
        q3.push(i);
    print(q3);
}