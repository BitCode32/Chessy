#include "../Include/Chessy/ChessEngine.h"
#include "../Include/Chessy/ChessMove.h"

void ChessyChessEngineInitialize(chessy_chess_engine *new_chess_engine) {
	new_chess_engine->total_game_score = 0;
	new_chess_engine->current_color = CHESSY_WHITE;

	char chess_board[CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE] = {
		CHESSY_BLACK_ROOK, CHESSY_BLACK_KNIGHT, CHESSY_BLACK_BISHOP, CHESSY_BLACK_QUEEN, CHESSY_BLACK_KING, CHESSY_BLACK_BISHOP, CHESSY_BLACK_KNIGHT, CHESSY_BLACK_ROOK,
		CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN, CHESSY_BLACK_PAWN,
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN, CHESSY_WHITE_PAWN,
		CHESSY_WHITE_ROOK, CHESSY_WHITE_KNIGHT, CHESSY_WHITE_BISHOP, CHESSY_WHITE_QUEEN, CHESSY_WHITE_KING, CHESSY_WHITE_BISHOP, CHESSY_WHITE_KNIGHT, CHESSY_WHITE_ROOK
	};

	for (int i = 0; i < CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE; i++) {
		new_chess_engine->board[i] = chess_board[i];
	}

	for (int i = 0; i < CHESSY_BOARD_SIZE; i++) {
		new_chess_engine->is_en_passant_white[i] = chessy_false;
		new_chess_engine->is_en_passant_black[i] = chessy_false;
	}

	new_chess_engine->record_count = 0;
}

// TODO: add support for en passant, castling and promoting
chessy_bool ChessyChessEngineMove(chessy_chess_engine *current_chess_engine, char current_board_position[2], char new_board_position[2]) {
	unsigned int current_row = '8' - current_board_position[1];
	unsigned int current_column = current_board_position[0] - 'a';

	chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT];
	int move_count = ChessyChessMoveGetValidMove(current_chess_engine, current_row, current_column, possible_moves);
	if (move_count > 0) {
		unsigned int new_row = '8' - new_board_position[1];
		unsigned int new_column = new_board_position[0] - 'a';

		for (int i = 0; i < move_count; i++) {
			if (possible_moves[i].row == new_row && possible_moves[i].column == new_column) {
				int current_index = current_column + (current_row * CHESSY_BOARD_SIZE);
				int new_index = new_column + (new_row * CHESSY_BOARD_SIZE);

				if (current_chess_engine->record_count == CHESSY_MAX_HISTORY_RECORDS) {
					current_chess_engine->record_count--;
					for (unsigned int record_index = 0; record_index < current_chess_engine->record_count; record_index++) {
						current_chess_engine->records[record_index].from_row = current_chess_engine->records[record_index + 1].from_row;
						current_chess_engine->records[record_index].from_column = current_chess_engine->records[record_index + 1].from_column;
						current_chess_engine->records[record_index].to_row = current_chess_engine->records[record_index + 1].to_row;
						current_chess_engine->records[record_index].to_column = current_chess_engine->records[record_index + 1].to_column;

						current_chess_engine->records[record_index].current_color = current_chess_engine->records[record_index + 1].current_color;
						current_chess_engine->records[record_index].own_piece = current_chess_engine->records[record_index + 1].own_piece;
						current_chess_engine->records[record_index].opponent_piece = current_chess_engine->records[record_index + 1].opponent_piece;
					}
				}

				current_chess_engine->records[current_chess_engine->record_count].from_row = current_row;
				current_chess_engine->records[current_chess_engine->record_count].from_column = current_column;
				current_chess_engine->records[current_chess_engine->record_count].to_row = new_row;
				current_chess_engine->records[current_chess_engine->record_count].to_column = new_column;

				current_chess_engine->records[current_chess_engine->record_count].current_color = current_chess_engine->current_color;
				current_chess_engine->records[current_chess_engine->record_count].own_piece = current_chess_engine->board[current_index];
				current_chess_engine->records[current_chess_engine->record_count].opponent_piece = current_chess_engine->board[new_index];

				current_chess_engine->record_count++;
				current_chess_engine->total_game_score -= ChessyChessEngineGetPieceScore(current_chess_engine->board[new_index]);

				current_chess_engine->board[new_index] = current_chess_engine->board[current_index];
				current_chess_engine->board[current_index] = ' ';

				current_chess_engine->current_color ^= 1;
				return chessy_true;
			}
		}
	}

	return chessy_false;
}

