#ifndef BOARD_H
#define BOARD_H

// dimensions
#define BOARD_WIDTH 70 + 1 // +1 cuz null character
#define BOARD_HEIGHT 7

// components
#define PLAYER '>'
#define BULLET '*'
#define ENEMY  '&'
#define VOID   ' '

// functions
char **get_board();
void display_board(char **board);

#endif
