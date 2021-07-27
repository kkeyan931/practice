#include <bits/stdc++.h>

using namespace std;

struct edge
{

    int to;
    int weight;

    edge(int to, int weight) : to{to}, weight{weight} {}
};

bool visited[1000] = {false};

int DFS(map<int, list<edge>> &graph,
        int topSortOrdering[], int at, int k)
{
    visited[at] = true;
    auto allEdges = graph[at];
    for (auto &temp : allEdges)
    {
        if (visited[temp.to] == false)
        {
            k = DFS(graph, topSortOrdering, temp.to, k);
        }
    }
    topSortOrdering[k] = at;
    return k - 1;
}

void topSort(map<int, list<edge>> &graph, int topSortOrdering[], int n)
{
    int k = n - 1;
    for (auto &temp : graph)
    {
        if (!graph[temp.first].empty())
        {
            if (visited[temp.first] == false)
            {
                k = DFS(graph, topSortOrdering, temp.first, k);
            }
        }
    }
}

void dagSSSP(map<int, list<edge>> &graph,
             int topSortOrdering[], int dist[], int start, int n)
{

    topSort(graph, topSortOrdering, n);

    dist[start] = 0;

    for (int i = 0; i < n; ++i)
    {

        int nodeIndex = topSortOrdering[i];

        if (dist[nodeIndex] != INT_MAX)
        {

            auto allEdges = graph[nodeIndex];

            if (!allEdges.empty())
            {

                for (auto &node : allEdges)
                {

                    int nodeDistance = dist[nodeIndex] + node.weight;
                    if (dist[node.to] == INT_MAX)
                        dist[node.to] = nodeDistance;
                    else dist[node.to] =  min(dist[node.to],nodeDistance);
                        
                }
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

    cout << endl
         << endl
         << "Enter the start Node" << endl;
    int start;

    cin >> start;

    int topSortOrdering[n];
    int dist[n];
    for(int i=0;i<n;++i){
        dist[i]=INT_MAX;
    }

    dagSSSP(graph, topSortOrdering, dist, start, n);


    for (int i = 0; i < n; ++i)
    {
        cout << topSortOrdering[i] << " ";
    }
    cout << endl;

    cout << endl
         << "SSSP" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}