#include <iostream>
#include <random>

using namespace std;

int main() {
    int seed, events, range;
    float ratio;
    cin >> seed >> events >> ratio >> range;

    cout << events << endl;

    mt19937 gen(seed);

    uniform_int_distribution<int> xDist(-range, range);
    bernoulli_distribution ratioDist(ratio);

    int currentLen = 0;

    for (int i = 0; i < events; i++) {
        if (currentLen == 0 || ratioDist(gen)) { // push
            cout << "P " << xDist(gen) << endl;
            currentLen++;
        } else { // ask
            uniform_int_distribution<int> iDist(0, currentLen - 1);

            int lo = xDist(gen);
            int hi = xDist(gen);
            if (lo > hi)
                swap(lo, hi);

            cout << "A " << iDist(gen) << " " << lo << " " << hi << endl;
        }
    }
}