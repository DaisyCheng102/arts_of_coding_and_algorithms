#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("gettingpoints.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    while (cases--)
    {
        long long n, p, l, t;
        cin >> n >> p >> l >> t;
        // k: number of tasks
        long long k = (n + 6) / 7;
        // case 1: all FDays added together are enough for p
        long long fd = k / 2, fdp = l + t + t;
        long long fdsum = fd * fdp;
        if (fdsum >= p)
        {
            cout << n - (p + fdp - 1) / fdp << endl;
            continue;
        }
        // case 2: all Fdays AND all HDays added together are enough for p
        long long hd = k % 2, hdp = l + t;
        long long hdsum = hd * hdp;
        if (hd && hdsum + fdsum >= p)
        {
            cout << n - fd - hd << endl;
            continue;
        }
        // case 3: all days added together are enough for p
        int days = (p - hdsum - fdsum + l - 1) / l;
        cout << fixed << n - days - fd - hd << endl;
    }
    return 0;
}