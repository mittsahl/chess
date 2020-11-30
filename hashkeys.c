#include "defs.h"

/**
 * generatePositionKey - takes a ptr BOARD data type
 * and generates unique hashkey for that position
 * @position: BOARD that is passed into function
 * Return: final HashKay after all enPassant sq, piece positions,
 * and which side to move has been hashed into final Key;
 */

U64 generatePositionKey(const BOARD *postition)
{
    int sq = 0;
    /* Final position key that will be returned */
    U64 finalKey = 0;
    int piece = EMPTY;
     
    for (; sq < BRD_SQ_NUM; ++sq)
    {
        /* Loop through and piece equals value stored in array at that sqaure */
        piece = postition->pieces[sq];
        
        if (piece != NONE && piece != EMPTY)
        {
            ASSERT(piece >= wP && piece <= bK);
            /* XOR operator to hash in the piece key array at the square */
            finalKey ^= pieceKeys[piece][sq];
        }
    }    
    /* If white to move hash in the side key */
    if (postition->side == WHITE)
        finalKey ^= sideKey;
    
    /* If pawn moved forward 2 sq's on prev move, enPas sq will be set */
    if (postition->enPassant != NONE)
    {
        ASSERT(postition->enPassant >= 0 && postition->enPassant < BRD_SQ_NUM);
        finalKey ^= pieceKeys[EMPTY][postition->enPassant];
    }
    ASSERT(postition->castlePermission >= 0 && postition->castlePermission <= 15);
    /* Add castling permission to the hash key */
    finalKey ^= CastleKeys[postition->castlePermission];

    return (finalKey);
}
