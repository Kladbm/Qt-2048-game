#include "themechange.h"

#include <iostream>
#include <fstream>
#include <vector>

bool dark_theme_is_active = false;

bool Get_DarkTheme();
void ChangeTheme(Ui::MainWindow *ui);
void Change_BackgroundLabel(Ui::MainWindow *ui);

bool ThemeChange::Get_DarkThemeIsActive() {
    return dark_theme_is_active;
}

void ThemeChange::ChangeTheme_Button_Pressed(Ui::MainWindow *ui) {

    if (!dark_theme_is_active) {
        dark_theme_is_active = true;
        ui -> change_theme_button -> setStyleSheet("image: url(image/light_theme_pressed.png);"
                                            "border-radius: 0px;");
    } else {
        dark_theme_is_active = false;
        ui -> change_theme_button -> setStyleSheet("image: url(image/dark_theme_pressed.png);"
                                            "border-radius: 0px;");
    }
}

void ThemeChange::ChangeTheme_Button_Released(Ui::MainWindow *ui) {

    if (dark_theme_is_active) {
        dark_theme_is_active = true;
        ui -> change_theme_button -> setStyleSheet("image: url(image/dark_theme.png);"
                                            "border-radius: 0px;");
    } else {
        dark_theme_is_active = false;
        ui -> change_theme_button -> setStyleSheet("image: url(image/light_theme.png);"
                                            "border-radius: 0px;");
    }

    ChangeTheme(ui);
}

void ThemeChange::Set_ThemeForNewGame(Ui::MainWindow *ui) {

    // get information from file about dark theme
    dark_theme_is_active = Get_DarkTheme();

    ChangeTheme_Button_Released(ui);
}

bool Get_DarkTheme() {

    std::ifstream file("settings.txt");

    if (!file.is_open()) {
        qWarning("File is not open");
        return -1;
    }

    std::string str;
    while (getline(file, str)) {

        QString new_str = QString::fromStdString(str);

        if (new_str.indexOf("dark_theme_is_active") != -1) {

            file.close();
            return new_str.remove(0, new_str.lastIndexOf(" ") + 1) == "false" ? false : true;
        }
    }

    file.close();
    return -1;
}

void ThemeChange::Save_DarkTheme() {

    std::ifstream file_read("settings.txt");

    if (!file_read.is_open()) {
        qWarning("File is not open");
        return;
    }

    std::string line;
    std::vector<std::string> all_line;

    while (getline(file_read, line)) {

        if (QString::fromStdString(line).indexOf("dark_theme_is_active") != -1) {

            QString new_line = QString::fromStdString(line);
            std::string new_line_str = (new_line.remove(new_line.lastIndexOf(" ") + 1, new_line.size())
                                        + QString::fromStdString(dark_theme_is_active ? "true" : "false"))
                                        .toStdString();

            all_line.push_back(new_line_str);

            continue;
        }

        all_line.push_back(line);
    }

    file_read.close();

    std::ofstream file_write("settings.txt");

    if (!file_write.is_open()) {
        qWarning("File is not open");
        return;
    }

    for (const auto &line : all_line)
        file_write << line << "\n";

    file_write.close();
}

void ChangeTheme(Ui::MainWindow *ui) {

    if (dark_theme_is_active) {
        ui -> centralwidget -> setStyleSheet("background-color: #313150;");

        ui -> newGame_btn -> setStyleSheet("background-color: #888eb3;"
                                           "font-weight: bold;"
                                           "color: #484e78;"
                                           "font-family: clear sans,helvetica neue,Arial,sans-serif;");

        ui -> Score_lbl -> setStyleSheet("color: #ffffff;"
                                         "font-weight: bold;"
                                         "font-family: clear sans,helvetica neue,Arial,sans-serif;");
        ui -> Max_Score_lbl -> setStyleSheet("color: #ffffff;"
                                             "font-weight: bold;"
                                             "font-family: clear sans,helvetica neue,Arial,sans-serif;");

        ui -> try_again_btn -> setStyleSheet("background-color: #888eb3;"
                                             "font-weight: bold;"
                                             "color: #484e78;"
                                             "font-family: clear sans,helvetica neue,Arial,sans-serif;");
        ui -> frame -> setStyleSheet("background: rgba(94,94,127,.5);");

    } else {
        ui -> centralwidget -> setStyleSheet("background-color: #bbada0;");

        ui -> newGame_btn -> setStyleSheet("background-color: #8f7a66;"
                                           "font-weight: bold;"
                                           "color: #f9f6f2;"
                                           "font-family: clear sans,helvetica neue,Arial,sans-serif;");

        ui -> Score_lbl -> setStyleSheet("color: #ffffff;"
                                         "font-weight: bold;"
                                         "font-family: clear sans,helvetica neue,Arial,sans-serif;");
        ui -> Max_Score_lbl -> setStyleSheet("color: #ffffff;"
                                             "font-weight: bold;"
                                             "font-family: clear sans,helvetica neue,Arial,sans-serif;");

        ui -> try_again_btn -> setStyleSheet("background-color: #8f7a66;"
                                             "font-weight: bold;"
                                             "color: #f9f6f2;"
                                             "font-family: clear sans,helvetica neue,Arial,sans-serif;");
        ui -> frame -> setStyleSheet("background: rgba(238,228,218,.5);");
    }

    Change_BackgroundLabel(ui);
}

void Change_BackgroundLabel(Ui::MainWindow *ui) {

    if (dark_theme_is_active) {
        ui -> B11_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B12_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B13_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B14_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B21_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B22_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B23_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B24_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B31_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B32_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B33_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B34_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B41_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B42_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B43_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        ui -> B44_2 -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
    } else {
        ui -> B11_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B12_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B13_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B14_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B21_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B22_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B23_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B24_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B31_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B32_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B33_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B34_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B41_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B42_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B43_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
        ui -> B44_2 -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
    }
}

void ThemeChange::Change_Label(QLabel *target_lbl, int table_value) {

    switch (table_value) {

        case 2:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #a7aeec; color: #e0e3ff");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #eee4da; color: #776e65");
            break;

        case 4:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #969ff3; color: #e0e3ff");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #ede0c8; color: #776e65");
            break;

        case 8:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #7982f2; color: #2b2a5f");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #f2b179; color: #f9f6f2");
            break;

        case 16:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #6367f5; color: #2b2a5f");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #f59563; color: #f9f6f2");
            break;

        case 32:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #564dde; color: #2b2a5f");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #ff775c; color: #f9f6f2");
            break;

        case 64:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #583bf6; color: #2b2a5f");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #e64c2e; color: #f9f6f2");
            break;

        case 128:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #729eed; color: #2b2a5f; font-size: 38px");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #ede291; color: #f9f6f2; font-size: 38px");
            break;

        case 256:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #6163ed; color: #2b2a5f; font-size: 38px");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #fce130; color: #f9f6f2; font-size: 38px");
            break;

        case 512:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #5062ed; color: #2b2a5f; font-size: 38px");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #ffdb4a; color: #f9f6f2; font-size: 38px");
            break;

        case 1024:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #3f3fed; color: #2b2a5f; font-size: 28px");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #fad74d; color: #f9f6f2; font-size: 28px");
            break;

        case 2048:
            if (dark_theme_is_active)
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #382eed; color: #2b2a5f; font-size: 28px");
            else
                target_lbl -> setStyleSheet("border-radius: 3px; background-color: #f0b922; color: #f9f6f2; font-size: 28px");
            break;
    }
}
