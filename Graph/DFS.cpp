#include <bits/stdc++.h>

using namespace std;

struct edge
{

    int to;
    int weight;

    edge(int to, int weight) : to{to}, weight{weight} {}
};


void DFS(map<int,list<edge>> &graph,int at,vector<int> &dfsNodes,int visited[]){

    if(visited[at]==true) return;
    visited[at]=true;

    for(auto &edge : graph[at]){
        DFS(graph,edge.to,dfsNodes,visited);
    }
    dfsNodes.push_back(at);
}

int main()
{

    cout << "Enter the number of nodes " << endl;

    int n;

    cin >> n;

    cout << "Enter the adjacency list" << endl
         << endl
         << endl;

    map<int, list<edge>> graph;

    int node, conNode, toNode, weight;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter Node" << endl;
        cin >> node;
        cout << "Enter number of connected Nodes" << endl;
        cin >> conNode;

        if (conNode == 0)
        {
            graph[node];
            continue;
        }
        cout << "Enter " << conNode << " To Node and weight" << endl;
        for (int j = 0; j < conNode; ++j)
        {
            cin >> toNode;
            cin >> weight;
            graph[node].push_back({toNode, weight});
        }
    }

    vector<int> dfsNodes;
    int visited[n] = {false};
    DFS(graph,0,dfsNodes,visited);

    cout << "DFS of the Graph "<< endl;
    for(auto &x: dfsNodes){
        cout << x << " ";
    }
    cout << endl;

    
}