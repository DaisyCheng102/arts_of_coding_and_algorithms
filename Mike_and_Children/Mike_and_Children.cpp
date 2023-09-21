#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int n = 10;
    int size, val;
    fin >> size;
    unordered_map<int, int> maps;
    int max = 0;
    int arr[size]; // to contain the numbers
    for (int i = 0, num = 0; i < size; ++i)
    {
        fin >> arr[i];
    }
    fin.close();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            int sum = arr[i] + arr[j];
            if (maps.find(sum) == maps.end())
            {
                maps[sum] = 1;
            }
            else
            {
                ++maps[sum];
            }
            if (maps[sum] > max)
            {
                max = maps[sum];
            }
        }
    }
    cout << max << endl;
    return max;
}