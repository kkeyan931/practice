#include <bits/stdc++.h>

using namespace std;

bool canSum(int targetSum, vector<int> &nums)
{

    vector<bool> table(targetSum + 1);

    table[0] = true;
    for (int i = 0; i <= targetSum; ++i)
    {
        if (table[i] == true)
        {
            for (auto &num : nums)
            {
                int index = i+num;
                if (index <=targetSum)
                {
                    table[index] = table[i];
                }
            }
        }
    }
    return table[targetSum];
}

int main()
{

    cout << "Enter the TargetSum" << endl;
    int targetSum;
    cin >> targetSum;

    cout << "Enter the number of elements in array" << endl;

    int n;

    cin >> n;
    vector<int> nums;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        nums.push_back(k);
    }

    if (canSum(targetSum, nums))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}