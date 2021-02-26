#include<bits/stdc++.h>
using namespace std;

#define lc x<<1
#define rc (x<<1)|1
vector<int> A,ST;
int n;

// indexing for segment-tree is 1-based
void build(int l,int r,int x) {             // O(n) time complexity, O(4n) space complexity
    if(l>r) return;
    if(l==r) {                              // leaf node
        ST[x]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,lc);
    build(mid+1,r,rc);
    ST[x] = max(ST[lc],ST[rc]);
}

// [start,end] is given range, [l,r] is the range for which ans is to be found
int query(int x,int start,int end,int l,int r) {

    if(l>end || r<start)                // Not Overlap
        return INT_MIN;
    
    if(l<=start && r>=end)              // Complete query
        return ST[x];

    int mid = (start+end)/2;            // Partial Overlap
    int left_ans = query(lc,start,mid,l,r);
    int right_ans = query(rc,mid+1,end,l,r);
    return max(left_ans,right_ans);
}

// [start,end] is given range, ind - index, val - value
void update(int x,int start,int end,int ind,int val) {
    if(ind<start || ind>end) return;    //No Overlap

    if(start==end) {                    // Leaf-node
        ST[x]=val;
        return;
    }

    int mid = (start+end)/2;
    update(lc, start, mid, ind, val);
    update(rc, mid+1, end, ind, val);
    ST[x] = max(ST[lc],ST[rc]);
    return;
}

int main() {
    cin>>n;
    A.resize(n);
    ST.resize(4*n);

    for(int i=0;i<n;i++) A[i]=i+1;
    build(0,n-1,1);
    for(int i=0;i<4*n;i++) cout<<i<<" "<<ST[i]<<endl;

    update(1,0,n-1,3,2);

    while(1) {
        int l,r;
        cin>>l>>r;
        cout<<query(1,0,n-1,l,r)<<endl;
    }
}