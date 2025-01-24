#include "../Include/Chessy/ChessMove.h"

int ChessyChessMoveGetValidMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    switch (current_chess_engine->board[column + (row * CHESSY_BOARD_SIZE)]) {
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
    chessy_bool is_white = (current_chess_engine->current_color == CHESSY_WHITE);

    int direction, start_row;
    char opponent_piece_start, opponent_piece_end;
    if (is_white) {
        direction = -1;
        start_row = 6;

        opponent_piece_start = 'a';
        opponent_piece_end = 'z';
    } else {
        direction = 1;
        start_row = 1;

        opponent_piece_start = 'A';
        opponent_piece_end = 'Z';
    }

    unsigned int row_move = row + direction;
    unsigned int column_move = column;
    if (current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == ' ') {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_false;

        move_count++;
    }

    row_move = row + (direction * 2);
    if (row == start_row && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == ' ') {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_false;

        move_count++;
    }

    row_move = row + direction;
    column_move = column - 1;
    if (column > 0) {
        if (current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] >= opponent_piece_start && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] <= opponent_piece_end) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = chessy_true;

            move_count++;
        }

        row_move = row;
        if (is_white) {
            if (current_chess_engine->is_en_passant_white[column_move] && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == CHESSY_WHITE_PAWN) {
                possible_moves[move_count].row = row_move + direction;
                possible_moves[move_count].column = column_move;
                possible_moves[move_count].is_capture = chessy_true;

                move_count++;
            }
        } else {
            if (current_chess_engine->is_en_passant_black[column_move] && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == CHESSY_BLACK_PAWN) {
                possible_moves[move_count].row = row_move + direction;
                possible_moves[move_count].column = column_move;
                possible_moves[move_count].is_capture = chessy_true;

                move_count++;
            }
        }
    }

    row_move = row + direction;
    column_move = column + 1;
    if (column < 7) {
        if (current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] >= opponent_piece_start && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] <= opponent_piece_end) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = chessy_true;

            move_count++;
        }

        row_move = row;
        if (is_white) {
            if (current_chess_engine->is_en_passant_white[column_move] && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == CHESSY_WHITE_PAWN) {
                possible_moves[move_count].row = row_move + direction;
                possible_moves[move_count].column = column_move;
                possible_moves[move_count].is_capture = chessy_true;

                move_count++;
            }
        } else {
            if (current_chess_engine->is_en_passant_black[column_move] && current_chess_engine->board[column_move + (row_move *  CHESSY_BOARD_SIZE)] == CHESSY_BLACK_PAWN) {
                possible_moves[move_count].row = row_move + direction;
                possible_moves[move_count].column = column_move;
                possible_moves[move_count].is_capture = chessy_true;

                move_count++;
            }
        }
    }

    current_chess_engine->is_en_passant_white;
    current_chess_engine->is_en_passant_black;

    return move_count;
}

int ChessyChessMoveGetValidRookMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    char opponent_piece_start, opponent_piece_end;
    if (current_chess_engine->current_color == CHESSY_WHITE) {
        opponent_piece_start = 'a';
        opponent_piece_end = 'z';
    } else {
        opponent_piece_start = 'A';
        opponent_piece_end = 'Z';
    }
    
    int row_move = row + 1;
    int index = column + (row_move * CHESSY_BOARD_SIZE);
    while (row_move < CHESSY_BOARD_SIZE && current_chess_engine->board[index] == ' ') {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column;
        possible_moves[move_count].is_capture = chessy_false;

        row_move++;
        index = column + (row_move * CHESSY_BOARD_SIZE);
        move_count++;
    }

    if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column;
        possible_moves[move_count].is_capture = chessy_true;

        move_count++;
    }

    row_move = row - 1;
    index = column + (row_move * CHESSY_BOARD_SIZE);
    while (row_move >= 0 && current_chess_engine->board[index] == ' ') {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column;
        possible_moves[move_count].is_capture = chessy_false;

        row_move--;
        index = column + (row_move * CHESSY_BOARD_SIZE);

        move_count++;
    }

    if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column;
        possible_moves[move_count].is_capture = chessy_true;

        move_count++;
    }

    int column_move = column + 1;
    index = column_move + (row * CHESSY_BOARD_SIZE);
    while (column_move < CHESSY_BOARD_SIZE && current_chess_engine->board[index] == ' ') {
        possible_moves[move_count].row = row;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_false;

        column_move++;
        index = column_move + (row * CHESSY_BOARD_SIZE);

        move_count++;
    }

    if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
        possible_moves[move_count].row = row;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_true;

        move_count++;
    }

    column_move = column - 1;
    index = column_move + (row * CHESSY_BOARD_SIZE);
    while (column_move >= 0 && current_chess_engine->board[index] == ' ') {
        possible_moves[move_count].row = row;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_false;

        column_move--;
        index = column_move + (row * CHESSY_BOARD_SIZE);

        move_count++;
    }

    if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
        possible_moves[move_count].row = row;
        possible_moves[move_count].column = column_move;
        possible_moves[move_count].is_capture = chessy_true;

        move_count++;
    }

    return move_count;
}

int ChessyChessMoveGetValidBishopMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;

    char own_piece_start, own_piece_end;
    char opponent_piece_start, opponent_piece_end;
    if (current_chess_engine->current_color == CHESSY_WHITE) {
        own_piece_start = 'A';
        own_piece_end = 'Z';

        opponent_piece_start = 'a';
        opponent_piece_end = 'z';
    } else {
        own_piece_start = 'a';
        own_piece_end = 'z';

        opponent_piece_start = 'A';
        opponent_piece_end = 'Z';
    }

    chessy_bool hit_opponent = chessy_false;

    int row_move = row + 1;
    int column_move = column + 1;
    int index = column_move + (row_move * CHESSY_BOARD_SIZE);
    while (!hit_opponent && row_move < CHESSY_BOARD_SIZE && column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;

        if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
            possible_moves[move_count].is_capture = chessy_true;
            hit_opponent = chessy_true;
        } else {
            possible_moves[move_count].is_capture = chessy_false;

            row_move++;
            column_move++;
            index = column_move + (row_move * CHESSY_BOARD_SIZE);
        }
        
        move_count++;
    }

    hit_opponent = chessy_false;

    row_move = row - 1;
    column_move = column + 1;
    index = column_move + (row_move * CHESSY_BOARD_SIZE);
    while (!hit_opponent && row_move >= 0 && column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;

        if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
            possible_moves[move_count].is_capture = chessy_true;
            hit_opponent = chessy_true;
        } else {
            possible_moves[move_count].is_capture = chessy_false;

            row_move--;
            column_move++;
            index = column_move + (row_move * CHESSY_BOARD_SIZE);
        }
        
        move_count++;
    }

    hit_opponent = chessy_false;

    row_move = row + 1;
    column_move = column - 1;
    index = column_move + (row_move * CHESSY_BOARD_SIZE);
    while (!hit_opponent && row_move < CHESSY_BOARD_SIZE && column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;

        if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
            possible_moves[move_count].is_capture = chessy_true;
            hit_opponent = chessy_true;
        } else {
            possible_moves[move_count].is_capture = chessy_false;

            row_move++;
            column_move--;
            index = column_move + (row_move * CHESSY_BOARD_SIZE);
        }
        
        move_count++;
    }

    hit_opponent = chessy_false;

    row_move = row - 1;
    column_move = column - 1;
    index = column_move + (row_move * CHESSY_BOARD_SIZE);
    while (!hit_opponent && row_move >= 0 && column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
        possible_moves[move_count].row = row_move;
        possible_moves[move_count].column = column_move;

        if (current_chess_engine->board[index] >= opponent_piece_start && current_chess_engine->board[index] <= opponent_piece_end) {
            possible_moves[move_count].is_capture = chessy_true;
            hit_opponent = chessy_true;
        } else {
            possible_moves[move_count].is_capture = chessy_false;

            row_move--;
            column_move--;
            index = column_move + (row_move * CHESSY_BOARD_SIZE);
        }
        
        move_count++;
    }

    return move_count;
}

int ChessyChessMoveGetValidKnightMove(chessy_chess_engine *current_chess_engine, int row, int column, chessy_chess_move possible_moves[CHESSY_MAX_MOVE_COUNT]) {
    int move_count = 0;
    
    char own_piece_start, own_piece_end;
    if (current_chess_engine->current_color == CHESSY_WHITE) {
	    own_piece_start = 'A';
	    own_piece_end = 'Z';
    } else {
	    own_piece_start = 'a';
	    own_piece_end = 'z';
    }

    int row_move = row + 1;
    int column_move = column + 2;
    int index = column_move + (row_move * CHESSY_BOARD_SIZE);
    if (row_move < CHESSY_BOARD_SIZE) {
        if (column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }

        column_move = column - 2;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }
    }

    row_move = row + 2;
    if (row_move < CHESSY_BOARD_SIZE) {
        column_move = column + 1;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }

        column_move = column - 1;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }
    }

    row_move = row - 1;
    if (row_move >= 0) {
        column_move = column + 2;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }

        column_move = column - 2;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }
    }

    row_move = row - 2;
    if (row_move >= 0) {
        column_move = column + 1;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move < CHESSY_BOARD_SIZE && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }

        column_move = column - 1;
        index = column_move + (row_move * CHESSY_BOARD_SIZE);
        if (column_move >= 0 && (current_chess_engine->board[index] < own_piece_start || current_chess_engine->board[index] > own_piece_end)) {
            possible_moves[move_count].row = row_move;
            possible_moves[move_count].column = column_move;
            possible_moves[move_count].is_capture = (current_chess_engine->board[index] != ' ');

            move_count++;
        }
    }

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
