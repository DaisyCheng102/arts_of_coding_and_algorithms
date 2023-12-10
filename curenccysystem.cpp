#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("sortthearray.txt");
    cin.rdbuf(fin.rdbuf());
    int size;
    cin >> size;
    for(int i = 0, num;i < size;++i)
    {
        cin >> num;
        if(num == 1)
        {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}