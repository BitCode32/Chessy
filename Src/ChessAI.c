#include "../Include/Chessy/ChessAI.h"
#include "../Include/Chessy/ChessMove.h"

static int MiniMax(chessy_chess_engine *current_chess_engine, int depth, chessy_chess_ai_move *best_move);

chessy_chess_ai_move ChessyChessAIGetNextMove(chessy_chess_engine *current_chess_engine, int difficulty) {
    chessy_chess_ai_move best_move;
    MiniMax(current_chess_engine, difficulty, &best_move);

    return best_move;
}

// TODO: improve + alpha beta pruning
static int MiniMax(chessy_chess_engine *current_chess_engine, int depth, chessy_chess_ai_move *best_move) {
    if (depth == 0) {
        return current_chess_engine->total_game_score;
    }

    chessy_bool is_maximizing = (current_chess_engine->current_color == CHESSY_WHITE);
    int best_possible_score = (is_maximizing) ? -1000 : 1000;

    for (unsigned int row = 0; row < CHESSY_BOARD_SIZE; row++) {
        for (unsigned int column = 0; column < CHESSY_BOARD_SIZE; column++) {
            chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT];
            int move_count = ChessyChessMoveGetValidMove(current_chess_engine, row, column, possible_moves);   

            char selected[2] = { 'a' + (char)column, '8' - (char)row };
            for (int move_index = 0; move_index < move_count; move_index++) {
                char move[2] = { 'a' + (char)possible_moves[move_index].column, '8' - (char)possible_moves[move_index].row };
                ChessyChessEngineMove(current_chess_engine, selected, move);
                int move_score = MiniMax(current_chess_engine, depth - 1, (void*)0);
                ChessyChessEngineUndoMove(current_chess_engine);

                if (is_maximizing) {
                    if (move_score >= best_possible_score) {
                        if (best_move) {
                            best_move->selected[0] = selected[0];
                            best_move->selected[1] = selected[1];

                            best_move->move[0] = move[0];
                            best_move->move[1] = move[1];
                        }

                        best_possible_score = move_score;
                    }
                } else {
                    if (move_score <= best_possible_score) {
                        if (best_move) {
                            best_move->selected[0] = selected[0];
                            best_move->selected[1] = selected[1];

                            best_move->move[0] = move[0];
                            best_move->move[1] = move[1];
                        }

                        best_possible_score = move_score;
                    }
                }
            }
        }
    }

    return best_possible_score;
}