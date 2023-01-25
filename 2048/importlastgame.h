#ifndef IMPORTLASTGAME_H
#define IMPORTLASTGAME_H

class ImportLastGame
{
public:
    static void Set_CriticalPrograTermination(bool value);
    static bool Return_CriticalPrograTermination();

    static void Set_TableValues(int* array);
    static int* Return_TableValues();

    static void Get_TableValuesFromMW();
    static void Get_CriticalPrograTerminationFromMW();

};

#endif // IMPORTLASTGAME_H
