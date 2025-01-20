#include <stdio.h>
#include "../Include/ChessEngine/ChessEngine.h"
#include "../Include/ChessEngine/ChessMove.h"

int main() {
	chessy_chess_engine main_engine;
	ChessyChessEngineInitialize(&main_engine);

	for (int y = 0; y < CHESSY_BOARD_SIZE; y++) {
		for (int x = 0; x < CHESSY_BOARD_SIZE; x++) {
			printf("%c", main_engine.board[x + (y * CHESSY_BOARD_SIZE)]);
		}
		printf("\n");
	}

	chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT];
	int move_count = ChessyChessMoveGetValidMove(&main_engine, 7, 2, possible_moves);

	printf("%d possible moves with knight\n", move_count);
	for (int i = 0; i < move_count; i++) {
		printf("row: %d, column: %d\n", possible_moves[i].row, possible_moves[i].column);
	}

	return 0;
}
