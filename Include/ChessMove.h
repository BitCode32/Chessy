#ifndef CHESSY_CHESS_MOVE
#define CHESSY_CHESS_MOVE

#include "ChessEngine.h"
#include "Bool.h"

#define CHESSY_MAX_MOVE_COUNT 27

typedef struct {
    unsigned int row, column;
    chessy_bool is_capture;
    chessy_bool is_castling;
} chessy_chess_move;

int ChessyChessMoveGetValidMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);

int ChessyChessMoveGetValidPawnMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);
int ChessyChessMoveGetValidRookMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);
int ChessyChessMoveGetValidBishopMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);
int ChessyChessMoveGetValidKnightMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);
int ChessyChessMoveGetValidQueenMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);
int ChessyChessMoveGetValidKingMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]);

#endif