#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("goodkid.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;
    for (int i = 0, min; i < cases; ++i)
    {
        cin >> size;
        int product = 1;
        min = 10000000;
        for (int j = 0, num = 0, zero = 0; j < size; ++j)
        {
            cin >> num;
            if (num < min)
                min = num;
            if (num == 0 && zero < 1)
            {
                ++num;
                ++zero;
            }
            product = product * num;
            if (zero == 2)
                break;
        }
        if (min != 0)
            product = product / min * (min +1);
        cout << product << endl;
    }
    return 0;
}