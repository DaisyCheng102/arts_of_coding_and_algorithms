#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("findpair.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    while(cases--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);

        for (long long j = 0; j < n; ++j)
        {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());

        long long first = (k - 1) / n;
        if ((first - 1 >= 0 && arr[first] == arr[first - 1]) || (first + 1 < n && arr[first + 1] == arr[first]))
        {
            long long l = first - 1, r = first + 1;
            for (; l >= 0 && arr[l] == arr[first]; --l)
                ;
            for (; r < n && arr[r] == arr[first]; ++r)
                ;
            ++l;
            --r;
            long long duplicates = r - l + 1;
            k -= l * n;
            cout << arr[first] << " " << arr[(k - 1) / duplicates] << endl;
        }
        else
        {
            cout << arr[first] << " " << arr[(k - 1) % n] << endl;
        }
    }
    return 0;
}