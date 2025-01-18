#include <stdio.h>
#include "../Include/ChessEngine/ChessEngine.h"

int main() {
	chessy_chess_engine main_engine;
	ChessyChessEngineInitialize(&main_engine);

	for (int y = 0; y < CHESSY_BOARD_SIZE; y++) {
		for (int x = 0; x < CHESSY_BOARD_SIZE; x++) {
			printf("%c", main_engine.board[x + (y * CHESSY_BOARD_SIZE)]);
		}
		printf("\n");
	}
	return 0;
}
