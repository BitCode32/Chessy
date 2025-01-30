#include <stdio.h>
#include <Chessy/ChessEngine.h>
#include <Chessy/ChessMove.h>
#include <Chessy/ChessAI.h>

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
		player_select[0] = (char)getchar();
		player_select[1] = (char)getchar();
		player_move[0] = (char)getchar();
		player_move[1] = (char)getchar();
		while (getchar() != '\n');

		if (!ChessyChessEngineMove(&main_engine, player_select, player_move)) {
			if (player_select[0] == 'u' && player_select[1] == 'n' && player_move[0] == 'd' && player_move[1] == 'o') {
				if (!ChessyChessEngineUndoMove(&main_engine)) {
					printf("Can't undo move\n");
				}
			} else {
				printf("Invalid Move!\n");
			}
		} else {
			chessy_chess_ai_move ai_move = ChessyChessAIGetNextMove(&main_engine, CHESSY_DIFFICULTY_INTERMEDIATE);
			ChessyChessEngineMove(&main_engine, ai_move.selected, ai_move.move);
		}
	}

	return 0;
}
