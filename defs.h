#ifndef DEFS_H
#define DEFS_H
typedef unsigned long long U64;

#define NAME "Play Me in Chess"
#define BRD_SQ_NUM 120
#define MAX_MOVES 2048

enum ( EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK );
enum ( FILE_A, FILE_B, FILE_C, FILE_D, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE );
enum ( RANK_1, RANK_2, RANK_3, RANK_4, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE );

enum ( WHITE, BLACK, BOTH );

enum (
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NONE
);

enum ( TRUE, FALSE );

enum ( W_KSIDE_CASTLE = 1, W_QSIDE_CASTLE = 2, B_KSIDE_CASTLE = 4, B_QSIDE_CASTLE = 8 );

typedef struct 
{
    int move;
    int castlePermissions;
    int enPassant;
    int fiftyMoves;
    U64 positionKey;
} UNDO;


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
    U64 positionKey;
    int pieceNumbers [13];
    int bigPieces[3];
    int majorPieces[3];
    int minorPieces[3];
    UNDO hist[MAX_MOVES];
} BOARD;

#endif /*DEFS_H*/