chessy_bool ChessyChessEngineUndoMove(chessy_chess_engine *current_chess_engine) {
	if (current_chess_engine->record_count == 0) {
		return chessy_false;
	}

	const unsigned int index = current_chess_engine->record_count - 1;

	current_chess_engine->current_color = current_chess_engine->records[index].current_color;

	current_chess_engine->board[current_chess_engine->records[index].from_column + (current_chess_engine->records[index].from_row * CHESSY_BOARD_SIZE)] = current_chess_engine->records[index].own_piece;
	current_chess_engine->board[current_chess_engine->records[index].to_column + (current_chess_engine->records[index].to_row * CHESSY_BOARD_SIZE)] = current_chess_engine->records[index].opponent_piece;

	current_chess_engine->total_game_score += ChessyChessEngineGetPieceScore(current_chess_engine->records[index].opponent_piece);

	current_chess_engine->record_count--;
	return chessy_true;
}

int ChessyChessEngineGetPieceScore(char piece) {
	switch (piece) {
		case CHESSY_WHITE_PAWN:
			return CHESSY_PAWN_SCORE;

		case CHESSY_WHITE_ROOK:
			return CHESSY_ROOK_SCORE;

		case CHESSY_WHITE_BISHOP:
			return CHESSY_BISHOP_SCORE;

		case CHESSY_WHITE_KNIGHT:
			return CHESSY_KNIGHT_SCORE;

		case CHESSY_WHITE_QUEEN:
			return CHESSY_QUEEN_SCORE;

		case CHESSY_WHITE_KING:
			return CHESSY_KING_SCORE;

		case CHESSY_BLACK_PAWN:
			return -CHESSY_PAWN_SCORE;

		case CHESSY_BLACK_ROOK:
			return -CHESSY_ROOK_SCORE;

		case CHESSY_BLACK_BISHOP:
			return -CHESSY_BISHOP_SCORE;

		case CHESSY_BLACK_KNIGHT:
			return -CHESSY_KNIGHT_SCORE;

		case CHESSY_BLACK_QUEEN:
			return -CHESSY_QUEEN_SCORE;

		case CHESSY_BLACK_KING:
			return -CHESSY_KING_SCORE;

		default:
			break;
	}

	return 0;
}

void ChessyChessEngineCopy(chessy_chess_engine *destination, chessy_chess_engine *origin) {
	destination->total_game_score = origin->total_game_score;
	destination->current_color = origin->current_color;

	for (unsigned int i = 0; i < CHESSY_BOARD_SIZE * CHESSY_BOARD_SIZE; i++) {
		destination->board[i] = origin->board[i];
	}

	for (unsigned int i = 0; i < CHESSY_BOARD_SIZE; i++) {
		destination->is_en_passant_white[i] = origin->is_en_passant_white[i];
		destination->is_en_passant_black[i] = origin->is_en_passant_black[i];
	}

	destination->record_count = origin->record_count;
	for (unsigned int i = 0; i < origin->record_count; i++) {
		destination->records[i].from_row = origin->records[i].from_column;
		destination->records[i].from_column = origin->records[i].from_column;
		destination->records[i].to_row = origin->records[i].to_row;
		destination->records[i].to_column = origin->records[i].to_column;

		destination->records[i].current_color = origin->records[i].current_color;
		destination->records[i].own_piece = origin->records[i].own_piece;
		destination->records[i].opponent_piece = origin->records[i].opponent_piece;
	}
}