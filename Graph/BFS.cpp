#include <bits/stdc++.h>

using namespace std;

struct edge
{

    int to;
    int weight;

    edge(int to, int weight) : to{to}, weight{weight} {}
};

void BFS(map<int, list<edge>> &graph, int at, vector<int> &bfsNodes, bool visited[])
{

    queue<int> queue;
    queue.push(at);
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        bfsNodes.push_back(node);
        for (auto &edge : graph[node])
        {
            if (visited[edge.to] == false){
                queue.push(edge.to);
                visited[edge.to] = true;
            }
        }
    }
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

    vector<int> bfsNodes;

    bool visited[n] = {false};
    BFS(graph, 0, bfsNodes, visited);

    cout << "BFS of the Graph " << endl;
    for (auto &x : bfsNodes)
    {
        cout << x << " ";
    }
    cout << endl;
}