#include <bits/stdc++.h>

using namespace std;

vector<int> *hasSum(int targetSum, vector<int> &nums)
{
    if (targetSum == 0)
    {
        return new vector<int>;
    }
    // else if (targetSum < 0)
    // {
    //     return nullptr;
    // }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] <= targetSum)
        {
            auto vec = hasSum(targetSum - nums[i], nums);
            if (vec != nullptr)
            {
                auto vec1 = new vector<int>;
                vec1->assign(vec->begin(), vec->end());
                vec1->push_back(nums[i]);
                
                delete vec;
                //delete vec1;
                return vec1;
            }
        }
    }
    return nullptr;
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
    // if (vec != nullptr)
    // {
    //     auto p = vec->begin();

    //     cout << *p << endl;
    // }
}