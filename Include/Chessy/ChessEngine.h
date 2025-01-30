#ifndef CHESSY_CHESS_ENGINE
#define CHESSY_CHESS_ENGINE

#include "Bool.h"
#include "Constants.h"

typedef struct {
	unsigned int from_row, from_column;
	unsigned int to_row, to_column;

	unsigned int current_color;
	char own_piece, opponent_piece;
} chessy_record;

typedef struct {
	int total_game_score;
	unsigned int current_color;

	char board[CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE];
	
	chessy_bool is_en_passant_white[CHESSY_BOARD_SIZE];
	chessy_bool is_en_passant_black[CHESSY_BOARD_SIZE];

	unsigned int record_count;
	chessy_record records[CHESSY_MAX_HISTORY_RECORDS];
} chessy_chess_engine;

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine);

chessy_bool ChessyChessEngineMove(chessy_chess_engine *current_chess_engine, char current_board_position[2], char new_board_position[2]);
chessy_bool ChessyChessEngineUndoMove(chessy_chess_engine *current_chess_engine);
int ChessyChessEngineGetPieceScore(char piece);

void ChessyChessEngineCopy(chessy_chess_engine *destination, chessy_chess_engine *origin);

#endif
