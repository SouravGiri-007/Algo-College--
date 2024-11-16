#include<iostream>
#include<vector>
using namespace std;

void DFS(int node,vector<int>adjlist[],vector<bool>& visited, vector<int>&ans)
{
    visited[node]=1;
    ans.push_back(node);
    for(int j = 0;j<adjlist[node].size();j++){
        if(!visited[adjlist[node][j]]){
            DFS(adjlist[node][j],adjlist,visited,ans);
        }
    }


}
    vector<int>DFSGRAPH(int v,vector<int>adjlist[])
    {
        vector<bool>visited(v,0);
        vector<int>ans;
        DFS(0,adjlist,visited,ans);
        return ans;
    }
int main(){
    int vertex,edges;
    cout<<"enter number of vertex: ";
    cin>>vertex;
    cout<<"enter number of edges: ";
    cin>>edges;
    vector<int>adjlist[vertex];
    int u,v;
    for(int i= 0;i<edges;i++){
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j = 0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<" ";
        }
        cout<< endl;
    }
    vector<int>result = DFSGRAPH(vertex,adjlist);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
