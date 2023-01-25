#include "gamestatuscheck.h"

int GameStatusCheck::Check_Win(const int ARRAY_SIZE, const int table_values[]) {

    for (int i = 0; i < ARRAY_SIZE; i++)
        if (table_values[i] == 2048)
            return 1;

    return 0;
}

int GameStatusCheck::Check_Lose(const int ARRAY_SIZE, const int table_values[]) {

    if (!GameStatusCheck::Check_TableIsFull(ARRAY_SIZE, table_values)) {
        return 0;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i + 1 < ARRAY_SIZE && (i + 1) % 4 != 0 && table_values[i] == table_values[i + 1])
            return 0;
        if (i + 4 < ARRAY_SIZE && table_values[i] == table_values[i + 4])
            return 0;
    }

    return 1;
}

int GameStatusCheck::Check_TableIsFull(const int ARRAY_SIZE, const int table_values[]) {

    for (int i = 0; i < ARRAY_SIZE; i++)
        if (table_values[i] == 0)
            return 0;

    return 1;
}
