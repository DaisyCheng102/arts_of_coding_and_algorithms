#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr{1, 1, 1, 1};
    for(int i = 0; i < arr.size();++i)
    {
        for(int j = 0; j < arr.size();++j)
        {
            if(arr[i] != arr[j])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}