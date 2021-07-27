#include <bits/stdc++.h>

using namespace std;

struct edge
{

    int to;
    int weight;

    edge(int to, int weight) : to{to}, weight{weight} {}
};

struct comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void dijkstra(map<int, list<edge>> &graph, int dist[],int prev[], int start, int n)
{

    int visited[n];
    memset(visited, false, sizeof(visited));

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

    pq.push({start, 0});
    dist[start] = 0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        visited[node.first] = true;

        if (dist[node.first] < node.second)
            continue;
        for (auto &edge : graph[node.first])
        {
            if (visited[edge.to] == false)
            {

                int newDist = dist[node.first] + edge.weight;
                if (newDist < dist[edge.to])
                {
                    dist[edge.to] = newDist;
                    prev[edge.to] = node.first;
                    pq.push({edge.to, newDist});
                }
            }
        }
    }
}

void printPath(int prev[],int end){

    for(int at=end;at!=-1;at=prev[at]){

        cout << "<-" << at;
    }
    cout << endl;

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

    int dist[n],prev[n];
    for (int i = 0; i < n; ++i)
    {
        prev[i] = -1;
        dist[i] = INT_MAX;
    }
    dijkstra(graph, dist,prev, start, n);

    cout << endl
         << "SSSP" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << endl <<  endl;


    for(int i=1;i<n;++i){
        printPath(prev,i);
    }
}