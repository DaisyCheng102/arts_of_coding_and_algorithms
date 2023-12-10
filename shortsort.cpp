#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool short_sort(vector<char> arr)
{
    int out_of_position = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] != i + 'a')
            ++out_of_position;
    }
    return (out_of_position <= 2);
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("shortsort.txt");
    int cases;
    char a, b, c;
    fin >> cases;

    vector<char> arr;
    for (int i = 0; i < cases; ++i)
    {
        fin >> a >> b >> c;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        cout << (short_sort(arr) ? "Yes" : "No") << endl;
        arr.clear();
    }
    return 0;
}