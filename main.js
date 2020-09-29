/* Defines pieces */
var pieces = {EMPTY:0, wP:1, wN:2, wB:3, wR:4, wQ:5, wK:6, bP:7, bN:8, bB:9, bR:10, bQ:11, bK:12 };

/* Defines number of sqaures */
var numberOfSquares = 120;

/* Defines rank values */
var ranks = {RANK_1:0, RANK_2:1, RANK_3:2, RANK_4:3, RANK_5:4, RANK_6:5, RANK_7:6, RANK_8:7, RANK_NONE:8};

/* Defines file values */
var files = {A_FILE:0, B_FILE:1, C_FILE:2, D_FILE:3, E_FILE:4, F_FILE:5, G_FILE:6, H_FILE:7, FILE_NONE:8};

/* Defines colors of pieces */
var colors = {WHITE:0, BLACK:1};

/* Defines names for each square on board for 120 element array */
var sqaureNames = { A1:21, B1:22, C1:23, D1:24, E1:25, F1:26, G1:27, H1:28,
                    A2:31, B2:32, C2:33, D2:34, E2:35, F2:36, G2:37, H2:38,
                    A3:41, B3:42, C3:43, D3:44, E3:45, F3:46, G3:47, H3:48,
                    A4:51, B4:52, C4:53, D4:54, E4:55, F4:56, G4:57, H4:58,
                    A5:61, B5:62, C5:63, D5:64, E5:65, F5:66, G5:67, H5:68,
                    A6:71, B6:72, C6:73, D6:74, E6:75, F6:76, G6:77, H6:78,    
                    A7:81, B7:82, C7:83, D7:84, E7:85, F7:86, G7:87, G7:88,
                    A8:91, B8:92, C8:93, D8:94, E8:95, F8:96, G8:97, H8:98,
                    NO_SQ:99, OFF:100
};

/*Defines boolean values */
var bool = {FALSE:0, TRUE:1};

/* Initializes new array of 120 values for each square's file */
var filesBoard = new Array(numberOfSquares);

/* Initializes new array of 120 values for each square's rank */
var ranksBoard = new Array(numberOfSquares);

/* Function to return the file and rank of each square for the reference boards */
function getFileGetRank(f,r) {
    return ((21 + f) + (r * 10));
}         

/* Fills reference boards first with all OFF values then changes the value
in that square to which file/rank it is a part of */
function initReferenceBoards(){
    for (let i = 0; i < numberOfSquares; i++)
    {
        filesBoard[i] = sqaureNames.OFF;
        ranksBoard[i] = sqaureNames.OFF;
    }
    for (let rank = ranks.RANK_1; rank <= ranks.RANK_8; ++rank)
    {
        for (let file = files.A_FILE; file <= files.H_FILE; ++file)
        {
            var square = getFileGetRank(file, rank);
            filesBoard[square] = file;
            ranksBoard[square] = rank;
        }
    }
};
