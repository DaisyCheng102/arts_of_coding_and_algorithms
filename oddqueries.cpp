#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool oddqueries(vector<int> &arr, vector<int> &ods, int l, int r, int k)
{
    int odm = 0;
    if (k % 2 != 0)
        odm = r - l + 1;
    return (((l < 2 ? 0 : ods[l - 2]) + odm + ods[ods.size() - 1] - ods[r - 1]) % 2 == 0);
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("oddqueries.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size, sizeq, l, r, k;
    cin >> cases;
    while (cases--)
    {
        cin >> size;
        cin >> sizeq;
        vector<int> arr;
        vector<int> ods;
        for (int i = 0, num, odd = 0; i < size; ++i)
        {
            cin >> num;
            arr.push_back(num);
            if (num % 2 != 0)
                ods.push_back(++odd);
            else
                ods.push_back(odd);
        }
        while (sizeq--)
        {
            cin >> l >> r >> k;
            cout << ((oddqueries(arr, ods, l, r, k)) ? "NO" : "YES") << endl;
        }
    }
    return 0;
}