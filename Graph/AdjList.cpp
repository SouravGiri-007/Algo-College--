#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertex, edges;

    cin >> vertex >> edges;

    // Initialize an adjacency list for each vertex

    vector<int> adjlist[vertex];

    int u, v;
   // Input edges and build the adjacency list
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
         // Add the edge to the adjacency list for an undirected graph
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    // Print List

    for (int i = 0; i < vertex; i++)
    {
        cout << i << "->";
        for (int j : adjlist[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
