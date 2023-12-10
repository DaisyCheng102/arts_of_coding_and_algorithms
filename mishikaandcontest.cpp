#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    string name = filesystem::path(argv[0]).filename();
    ifstream fin(name + ".txt");
    cin.rdbuf(fin.rdbuf());
    int size, skill, count = 0, left = -1;
    cin >> size >> skill;
    vector<int> arr(size);
    for (int i = 0, num; i < size; ++i)
    {
        cin >> arr[i];
        if (left == -1)
        {
            if (arr[i] <= skill)
                ++count;
            else
                left = i;
        }
    }
    for (int i = size - 1; i >= left && left != -1; --i)
    {
        if (arr[i] <= skill)
            ++count;
        else
            break;
    }
    cout << count << endl;

    return 0;
}