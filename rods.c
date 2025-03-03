#include <stdio.h>
#include <stdlib.h>
#include "max_rod.h"
#include "print_rod.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int rod;
    if (fscanf(file, "%d", &rod) != 1 || rod <= 0) {
        fprintf(stderr, "Invalid rod length in file\n");
        fclose(file);
        return 1;
    }

    int length[100], value[100], piece = 0;
    printf("Reading piece prices from file\n");

    while (fscanf(file, "%d, %d", &length[piece], &value[piece]) == 2) {
        piece++;
        if (piece >= 100) break; // Limit to 100 pieces
    }

    if (piece == 0) {
        fprintf(stderr, "No valid pieces found in file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    // checks if pieces are greater than rod length
    for (int i = 0; i < piece; i++) {
        if (length[i] > rod) {
            printf("Piece length %d is greater than rod length %d\n\n", length[i], rod);
        }
    }

    int max_val[rod + 1];
    int total_val = maxRod(length, value, rod, piece, max_val);

    printPieces(length, value, rod, piece, max_val);
    printf("Best value: %d\n", total_val);

    return 0;
}