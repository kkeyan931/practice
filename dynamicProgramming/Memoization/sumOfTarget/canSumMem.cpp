#include <bits/stdc++.h>

using namespace std;

bool canSum(int target, vector<int> &nums,unordered_map<int,bool> &memo)
{

    if(memo.find(target)!=memo.end()){
        return memo[target];
    }
    else if (target == 0)
    {
        return true;
    }
    else if (target < 0)
    {
        return false;
    }
    for (int i = 0; i < nums.size(); ++i)
    {

        if (nums[i]<=target && (memo[target] = canSum(target - nums[i], nums,memo)))
        {
            return memo[target];
        }
    }
    memo[target] = false;
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

    unordered_map<int,bool>  memo;
    vector<int> nums;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        nums.push_back(k);
    }

    if (canSum(target, nums,memo))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}