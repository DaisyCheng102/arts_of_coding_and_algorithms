#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("twotowers.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i)
    {
        int m, n;
        cin >> m >> n;
        char arr[m + n];
        for (int j = 0; j < m; ++j)
            cin >> arr[j];
        for (int j = n + m - 1; j >= m; --j)
            cin >> arr[j];
        int count = 0;
        for (int j = 1; j < m + n; j++)
            count += (int)arr[j] == arr[j - 1];
        cout << (count <= 1 ? "YES" : "NO") << endl;
    }
    return 0;
}