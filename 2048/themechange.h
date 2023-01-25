#ifndef THEMECHANGE_H
#define THEMECHANGE_H

#include "ui_mainwindow.h"


class ThemeChange
{
public:
    static void ChangeTheme_Button_Pressed(Ui::MainWindow *ui);
    static void ChangeTheme_Button_Released(Ui::MainWindow *ui);

    static void Set_ThemeForNewGame(Ui::MainWindow *ui);
    static bool Get_DarkThemeIsActive();
    static void Save_DarkTheme();

    static void Change_Label(QLabel *target_lbl, int table_value);

};

#endif // THEMECHANGE_H
