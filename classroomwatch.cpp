#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief return =
 *
 * @param num = number you need to find
 * @param i = number that either its sum of digits equals to num or not
 */
bool check(int num, int i)
{
    int sum = i;
    while (i > 0)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum == num ? true : false;
}

int digits(int num)
{
    int d = 0;
    for (; num > 0; ++d)
        num /= 10;
    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("classroomwatch.txt");
    cin.rdbuf(fin.rdbuf());
    vector<int> arr;
    int num;
    cin >> num;
    int d = digits(num);
    for (int i = 1; i <= 9 * d; ++i)
    {
        if (check(num, num - i))
        {
            arr.push_back(num - i);
        }
    }
    cout << arr.size() << endl;
    for (int i = arr.size() - 1; i >= 0; --i)
        cout << arr[i] << endl;

    return 0;
}