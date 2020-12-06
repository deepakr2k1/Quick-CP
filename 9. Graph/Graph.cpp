#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int connected_components;
        int n,m;
        vector<int> E[100001];
        Graph(int nodes,int edges,bool directed) {
            n=nodes;
            m=edges;
            for(int i=0;i<m;i++) {
                int a,b;
                cin>>a>>b;
                E[a].push_back(b);
                if(!directed)
                    E[b].push_back(a);
            }
        }

        vector<int> dfs_order;
        void dfs(int start,bool visit[]) {
            dfs_order.push_back(start);
            visit[start]=true;
            for(int i=0;i<E[start].size();i++) {
                if(visit[E[start][i]]==false) {
                    dfs(E[start][i],visit);
                    // To-do
                }
            }
        }
        void Ddfs() {
            connected_components=0;
            bool visit[n+1]={false};
            for(int i=1;i<=n;i++)
                if(visit[i]==false) {
                    dfs(i,visit);
                    connected_components++;
                }
        }
};
int main()
{
    Graph g(5,3,false);
    g.Ddfs();
    cout<<g.connected_components;
}