#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int max_number_of_children(vector<int> arr)
{
    return 0;
}

int main()
{
    ifstream fin("input.txt");

    vector<int> arr;
    int size, val;
    fin >> size;
    for (int j = 0; j < size; ++j)
    {
        fin >> val;
        arr.push_back(val);
    }
    cout << max_number_of_children(arr);
    return 0;
}