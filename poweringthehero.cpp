#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("poweringthehero.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;
    while (cases--)
    {
        cin >> size;
        long long power = 0, num = 0;
        std::priority_queue<long long> bonus;
        for (int i = 0; i < size; ++i)
        {
            cin >> num;
            if (num != 0)
            {
                bonus.push(num);
            }
            else if (!bonus.empty())
            {
                power += bonus.top();
                bonus.pop();
            }
        }
        cout << power << endl;
    }
    return 0;
}