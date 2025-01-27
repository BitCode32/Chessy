#include <stdio.h>
#include <Chessy/ChessEngine.h>
#include <Chessy/ChessMove.h>

static void printBoard(chessy_chess_engine *current_engine) {
	printf("\ncurrent score: %d\n", current_engine->total_game_score);
	printf("  abcdefgh\n");
	for (int y = 0; y < CHESSY_BOARD_SIZE; y++) {
		printf("%d ", 8 - y);
		for (int x = 0; x < CHESSY_BOARD_SIZE; x++) {
			printf("%c", current_engine->board[x + (y * CHESSY_BOARD_SIZE)]);
		}
		printf("\n");
	}
}

int main() {
	chessy_chess_engine main_engine;
	ChessyChessEngineInitialize(&main_engine);

	for (unsigned short row = 0; row < CHESSY_BOARD_SIZE; row++) {
		for (unsigned short column = 0; column < CHESSY_BOARD_SIZE; column++) {
			chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT];
			int move_count = ChessyChessMoveGetValidMove(&main_engine, row, column, possible_moves);

			if (move_count > 0) {
				printf("%c has the following possible moves: \n", main_engine.board[column + (row * CHESSY_BOARD_SIZE)]);
				for (unsigned short i = 0; i < move_count; i++) {
					printf("\t%c%c to %c%c\n", '8' - row, 'a' + column, '8' - possible_moves[i].row, 'a' + possible_moves[i].column);
				}
			}
		}
	}

	char player_select[2];
	char player_move[2];
	while (player_select[0] != 'e' || player_select[1] != 'x' || player_move[0] != 'i' || player_move[1] != 't') {
		printBoard(&main_engine);

		printf("\nEnter move: ");
		player_select[0] = (char)getchar();
		player_select[1] = (char)getchar();
		player_move[0] = (char)getchar();
		player_move[1] = (char)getchar();
		while (getchar() != '\n');

		if (!ChessyChessEngineMove(&main_engine, player_select, player_move)) {
			printf("Invalid Move!\n");
		}
	}

	return 0;
}
