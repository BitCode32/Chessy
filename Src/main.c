#include <stdio.h>
#include "../Include/ChessEngine/ChessEngine.h"
#include "../Include/ChessEngine/ChessMove.h"

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

	char player_select[2];
	char player_move[2];
	while (player_select[0] != 'e' || player_select[1] != 'x' || player_move[0] != 'i' || player_move[1] != 't') {
		printBoard(&main_engine);

		printf("\nEnter move: ");
		player_select[0] = getchar();
		player_select[1] = getchar();
		player_move[0] = getchar();
		player_move[1] = getchar();
		while (getchar() != '\n');

		if (!ChessyChessEngineMove(&main_engine, player_select, player_move)) {
			printf("Invalid Move!\n");
		}
	}

	return 0;
}
