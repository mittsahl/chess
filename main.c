#include <stdio.h>
#include "defs.h"

int main(void)
{
    initAll();
    
    U64 bitboard = 0ULL;
    printf("start:\n\n");
    PrintBitBoard(bitboard);

    bitboard |= (1ULL << SQ64(D2));
    printf("Added Pawn to D2\n\n");
    PrintBitBoard(bitboard);

    bitboard |= (1ULL << SQ64(E4));
    printf("Added Pawn to E4\n\n");
    PrintBitBoard(bitboard);
    
    return (0);
}
