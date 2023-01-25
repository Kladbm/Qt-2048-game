#ifndef GAMESTATUSCHECK_H
#define GAMESTATUSCHECK_H


class GameStatusCheck
{
public:
    static int Check_Win(const int ARRAY_SIZE, const int table_values[]);
    static int Check_Lose(const int ARRAY_SIZE, const int table_values[]);
    static int Check_TableIsFull(const int ARRAY_SIZE, const int table_values[]);
};

#endif // GAMESTATUSCHECK_H
