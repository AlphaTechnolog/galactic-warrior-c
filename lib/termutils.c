#include <stdio.h>
#include <stdlib.h>

#include "termutils.h"

void clear_screen() {
    if (system("clear") != 0) {
        fprintf(stderr, "cannot call the clear command!\n");
        exit(1);
    }
}
