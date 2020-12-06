#include<bits/stdc++.h>
using namespace std;

vector<int> Next_largest_element(vector<int> V) {
    stack<pair<int,int> > st;
    vector<int> ans;
    for(int i=V.size()-1;i>=0;i--) {
        while (!st.empty() && V[i]>=st.top().second)            // remove = to make greater equal
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top().first);
        st.push(make_pair(i,V[i]));        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> prev_largest_element(vector<int> V) {
    reverse(V.begin(),V.end());
    stack<pair<int,int> > st;
    vector<int> ans;
    for(int i=V.size()-1;i>=0;i--) {
        while (!st.empty() && V[i]>=st.top().second)
        // remove = to make greater equal
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top().first);
        st.push(make_pair(i,V[i]));        
    }
    for(int i=0;i<V.size();i++) {
        if(ans[i]!=-1) ans[i]=V.size()-1-ans[i];
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> V = {1,3,2,3,4};
    vector<int> ans = Next_largest_element(V);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    ans = prev_largest_element(V);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}