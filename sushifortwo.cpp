#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("sushifortwo.txt");
    cin.rdbuf(fin.rdbuf());
    int size = 0, curr = 0, prev = 0, count1 = 0, count2 = 0, max_length = 0;
    cin >> size;
    while (size--)
    {
        cin >> curr;

        // loop invariants:
        // curr:the number being processed right now
        // prev: the number that was just processed
        // count1: how many continous 1's in most recent segments
        // count2: how many continous 2's in most recent segments
        // max_length: the answer

        // 1. If curr is not the same as prev, calculate subsegment length from previous segments, then compare and update max
        if (curr != prev)
        {
            max_length = max(max_length, min(count1, count2) * 2);
            // 2. after updating max, reset counter for current
            if (curr == 2)
                count2 = 0;
            else
                count1 = 0;
        }
        // 3. increase counter for current number
        if (curr == 1)
            ++count1;
        else
            ++count2;
        // 4. update prev
        prev = curr;

        // validate loop invaraint
    }
    max_length = max(max_length, min(count1, count2) * 2);
    cout << max_length << endl;
    return 0;
}