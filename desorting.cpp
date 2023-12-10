#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int desorting(int *arr, int size)
{
    int min = INT_MAX;
    for (int i = 0; i + 1 < size && min >= 0; ++i)
    {
        if (arr[i] > arr[i + 1])
            return 0;
        int diff = arr[i + 1] - arr[i];
        if (min > diff)
            min = diff;
    }
    if (min < 0)
        return 0;
    return (min / 2) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("desorting.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    for (int i = 0, size; i < cases; ++i)
    {
        cin >> size;
        int *arr = new int[size];
        for (int j = 0; j < size; ++j)
        {
            cin >> arr[j];
        }
        cout << desorting(arr, size) << endl;
        delete[] arr;
    }
    return 0;
}