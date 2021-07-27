#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> result;
    int low = 0;
    int high = nums.size() - 1;

    if (nums.size() == 0)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    if (nums.size() == 1)
    {
        if (nums[0] == target)
        {
            result.push_back(0);
            result.push_back(0);
            return result;
        }
    }

    int index = -1;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            int start = mid, end = mid;
            while ((start != 0 && nums[start - 1] == target) || (end != nums.size() - 1 && nums[end + 1] == target))
            {
                if (start != 0 && nums[start - 1] == target)
                    start--;
                if (end != nums.size() - 1 && nums[end + 1] == target)
                    end++;
            }
            result.push_back(start);
            result.push_back(end);
            return result;
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
}

int main()
{

    vector<int> vec{5, 7, 7, 8, 8, 10};

    vector<int> result = searchRange(vec, 8);

    for (auto &x : result)
    {
        cout << x << " ";
    }
}