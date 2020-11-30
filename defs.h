#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>

/* Fills 64 bits with random numbers to fill U64 bits  */
#define RAND_64 (   (U64)rand() + \
                    (U64)rand() << 15 + \
                    (U64)rand() << 30 + \
                    (U64)rand() << 45 + \
                    ((U64)rand() & 0xf) << 60   )

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) { \
    printf("%s - FAILED", #n);\
    printf("On %s ", __DATE__);\
    printf("At %s ", __TIME__);\
    printf("In File %s ", __FILE__);\
    printf("At Line %d\n", __LINE__);\
    exit(1); }
#endif
/* Defining data type for the bits */
typedef unsigned long long U64;

#define NAME "Play Me in Chess"
#define BRD_SQ_NUM 120
#define MAX_MOVES 2048

/* Enum for the piece names */
enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };

/* enum for file names */
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };

/* enum for rank names */
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

/* enum for color names */
enum { WHITE, BLACK, BOTH};

/* enum for square names on corresponding 120 element array */
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NONE
};

/* enum for names true and false */
enum { TRUE, FALSE };

/* enum defining different castling moves */
enum {W_KSIDE_CASTLE = 1, W_QSIDE_CASTLE = 2, B_KSIDE_CASTLE = 4, B_QSIDE_CASTLE = 8};

/* Struct that holds en passant, if fifty moves has been played,
position key, and move */
typedef struct 
{
    int move;
    int castlePermissions;
    int enPassant;
    int fiftyMoves;
    U64 positionKey;
} UNDO;

/* Struct that holds pieces array, 64 bit # pawns array, which side,
en passant, if fifty moves has been played, history, castling permissions,
array for different pieces and 64 bit position key */

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3];
    int kingSq[2];
    int side;
    int enPassant;
    int fiftyMoves;
    int play;
    int historyPlay;
    int castlePermission;   
    /* unique number representing position on the board */
    U64 positionKey;
    int pieceNumbers [13];
    int bigPieces[3];
    int majorPieces[3];
    int minorPieces[3];
    UNDO hist[MAX_MOVES];
    int pieceList[13][10];
} BOARD;

/* Globals */
extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64To120[64];
extern U64 setMask[64];
extern U64 clearMask[64];
U64 pieceKeys[13][120];
U64 sideKey;
U64 CastleKeys[16];

/* Macros */
#define FR2SQ(f, r) ((21 + (f)) + ( (r) * 10) )
#define SQ64(sq120) Sq120ToSq64[sq120]
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)

/* clearing specified bit from bitboard */
#define CLRBIT(bb, sq) ((bb) &= clearMask[(sq)])

/* sets a specified bit from bitboard */
#define SETBIT(bb, sq) ((bb) |= setMask[(sq)]) 

/* Functions */
extern void initAll();
extern void PrintBitBoard(U64 BitBoard);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);
#endif /*DEFS_H*/
