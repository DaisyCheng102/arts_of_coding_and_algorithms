#include <iostream>
#include <fstream>

using namespace std;

bool check(int a, int b, int c)
{
    return a + b >= 10 || b + c >= 10 || a + c >= 10;
}

int main()
{
    ifstream fin("input.txt");
    int cases;
    fin >> cases;

    for (int i = 0; i < cases; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        cout << a << ", " << b << ", " << c << ": " << std::boolalpha << check(a, b, c) << endl;
    }
}