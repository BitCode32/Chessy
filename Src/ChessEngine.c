#include "../Include/ChessEngine.h"

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine) {
	new_chess_engine->total_game_score = 0;

	char chess_board[CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE] = {
		CHESSY_BLACK_ROOK, CHESSY_BLACK_BISHOP, CHESSY_BLACK_KNIGHT, CHESSY_BLACK_QUEEN, CHESSY_BLACK_KING, CHESSY_BLACK_KNIGHT, CHESSY_BLACK_BISHOP, CHESSY_BLACK_ROOK,
		CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN,
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN,
		CHESSY_WHITE_ROOK, CHESSY_WHITE_BISHOP, CHESSY_WHITE_KNIGHT, CHESSY_WHITE_QUEEN, CHESSY_WHITE_KING, CHESSY_WHITE_KNIGHT, CHESSY_WHITE_BISHOP, CHESSY_WHITE_ROOK
	};

	for (int i = 0; i < CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE; i++) {
		new_chess_engine->board[i] = chess_board[i];
	}
}
