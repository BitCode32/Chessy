#ifndef CHESSY_CHESS_AI
#define CHESSY_CHESS_AI

#include "ChessEngine.h"

typedef struct {
    char selected[2];
    char move[2];
} chessy_chess_ai_move;

chessy_chess_ai_move ChessyChessAIGetNextMove(chessy_chess_engine *current_chess_engine, int difficulty);

#endif