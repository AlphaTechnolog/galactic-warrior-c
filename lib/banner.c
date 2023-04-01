#include <stdio.h>

#include "banner.h"
#include "termutils.h"

// NOTE: remember that \\ is \\\\ so that's why it looks in the code kinda huh, weird.
void display_banner() {
    clear_screen();
    printf("  ____       _            _   _       __        __              _            \n");
    printf(" / ___| __ _| | __ _  ___| |_(_) ___  \\ \\      / /_ _ _ __ _ __(_) ___  _ __ \n");
    printf("| |  _ / _` | |/ _` |/ __| __| |/ __|  \\ \\ /\\ / / _` | '__| '__| |/ _ \\| '__|\n");
    printf("| |_| | (_| | | (_| | (__| |_| | (__    \\ V  V / (_| | |  | |  | | (_) | |   \n");
    printf(" \\____|\\__,_|_|\\__,_|\\___|\\__|_|\\___|    \\_/\\_/ \\__,_|_|  |_|  |_|\\___/|_|   \n\n");
}
