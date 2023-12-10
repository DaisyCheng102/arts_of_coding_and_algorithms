#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int blank_space(vector<int> arr)
{
    int count = 0, max = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 0)
            ++count;
        else
        {
            if (max < count)
                max = count;
            count = 0;
        }
    }
    return max < count ? count : max;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("input.txt");
    int cases;
    fin >> cases;

    vector<int> arr;
    for (int i = 0; i < cases; ++i)
    {
        int size = 0, val;
        fin >> size;
        for (int j = 0; j < size; ++j)
        {
            fin >> val;
            arr.push_back(val);
        }

        // <bool_expression>?true_expression : false_expression;
        cout << blank_space(arr) << endl;
        // must clear arr so it doesnt contain prev numbers
        arr.clear();
    }
    return 0;
}