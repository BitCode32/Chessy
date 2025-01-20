#include "../../Include/ChessEngine/ChessEngine.h"
#include "../../Include/ChessEngine/ChessMove.h"

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine) {
	new_chess_engine->total_game_score = 0;
	new_chess_engine->current_color = CHESSY_WHITE;

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

	for (int i = 0; i < CHESSY_BOARD_SIZE; i++) {
		new_chess_engine->is_en_passant_white[i] = chessy_false;
		new_chess_engine->is_en_passant_black[i] = chessy_false;
	}
}

chessy_bool ChessyChessEngineMove(chessy_chess_engine *current_chess_engine, char current_board_position[2], char new_board_position[2]) {
	int current_row = '8' - current_board_position[1];
	int current_column = current_board_position[0] - 'a';

	chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT];
	int move_count = ChessyChessMoveGetValidMove(current_chess_engine, current_row, current_column, possible_moves);
	if (move_count > 0) {
		int new_row = '8' - new_board_position[1];
		int new_column = new_board_position[0] - 'a';

		for (int i = 0; i < move_count; i++) {
			if (possible_moves[i].row == new_row && possible_moves[i].column == new_column) {
				int current_index = current_column + (current_row * CHESSY_BOARD_SIZE);
				current_chess_engine->board[new_column + (new_row * CHESSY_BOARD_SIZE)] = current_chess_engine->board[current_index];
				current_chess_engine->board[current_index] = ' ';

				current_chess_engine->current_color = (current_chess_engine->current_color == CHESSY_WHITE) ? CHESSY_BLACK : CHESSY_WHITE;
				return chessy_true;
			}
		}
	}

	return chessy_false;
}
