#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> li;
    li.push_front(100);
    li.push_front(200);
    li.push_front(300);

    li.push_back(1);
    li.push_back(4);
    li.push_back(2);
    li.push_back(12);
    li.push_back(4);

    li.pop_front();
    li.pop_back();

    cout<<li.front()<<endl;
    cout<<li.back()<<endl;
    
    for(auto itr : li) {
        cout<<itr<<" ";
    }
}