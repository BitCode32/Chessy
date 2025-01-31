#ifndef CHESSY_CONSTANTS
#define CHESSY_CONSTANTS

#define CHESSY_WHITE 0
#define CHESSY_BLACK 1

#define CHESSY_WHITE_PAWN 'P'
#define CHESSY_WHITE_ROOK 'R'
#define CHESSY_WHITE_BISHOP 'B'
#define CHESSY_WHITE_KNIGHT 'N'
#define CHESSY_WHITE_QUEEN 'Q'
#define CHESSY_WHITE_KING 'K'

#define CHESSY_BLACK_PAWN 'p'
#define CHESSY_BLACK_ROOK 'r'
#define CHESSY_BLACK_BISHOP 'b'
#define CHESSY_BLACK_KNIGHT 'n'
#define CHESSY_BLACK_QUEEN 'q'
#define CHESSY_BLACK_KING 'k'

#define CHESSY_PAWN_SCORE 10
#define CHESSY_ROOK_SCORE 50
#define CHESSY_BISHOP_SCORE 35
#define CHESSY_KNIGHT_SCORE 30
#define CHESSY_QUEEN_SCORE 90
#define CHESSY_KING_SCORE 900

#define CHESSY_BOARD_SIZE 8
#define CHESSY_MAX_MOVE_COUNT 27
#define CHESSY_MAX_HISTORY_RECORDS 1024

#define CHESSY_DIFFICULTY_BEGINNER 3
#define CHESSY_DIFFICULTY_INTERMEDIATE 5
// FIX: These are way to slow for use (master even crashes) should fix minimax to improve these
// #define CHESSY_DIFFICULTY_EXPERT 7
// #define CHESSY_DIFFICULTY_MASTER 11

#endif