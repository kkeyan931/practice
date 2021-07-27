#include <iostream>
#include <vector>

using namespace std;

int searchNumOccurrence(vector<int> &V, int k, int start, int end)
{
    if (start > end)
        return 0;
    int mid = (start + end) / 2;
    if (V[mid] < k)
        return searchNumOccurrence(V, k, mid + 1, end);
    if (V[mid] > k)
        return searchNumOccurrence(V, k, start, mid - 1);
    else{
        return mid;
    }
}

int main()
{

    vector<int> vec{5, 7, 7, 8, 10};

    int num = searchNumOccurrence(vec, 10, 0, vec.size());

    cout << num;
}