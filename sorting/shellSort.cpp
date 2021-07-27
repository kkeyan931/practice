#include <bits/stdc++.h>

using namespace std;

void shellSort(vector<int> &arr)
{

    int n = arr.size();
    for (int gap = floor(n / 2); gap >= 1; gap = floor(gap / 2))
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i + gap] < arr[i])
                {
                    swap(arr[i], arr[i + gap]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{

    map<int,int> map;

    cout << "Enter number of elements" << endl;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 1000;
    }

    shellSort(arr);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}