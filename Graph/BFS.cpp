#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFSgraph(int v,vector<int> adjlist[])
{
    queue<int> q;
    vector<bool> visited(v,0);
    q.push(0);
    visited[0]=1;


    vector<int> ans;
    int node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        ans.push_back(node);
        for(int j=0;j<adjlist[node].size();j++)
        {
            if(!visited[adjlist[node][j]])
            {
                visited[adjlist[node][j]]=1;
                q.push(adjlist[node][j]);
            }
        }
    }
    return ans;

}

int main()
{
  int vertex,edges;
  cout<<"Enter the number of vertex: ";
  cin>>vertex;
  cout<<"Enter the number of edges: ";
  cin>>edges;

  vector<int> adjlist[vertex];
  int u,v;
  for(int i=0;i<edges;i++)
  {
    cin>>u>>v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  } 

  for(int i=0;i<vertex;i++)
  {
    cout<<i<<"->";
    for(int j=0;j<adjlist[i].size();j++)
    {
        cout<<adjlist[i][j]<<" ";
    }
    cout<<endl;
  }

  vector<int> result=BFSgraph(vertex,adjlist);

  for(int i=0;i<result.size();i++)
  {
    cout<<result[i]<<" ";
  }

}