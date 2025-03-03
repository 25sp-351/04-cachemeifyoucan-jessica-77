#include <stdio.h>

void printPieces(int lengths[], int values[], int rod, int piece, int max_val[]) {
    printf("Cutting list:\n");

    for (int i = 0; i < piece; i++) {
        if (lengths[i] > rod) {
            continue;
        }

        int num_pieces = rod / lengths[i];
        int remainder = rod % lengths[i];
        int total_value = num_pieces * values[i];

        printf("%d @ %d = %d\n", num_pieces, lengths[i], total_value);
        printf("Remainder: %d\n", remainder);
        printf("Value of rod: %d\n\n", total_value);
    }
}