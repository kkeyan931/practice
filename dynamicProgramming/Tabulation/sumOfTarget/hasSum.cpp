#include <bits/stdc++.h>

using namespace std;

int main()
{

    int target;
    cout << "Enter the TargetSum" << endl;
    cin >> target;

    cout << "Enter the size of the array" << endl;

    int n;
    cin >> n;

    cout << "Enter the elements" << endl;
    vector<int> nums;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        nums.push_back(k);
    }

    vector<vector<int> *> table(target + 1, nullptr);

    table[0] = new vector<int>;
    for (int i = 0; i <= target; ++i)
    {
        if (table[i] != nullptr)
        {
            for (auto &num : nums)
            {

                int index = i + num;
                if (index <= target)
                {
                    table[index] = new vector<int>(*table[i]);
                    table[index]->push_back(num);
                }
            }
        }
    }

    if (table[target] != nullptr)
    {
        cout << endl
             << "Possibility is" << endl;
        for (auto p = table[target]->begin(); p != table[target]->end(); ++p)
        {

            cout << *p << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not possible";
        cout <<endl;
    }
}