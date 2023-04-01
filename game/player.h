#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char **board;
    int x;
    int y;
} Player;

Player *create_player(char **board);
void display_player(Player *player);
void initialize_user_thread(Player *player);

#endif
