#include <stdio.h>
#include "defs.h"

/* Function to visualize and print U64 bitboard as chessboard */

void PrintBitBoard(U64 BitBoard)
{
    U64 shift = 1ULL;

    int rank = 0;
    int file = 0;
    int sq = 0;
    int sq64 = 0;

    putchar('\n');
    for (rank = RANK_8; rank >= RANK_1; --rank)
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            sq = FR2SQ(file, rank);
            sq64 = SQ64(sq);
            if ((shift << sq64) & BitBoard)
                printf("X ");
            else
                printf("- ");
            }
        putchar('\n');
    }
    printf("\n\n");
}