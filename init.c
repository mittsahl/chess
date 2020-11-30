#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64To120[64];
U64 setMask[64];
U64 clearMask[64];
/* Piece Keys Indexed by square */
U64 pieceKeys[13][120];
U64 sideKey;
U64 CastleKeys[16];

/**
 * initHashKeys - initializes hashKey arrays with random 64bit numbers
 * Return : void
 */

void initHashKeys() 
{
    int idx = 0;
    int idx2 = 0;

    for (; idx < 13; ++idx) 
    {
        for (; idx2 < 120; ++idx2)
            pieceKeys[idx][idx2] = RAND_64;
    }
    sideKey = RAND_64;
    for (idx = 0; idx < 16; ++idx)
    {
        CastleKeys[idx] = RAND_64;
    }
}

/**
 * initBitMasks - function that sets array of 64 bit nums used to
 * set and clear individual bits
 * Return: void
 */

void initBitMasks()
{
    int index = 0;

    for (; index < 64; index++)
    {
        setMask[index] = 0ULL;
        clearMask[index] = 0ULL;
    }
    for (index = 0; index < 64; index++)
    {
        setMask[index] |= (1ULL << index);
        clearMask[index] = ~setMask[index];
    }
}

/**
 * initSq120to64 - initializes array of 120 and array of 64 with 
 * corresponding values of each square in the other array
 * Return: void
 */

void initSq120to64()
{
    int idx = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;
    /* Initializes all values for both arrays to values 1 + number of elements */
    for (idx = 0; idx < BRD_SQ_NUM; ++idx)
        Sq120ToSq64[idx] = 65;
    for (idx = 0; idx < 64; ++idx)
        Sq64To120[idx] = 120;
    
    /* Initializes references array to their 120 array values and vice versa */
    for (rank = RANK_1; rank <= RANK_8; ++rank)    
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            sq = FR2SQ(file, rank);
            Sq64To120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

/**
 * initAll - all the initialization functions for the program
 * Return: void
 */

void initAll()
{
    initSq120to64();
    initBitMasks();
    initHashKeys();
}