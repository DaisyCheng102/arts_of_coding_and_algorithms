#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("advantage.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;
    while (cases--)
    {
        cin >> size;
        vector<int> arr;
        int max = 0, smax = 0;
        for (int i = 0, num = 0; i < size; ++i)
        {
            cin >> num;
            if(num > max)
            {
                smax = max;
                max = num;
            }
            else if(num > smax)
                smax = num;
            arr.push_back(num);
        }
        for(int j = 0; j < arr.size();++j)
        {
            if(arr[j] == max)
                cout << max - smax << " ";
            else
                cout << arr[j] - max << " ";
        }
        cout << endl;
    }
    return 0;
}