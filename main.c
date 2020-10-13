#include <stdio.h>
#include "defs.h"

int main(void)
{
    initAll();
    
    U64 bitboard = 0ULL;
    bitboard |= (1ULL << SQ64(D2));
    bitboard |= (1ULL << SQ64(D3));
    bitboard |= (1ULL << SQ64(D4));
    
    PrintBitBoard(bitboard);
    int count = CNT(bitboard);
    printf("\n%d\n\n", count);

    int index = POP(&bitboard);
    printf("\n\n%d\n\n", index);
    PrintBitBoard(bitboard);
    
    return (0);
}
