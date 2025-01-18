#include "../Include/ChessMove.h"

int ChessyChessMoveGetValidMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    switch (current_chess_engine->board[row + (column * CHESSY_BOARD_SIZE)]) {
        case CHESSY_WHITE_PAWN:
        case CHESSY_BLACK_PAWN:
            return ChessyChessMoveGetValidPawnMove(current_chess_engine, row, column, possible_moves);

        case CHESSY_WHITE_ROOK:
        case CHESSY_BLACK_ROOK:
            return ChessyChessMoveGetValidRookMove(current_chess_engine, row, column, possible_moves);

        case CHESSY_WHITE_BISHOP:
        case CHESSY_BLACK_BISHOP:
            return ChessyChessMoveGetValidBishopMove(current_chess_engine, row, column, possible_moves);

        case CHESSY_WHITE_KNIGHT:
        case CHESSY_BLACK_KNIGHT:
            return ChessyChessMoveGetValidKnightMove(current_chess_engine, row, column, possible_moves);

        case CHESSY_WHITE_QUEEN:
        case CHESSY_BLACK_QUEEN:
            return ChessyChessMoveGetValidQueenMove(current_chess_engine, row, column, possible_moves);

        case CHESSY_WHITE_KING:
        case CHESSY_BLACK_KING:
            return ChessyChessMoveGetValidKingMove(current_chess_engine, row, column, possible_moves);

        default:
            break;
    }

    return -1;
}

int ChessyChessMoveGetValidPawnMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}

int ChessyChessMoveGetValidRookMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}

int ChessyChessMoveGetValidBishopMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}

int ChessyChessMoveGetValidKnightMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}

int ChessyChessMoveGetValidQueenMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}

int ChessyChessMoveGetValidKingMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    return move_count;
}