#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int pizza_seperation(int *arr, int size)
{
    int min = 361;
    for (int i = 0; i < size; ++i)
    {
        int x = 0;
        int prevdiff = 361;
        for (int j = i; j < size; ++j)
        {
            x += arr[j];
            int diff = abs((2 * x) - 360);
            if (min > diff)
                min = diff;
            if (min == 0)
                return min;
            if (prevdiff < diff)
                break;
            prevdiff = diff;
        }
    }
    return min;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("pizza.txt");
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
        cout << pizza_seperation(arr, size) << endl;
        delete[] arr;
    }
    return 0;
}