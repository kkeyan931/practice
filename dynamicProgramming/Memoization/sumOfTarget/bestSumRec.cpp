#include <bits/stdc++.h>

using namespace std;

vector<int> *hasSum(int targetSum, vector<int> &nums)
{
    if (targetSum == 0)
    {
        return new vector<int>;
    }
    else if (targetSum < 0)
    {
        return nullptr;
    }
    vector<int> *min = nullptr;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] <= targetSum)
        {
            int remainder = targetSum-nums[i];
            auto remainderCombination = hasSum(remainder, nums);
            if (remainderCombination != nullptr)
            {
                auto combination = new vector<int>;
                combination->assign(remainderCombination->begin(), remainderCombination->end());
                combination->push_back(nums[i]);

                if(min == nullptr || combination->size() < min->size()){
                    min = combination;
                }
            }
        }
    }
    return min;
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
    unordered_map<int, vector<int> *> memo;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        nums.push_back(k);
    }

    auto vec = hasSum(target, nums);
    if (vec != nullptr)
    {
        for (auto p = vec->begin(); p != vec->end(); ++p)
        {
            cout << *p << " ";
        }
        delete vec;
    }
    else{
        cout << "nullptr" << endl;
    }
}