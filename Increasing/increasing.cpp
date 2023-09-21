#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool increasing(vector<int> arr)
{
    if(arr.size() == 1)
        return true;
    for(int i = 0; i < arr.size();++i)
        for(int j = i + 1; j < arr.size();++j)
            if(arr[i] != arr[j])
                return true;
    return false;
}

int main()
{
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
        cout << (increasing(arr) ? "YES" : "NO") << endl;
        //must clear arr so it doesnt contain prev numbers
        arr.clear();
    }
    return 0;
}