#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include "ui_mainwindow.h"


class ScoreManager
{
public:
    static void UpdateScore(Ui::MainWindow *ui, bool test);
    static void SetScore(Ui::MainWindow *ui, int score);

    static void Save_MaxScore();
    static void Save_TotalScore();
};

#endif // SCOREMANAGER_H
