#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("gregandarray.txt");
    cin.rdbuf(fin.rdbuf());
    int asize, osize, apsize;
    cin >> asize >> osize >> apsize;

    // step 0: read
    vector<long long> arr(asize);
    for (int i = 0; i < asize; ++i)
    {
        cin >> arr[i];
    }

    vector<vector<long long>> ops(osize, vector<long long>(3));
    for (int i = 0; i < osize; ++i)
    {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    vector<long long> op_freq(osize + 1);
    for (int i = 0, l = 0, r = 0; i < apsize; ++i)
    {

        cin >> l >> r;
        ++op_freq[l - 1];
        --op_freq[r];
    }
    for (int i = 1; i < osize; ++i)
    {
        op_freq[i] += op_freq[i - 1];
    }

    vector<long long> adds(asize + 1);
    for (int i = 0; i < osize; ++i)
    {
        long long d = op_freq[i] * ops[i][2];
        adds[ops[i][0] - 1] += d;
        adds[ops[i][1]] -= d;
    }
    for (int i = 1; i < asize; ++i)

        adds[i] += adds[i - 1];

    for (int i = 0; i < asize; ++i)
    {
        cout << adds[i] + arr[i] << " ";
    }
    return 0;
}