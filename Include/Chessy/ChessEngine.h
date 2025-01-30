#ifndef CHESSY_CHESS_ENGINE
#define CHESSY_CHESS_ENGINE

#include "Bool.h"
#include "Constants.h"

typedef struct {
	int total_game_score;
	char current_color;

	char board[CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE];
	
	chessy_bool is_en_passant_white[CHESSY_BOARD_SIZE];
	chessy_bool is_en_passant_black[CHESSY_BOARD_SIZE];
} chessy_chess_engine;

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine);

chessy_bool ChessyChessEngineMove(chessy_chess_engine *current_chess_engine, char current_board_position[2], char new_board_position[2]);
int ChessyChessEngineGetPieceScore(char piece);

void ChessyChessEngineCopy(chessy_chess_engine *destination, chessy_chess_engine *origin);

#endif
