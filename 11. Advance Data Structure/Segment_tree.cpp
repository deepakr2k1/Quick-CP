#include<bits/stdc++.h>
using namespace std;
void buildSegmentTree(int seg_tree[],vector<int> arr,int start,int end,int index) {             // O(n) time complexity, O(4n) space complexity
    if(start>end) return;

    if(start==end) {                      // leaf node
        seg_tree[index]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildSegmentTree(seg_tree,arr,start,mid,2*index+1);
    buildSegmentTree(seg_tree,arr,mid+1,end,2*index+2);
    seg_tree[index] = min(seg_tree[2*index+1],seg_tree[2*index+2]);
}
int Query(int seg_tree[],int index,int start,int end,int l,int r) {
    if(l>end || r<start)                // Not Overlap
        return INT_MAX;
    
    if(l<=start && r>=end)              // Complete Query
        return seg_tree[index];

    int mid = (start+end)/2;            // Partial Overlap
    int left_ans = Query(seg_tree,2*index+1,start,mid,l,r);
    int right_ans = Query(seg_tree,2*index+2,mid+1,end,l,r);
    return min(left_ans,right_ans);
}
void Update(int seg_tree[],int index,int start,int end,int i,int value) {         //index - tree index, i - arr index
    if(i<start || i>end) return;              //No Overlap

    if(start==end) {                          // Leaf-node
        seg_tree[index]=value;
        return;
    }

    int mid = (start+end)/2;
    Update(seg_tree, 2*index+1, start, mid, i, value);
    Update(seg_tree, 2*index+2, mid+1, end, i, value);
    seg_tree[index] = min(seg_tree[2*index+1],seg_tree[2*index+2]);
    return;
}
int main() {
    int n=6;
    vector<int> V;
    V.push_back(1);
    V.push_back(3);
    V.push_back(2);
    V.push_back(-2);
    V.push_back(4);
    V.push_back(5);
    int seg_tree[4*n];
    // building segment tree
    buildSegmentTree(seg_tree,V,0,n-1,0);
    // for(int i=0;i<4*n;i++) cout<<seg_tree[i]<<" ";
    Update(seg_tree,0,0,n-1,3,2);
    while(1) {
        int l,r;
        cin>>l>>r;
    cout<<Query(seg_tree,0,0,n-1,l,r)<<endl;
    }

}