#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int flag = 0;
        for (int j = 0; j < arr.size() - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{

    cout << "Enter number of elements" << endl;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 100;
    }

    bubbleSort(arr);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
