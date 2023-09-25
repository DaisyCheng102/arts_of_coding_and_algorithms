#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool matrix(vector<vector<int> > arr)
{
    for (int i = 0, n; i < 4; ++i)
    {
        if (arr[0][0] < arr[0][1] && arr[0][1] < arr[1][1] && arr[1][0] < arr[1][1] && arr[0][0] < arr[1][0])
            return true;
        n = arr[0][0];
        arr[0][0] = arr[1][0];
        arr[1][0] = arr[1][1];
        arr[1][1] = arr[0][1];
        arr[0][1] = n;
    }
    return false;
}
int main()
{
    ifstream fin("input.txt");
    int cases, num;
    fin >> cases;

    vector<vector<int> > arr(2, vector<int>(2));
    for (int k = 0; k < cases; ++k)
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                fin >> num;
                arr[i][j] = num;
            }
        }
        cout << (matrix(arr) ? "YES" : "NO") << endl;
    }
    return 0;
}