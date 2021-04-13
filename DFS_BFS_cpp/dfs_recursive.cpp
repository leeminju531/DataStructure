#include <vector>
#include <iostream>

using namespace std;



// undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
}
void DFSUtill(int u,vector<int> adj[], vector<bool>& visited)
{
	visited[u] = true;
	cout << u << " ";
	for(int i=0 ; i<adj[u].size() ; i++)
		if(visited[adj[u][i]] == false)
			DFSUtill(adj[u][i] , adj , visited);
}

void DFS(vector<int> adj[], int V)
{
	// allocate V number space and assign false val
	vector<bool> visited(V, false);
	for(int u=0;u<V;u++)
		if(visited[u] == false)
			DFSUtill(u,adj,visited);

}

// Driver code
int main()
{
    int V = 5; // vertex
 
    vector<int> adj[V];
 
    // Vertex numbers should be from 0 to 4.
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);
    return 0;
}