#include <iostream>
#include <fstream>

using namespace std;

int best_response(int size, int words[], int quality[])
{
    int max = 0, response = 0;
    for (int i = 0; i < size; ++i)
    {
        if (words[i] <= 10 && max < quality[i])
        {
            response = i + 1;
            max = quality[i];
        }
    }
    return response;
}

int main(int argc, char const *argv[])
{
    ifstream fin("input.txt");

    // read and test one case
    int cases;
    fin >> cases;
    for (int j = 0; j < cases; ++j)
    {
        int size;
        fin >> size;
        int *quality = new int[size];
        int *words = new int[size];

        for (int i = 0; i < size; ++i)
        {
            fin >> words[i] >> quality[i];
        }

        cout << best_response(size, words, quality) << endl;
    }

    return 0;
}
