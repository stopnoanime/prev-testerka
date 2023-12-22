#include <iostream>
#include <vector>

using namespace std;

int main() {
    char c;
    int x, lo, hi, events;

    vector<int> ciag;

    std::cin >> events;
    for (int i = 0; i < events; i++) {
        cin >> c;

        if (c == 'P') { // push
            cin >> x;
            ciag.push_back(x);
        } else { // ask
            cin >> x >> lo >> hi;

            // brut
            int maks = -1;
            for (int j = 0; j <= x; j++)
                if (lo <= ciag[j] && ciag[j] <= hi)
                    maks = j;

            cout << maks << " ";
        }
    }
}