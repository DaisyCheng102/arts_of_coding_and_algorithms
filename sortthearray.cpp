#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void is_sortable(int *arr, int size)
{
    // l: first index of reversable segment
    // r: last index of reversable segment
    // reversable segment: beginning order of greatest to smallest

    int l = 0;
    for (; l + 1 < size; ++l)
    {
        if (arr[l] >= arr[l + 1])
        {
            break;
        }
    }
    if (l == size - 1)
    {
        cout << "yes\n1 1\n";
        return;
    }

    int r = l + 1;
    for (; r + 1 < size; ++r)
    {
        if (arr[r] < arr[r + 1])
        {
            break;
        }
    }
    // validate l and r
    if ((l - 1 < 0 || arr[r] > arr[l - 1]) // validate left
        && (r + 1 == size || arr[l] < arr[r + 1]))
    {
        for (int i = r + 1; i + 1 < size; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                cout << "no\n";
                return;
            }
        }
        cout << "yes\n"
             << l + 1 << " " << r + 1 << endl;
    }
    else
        cout << "no\n";
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("sortthearray.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;

    for (int i = 0; i < cases; ++i)
    {
        cin >> size;
        int arr[size];
        for (int j = 0; j < size; ++j)
        {
            cin >> arr[j];
        }
        std::cout << "[ ";
        std::copy(arr, arr + size, std::ostream_iterator<int>(std::cout, " "));
        std::cout << "]" << std::endl;
        is_sortable(arr, size);
    }
    return 0;
}