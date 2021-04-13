#include <vector>

#include <stack>

#include <iostream>

#include <unordered_map>

#include <queue>

 

using namespace std;

 

 

void addEdge(vector<int> adj[], int u, int v)

{

    adj[u].emplace_back(v);

    adj[v].emplace_back(u);

}

 

void SpecialMovement(int v)

{

    cout << v << " ";

}

 

void dfs(vector<int> adj[],int sv) // start vertex

{

    unordered_map<int,bool> visited;

    visited[sv] = true;

    SpecialMovement(sv);

    

    stack<int> s;

    for(int i=0;i<adj[sv].size() ; i++)

        s.emplace(adj[sv][i]);

    

    while(!s.empty())

    {

        int interested_v;

        interested_v = s.top();

        s.pop(); 

       if(visited[interested_v] != true) // 방문한 적 없으면  

       {

           visited[interested_v] = true; // 방문 기록

           SpecialMovement(interested_v);

           for(int i=0;i<adj[interested_v].size() ; i++)

               if(visited[adj[interested_v][i]] != true)

                   s.emplace(adj[interested_v][i]);

            

       }

 

    }

 

}

void bfs(vector<int> adj[],int sv)

{

    unordered_map<int,bool> visited;

    visited[sv] = true;

    SpecialMovement(sv);

    

    queue<int> q;

    for(int i=0;i<adj[sv].size() ; i++)

        q.emplace(adj[sv][i]);

    

    while(!q.empty())

    {

        int interested_v;

        interested_v = q.front();

        q.pop(); 

       if(visited[interested_v] != true) // 방문한 적 없으면  

       {

           visited[interested_v] = true; // 방문 기록

           SpecialMovement(interested_v);

           for(int i=0;i<adj[interested_v].size() ; i++)

               if(visited[adj[interested_v][i]] != true)

                   q.emplace(adj[interested_v][i]);

            

       }

 

    }

}

int main(void)

{

    int v = 5; // vertex;

    vector<int> adj[v];

    addEdge(adj,0,1);

    addEdge(adj,1,3);

    addEdge(adj,2,0);

    addEdge(adj,2,4);

    

    bfs(adj,0);

    

}