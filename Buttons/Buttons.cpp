#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool buttons(vector<int> arr)
{
    if(arr[2] % 2 == 0)
    {
        if(arr[0] > arr[1])
            return true;
        if(arr[0] <= arr[1])
            return false;
    }
    else if(arr[2] % 2 != 0)
    {
        if(arr[0] >= arr[1])
            return true;
        if(arr[0] < arr[1])
            return false;
    }
}

int main()
{
    ifstream fin("input.txt");
    int cases;
    fin >> cases;

    vector<int> arr;
    for (int i = 0; i < cases; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        // <bool_expression>?true_expression : false_expression;
        cout << (buttons(arr) ? "First" : "Second") << endl;
        // must clear arr so it doesnt contain prev numbers
        arr.clear();
    }
    return 0;
}