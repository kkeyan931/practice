#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int profit;
    int weight;
    float ratio;
    Node(int profit, int weight, float ratio) : profit{profit},
                                                weight{weight},
                                                ratio{ratio}
    {
    }
};

struct comp{
    bool operator()(const Node &a,const Node &b) const{
        return a.ratio < b.ratio;
    }
};

int main()
{
    int n;

    cout << "Number of object" << endl;
    cin >> n;

    vector<int> profit;

    cout << "Enter the profit of each Item" << endl;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        profit.push_back(k);
    }
    cout << "Enter the weight of each Item" << endl;

    vector<int> weight;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        weight.push_back(k);
    }

    cout << "Enter the Capacity of the Bag" << endl;
    int capacity;
    cin >> capacity;

    priority_queue<Node,vector<Node>,comp> q;
    for (int i = 0; i < n; ++i)
    {
        q.push(Node{profit[i], weight[i], (float)profit[i] / (float)weight[i]});
    }

    float solution = 0;
    while (capacity - q.top().weight >= 0)
    {
        auto max = q.top();
        solution += max.profit;
        capacity -= max.weight;
        q.pop();
    }
    if (capacity != 0)
    {
        auto max = q.top();
        solution += ((float)capacity / (float)max.weight)*(float)max.profit;
    }

    cout << "Maximum Profit is : " << solution << endl;
}