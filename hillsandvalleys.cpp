#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int is_intimidate(int *arr, int i)
{
    if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        return 1;
    else if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
        return -1;
    else
        return 0;
}
int intimidation_val(int *arr, int size)
{
    if (size < 3)
        return 0;
    int pp = 0;
    int prev = is_intimidate(arr, 1);
    int curr = 0;
    int val = abs(prev);
    int max = 0;
    for (int i = 2; i < size; ++i)
    {
        curr = (i + 1 == size) ? 0 : is_intimidate(arr, i);
        val = val + abs(curr);

        // calc how many can be reduced
        if (max < 3)
        {
            if (pp != 0 && prev != 0 && curr != 0)
            { // 1 -1 1 or -1 1 -1
                max = 3;
            }
            else if (max < 2)
            {
                if (pp == 0 && prev == 1 && curr == -1)
                { // 0 1 -1; test: 2 2 2 1
                    max = (arr[i - 2] <= arr[i] || (i - 3 < 0 || arr[i - 3] == arr[i - 2])) ? 2 : 1;
                }
                else if (pp == -1 && prev == 1 && curr == 0)
                { // -1 1 0; test: 2 2 1
                    max = (arr[i - 2] >= arr[i] || i + 1 >= size || arr[i] == arr[i + 1]) ? 2 : 1;
                }
                else if (pp == 0 && prev == -1 && curr == 1)
                { // 0 -1 1; test: 2 2 2 1
                    max = (arr[i - 2] >= arr[i] || i - 3 < 0 || arr[i - 3] == arr[i - 2]) ? 2 : 1;
                }
                else if (pp == 1 && prev == -1 && curr == 0)
                { // 1 -1 0; test: 2 2 2 1
                    max = (arr[i - 2] <= arr[i] || (i + 1 >= size || arr[i] == arr[i + 1])) ? 2 : 1;
                }
                else if (max < 1 && prev != 0)
                { // 0 1 0 or 0 -1 0
                    max = 1;
                }
            }
        }
        pp = prev;
        prev = curr;
    }
    return val - max;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("hillsandvalleys.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;

    for (int i = 0, size; i < cases; ++i)
    {
        cin >> size;
        int *arr = new int[size];
        for (int j = 0, num; j < size; ++j)
            cin >> arr[j];
        cout << intimidation_val(arr, size) << endl;
        delete[] arr;
    }
    return 0;
}