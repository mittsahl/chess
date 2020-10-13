#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64To120[64];

void initSq120to64(){
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



void initAll(){
    initSq120to64();
}