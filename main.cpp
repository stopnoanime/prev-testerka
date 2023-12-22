#include <iostream>

#include "prev.h"

int main() {
    char c;
    int x, lo, hi, events;

    std::vector<int> seq;
    init(seq);

    std::cin >> events;
    for (int i = 0; i < events; i++) {
        std::cin >> c;

        if (c == 'P') { // push
            std::cin >> x;
            pushBack(x);
        } else { // ask
            std::cin >> x >> lo >> hi;
            std::cout << prevInRange(x, lo, hi) << " ";
        }
    }

    done();
}
