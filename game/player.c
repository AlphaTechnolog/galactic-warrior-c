#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include "board.h"
#include "player.h"
#include "../lib/termutils.h"

Player *create_player(char **board) {
    Player *player = malloc(sizeof(Player));
    player->board = board;
    player->x = 0;
    player->y = (int) round(BOARD_HEIGHT / 2); // rounding is to make sure.
    return player;
}

void display_player(Player *player) {
    player->board[player->y][player->x] = PLAYER;
    clear_screen();
    display_board(player->board);
}

void move_player(Player *player, int amount) {
    player->board[player->y][player->x] = VOID;
    player->y += amount;

    if (player->y < 0) player->y = 0;
    if (player->y > BOARD_HEIGHT - 1) player->y = BOARD_HEIGHT - 1;

    player->board[player->y][player->x] = PLAYER;

    display_player(player);
}

void* allow_player_movement(void *arg) {
    Player *player = (Player*) arg;

    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\033') {
            getchar();
            switch (getchar()) {
                case 'A':
                    move_player(player, -1); // up
                    break;
                case 'B':
                    move_player(player, 1); // down
                    break;
            }
        }
    }
}

void initialize_user_thread(Player *player) {
    pthread_t player_movement_thread;

    if (pthread_create(&player_movement_thread, NULL, allow_player_movement, player) != 0) {
        fprintf(stderr, "cannot create player movement thread!\n");
        exit(1);
    }

    pthread_join(player_movement_thread, NULL);
}
