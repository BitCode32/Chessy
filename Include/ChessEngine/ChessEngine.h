#ifndef CHESSY_CHESS_ENGINE
#define CHESSY_CHESS_ENGINE

#include "../Bool.h"

#define CHESSY_WHITE 'W'
#define CHESSY_BLACK 'B'

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
#define CHESSY_BISHOP_SCORE 30
#define CHESSY_KNIGHT_SCORE 30
#define CHESSY_QUEEN_SCORE 90
#define CHESSY_KING_SCORE 900

#define CHESSY_BOARD_SIZE 8

typedef struct {
	int total_game_score;
	char current_color;

	char board[CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE];
	
	chessy_bool is_en_passant_white[CHESSY_BOARD_SIZE];
	chessy_bool is_en_passant_black[CHESSY_BOARD_SIZE];
} chessy_chess_engine;

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine);

#endif
