#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("rigged.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size = 0;
    cin >> cases;
    while (cases--)
    {
        int max = 0, s, e, ws, we;
        cin >> size;
        cin >> ws >> we;
        while(--size)
        {
            cin >> s >> e;
            if(ws <= s && we <= e)
            {
                max = e;
            }
        }
        cout << ((we > max) ? ws : -1) << endl;
    }
    return 0;
}