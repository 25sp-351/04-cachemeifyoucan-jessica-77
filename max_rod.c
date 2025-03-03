#include <stdio.h>

#include "max_rod.h"


int maxRod(int lengths[], int values[], int rod, int piece, int max_val[]) {
    max_val[0] = 0;

    for (int length = 1; length <= rod; length++) {
        int max_rev = 0;

        for (int ind = 0; ind < piece; ind++) {
            if (lengths[ind] <= length) {
                int val = values[ind] + max_val[length - lengths[ind]];
                if (val > max_rev) {
                    max_rev = val;
                }
            }
        }
        max_val[length] = max_rev;
    }
    return max_val[rod];
}