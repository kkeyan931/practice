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

    vector<int> table(target + 1);

    table[0] = 1;
    for (int i = 0; i <= target; ++i)
    {
        if (table[i] != 0)
        {
            for (auto &num : nums)
            {
                int index = i + num;

                if (index <=target){
                    table[index] +=1;
                }
            }
        }
    }

    for(auto &x : table){
        cout << x << " ";
    }
    cout << endl;

    cout << "Number of Possibility : " << table[target] << endl;
    
}