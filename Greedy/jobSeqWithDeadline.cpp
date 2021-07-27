#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int profit;
    int deadline;

    Node(int profit, int deadline) : profit{profit},
                                     deadline(deadline) {}
};

struct comp
{

    bool operator()(const Node &a, const Node &b) const
    {
        return a.profit < b.profit;
    }
};

int main()
{

    priority_queue<Node, vector<Node>, comp> q;

    int n;
    cout << "Enter the number of Jobs" << endl;
    cin >> n;

    cout << "Enter the profit with deadline" << endl;
    int k, k1;
    int max = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        cin >> k1;
        q.push(Node{k, k1});
        if (k1 > max)
        {
            max = k1;
        }
    }
    vector<int> result(max, 0);
    int solution = 0;

    int x=1;
    while (!q.empty())
    {
        auto maxNode = q.top();
        int j = maxNode.deadline-1;
        while (j >= 0)
        {
            if (result[j] == 0)
            {
                result[j] = x;
                solution+=maxNode.profit;
                break;
            }
            else
            {
                j--;
            }
        }
        x++;
        q.pop();
    }

    cout <<"Maximum Profit is : " <<  solution << endl;

    for(auto &x : result){
        cout << "J" << x << " ";
    }
}