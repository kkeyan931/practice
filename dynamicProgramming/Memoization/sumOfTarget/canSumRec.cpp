#include <bits/stdc++.h>

using namespace std;

bool canSum(int target, vector<int> &nums)
{

    if (target == 0)
    {
        return true;
    }
    else if (target < 0)
    {
        return false;
    }
    for (int i = 0; i < nums.size(); ++i)
    {

        if (nums[i]<=target && canSum(target - nums[i], nums))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    cout << "Enter the Target" << endl;

    int target;
    cin >> target;

    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;

    vector<int> nums;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        nums.push_back(k);
    }

    if (canSum(target, nums))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}