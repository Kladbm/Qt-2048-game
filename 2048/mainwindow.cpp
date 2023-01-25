#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scoremanager.h"
#include "gamestatuscheck.h"
#include "themechange.h"
#include "importlastgame.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QThread>
#include <QProcess>

#include <iostream>

#define ARRAY_SIZE 16
#define ANIMATION_DURATION 100

int table_values[ARRAY_SIZE] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};
int current_table_values[ARRAY_SIZE];
QRect array[ARRAY_SIZE];

bool game_is_crashed = false;
bool game_is_active = false;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui -> setupUi(this);
    ui -> frame -> setVisible(false);

    all_label_geometry();

    ThemeChange::Set_ThemeForNewGame(ui);

    if (ImportLastGame::Return_CriticalPrograTermination()) {
        int* buf_array = ImportLastGame::Return_TableValues();

        for (int i = 0; i < ARRAY_SIZE; i++)
            table_values[i] = buf_array[i];

        game_is_crashed = true;
    }

    NewGame();
}

MainWindow::~MainWindow() {

    ScoreManager::Save_TotalScore();
    ScoreManager::Save_MaxScore();
    ThemeChange::Save_DarkTheme();

    if (game_is_active)
        ImportLastGame::Set_CriticalPrograTermination(true);
    else
        ImportLastGame::Set_CriticalPrograTermination(false);

    ImportLastGame::Set_TableValues(table_values);

    delete ui;
}


QLabel *MainWindow::indexToQLabel(int index) {

    QLabel *lbl;

    switch (index) {
        case 0:
            lbl = ui -> B11; break;
        case 1:
            lbl = ui -> B12; break;
        case 2:
            lbl = ui -> B13; break;
        case 3:
            lbl = ui -> B14; break;
        case 4:
            lbl = ui -> B21; break;
        case 5:
            lbl = ui -> B22; break;
        case 6:
            lbl = ui -> B23; break;
        case 7:
            lbl = ui -> B24; break;
        case 8:
            lbl = ui -> B31; break;
        case 9:
            lbl = ui -> B32; break;
        case 10:
            lbl = ui -> B33; break;
        case 11:
            lbl = ui -> B34; break;
        case 12:
            lbl = ui -> B41; break;
        case 13:
            lbl = ui -> B42; break;
        case 14:
            lbl = ui -> B43; break;
        case 15:
            lbl = ui -> B44; break;
    }

    return lbl;
}

void MainWindow::all_label_geometry() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        QLabel *animation_lbl = indexToQLabel(i);

        array[i] = animation_lbl -> geometry();
    }
}

void MainWindow::all_label_geometry_check() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        QLabel *animation_lbl = indexToQLabel(i);

        if (array[i] != animation_lbl -> geometry())
            animation_lbl -> setGeometry(array[i]);
    }
}

// animation for creating new grid item - new label
void MainWindow::CreateLabelAnimation(int target_index) {
    QLabel *animation_lbl = indexToQLabel(target_index); // target_index to label widget
    QPropertyAnimation *animation = new QPropertyAnimation(animation_lbl, "geometry");
    animation -> setDuration(ANIMATION_DURATION);
    animation -> setStartValue(QRect(animation_lbl->x() + 47, animation_lbl->y() + 47, 4, 4));
    animation -> setEndValue(QRect(animation_lbl->x(), animation_lbl->y(), 98, 98));
    animation -> start();
}


void MainWindow::ResizeLabelAnimation(int target_index) {

     QLabel *animation_lbl = indexToQLabel(target_index);
     QPropertyAnimation *animation = new QPropertyAnimation(animation_lbl, "geometry");
     animation -> setDuration(ANIMATION_DURATION);
     animation -> setStartValue(QRect(animation_lbl->x(), animation_lbl->y(), 98, 98));
     animation -> setEndValue(QRect(animation_lbl->x() - 5, animation_lbl->y() - 5, 108, 108));
     animation -> start();

     connect(animation, & QPropertyAnimation::finished, this, [this, animation_lbl, target_index] {
         QLabel *animation_lbl = indexToQLabel(target_index);
         QPropertyAnimation *animation = new QPropertyAnimation(animation_lbl, "geometry");
         animation -> setDuration(ANIMATION_DURATION);
         animation -> setStartValue(QRect(animation_lbl->x(), animation_lbl->y(), 108, 108));
         animation -> setEndValue(QRect(animation_lbl->x() + 5, animation_lbl->y() + 5, 98, 98));
         animation -> start();
     });
}

void MainWindow::AnimationC(int source_index, int target_index) {

    QLabel *startL = indexToQLabel(source_index);
    QLabel *endL = indexToQLabel(target_index);
    QLabel *tempLabel = new QLabel();
    tempLabel -> setGeometry(endL -> geometry());
    this -> layout() -> addWidget(tempLabel);
    if (ThemeChange::Get_DarkThemeIsActive())
        tempLabel -> setStyleSheet("background-color: rgba(94,94,127,.35); border-radius: 3px;");
    else
        tempLabel -> setStyleSheet("background-color: rgba(238,228,218,.35); border-radius: 3px;");
    tempLabel -> show();
    endL -> hide();

    QLabel *animation_lbl = new QLabel();
    animation_lbl -> setText(endL -> text());
    animation_lbl -> setStyleSheet(endL -> styleSheet());
    animation_lbl -> setFont(endL -> font());
    animation_lbl -> setAlignment(endL -> alignment());

    this -> layout() -> addWidget(animation_lbl);
    animation_lbl -> show();

    QPropertyAnimation *animation = new QPropertyAnimation(animation_lbl, "geometry");
    animation -> setDuration(ANIMATION_DURATION);
    animation -> setStartValue(startL -> geometry());
    animation -> setEndValue(endL -> geometry());
    animation -> start();

    connect(animation, & QPropertyAnimation::finished, this, [animation_lbl, endL, tempLabel] {
        delete animation_lbl;
        delete tempLabel;
        endL -> show();
    });
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (ui -> frame -> isVisible() == 0) {
        game_is_active = true;

        all_label_geometry_check();
        currentTable();

        switch (event -> key()) {

            case 1042:
            case Qt::Key_D:
                goRight();
                break;

            case 1030:
            case 1067:
            case Qt::Key_S:
                goDown();
                break;

            case 1060:
            case Qt::Key_A:
                goLeft();
                break;

            case 1062:
            case Qt::Key_W:
                goTop();
                break;
        }

        if (move_is_over())
            return;
        StartNewPoint();
    }
}

void MainWindow::currentTable() {
    for (int i = 0; i < ARRAY_SIZE; i++)
        current_table_values[i] = table_values[i];
}

int MainWindow::move_is_over() {
    for (int i = 0; i < ARRAY_SIZE; i++)
        if (table_values[i] != current_table_values[i])
            return 0;

    return 1;
}

void MainWindow::goRight() {

    for (int row_number = 1; row_number <= 4; row_number++) {

        int last_index = (row_number * 4) - 4;
        int first_index = (row_number * 4) - 1;

        for (int rowCounter = first_index; rowCounter >= last_index; rowCounter--) {
            int min = 100, max = 0, maC = -1;
            if (rowCounter <= first_index) {
                for ( ; table_values[rowCounter] != 0 and table_values[rowCounter + 1] == 0 and rowCounter < first_index; rowCounter++) {

                    setValue_on_Gridindex(rowCounter + 1, table_values[rowCounter], rowCounter);
                    setValue_on_Gridindex(rowCounter, -1, rowCounter);

                    if (rowCounter + 1 > max)
                        max = rowCounter + 1;
                    if (maC == -1)
                        min = rowCounter;
                    maC++;
                }
                if (max != 0)
                    AnimationC(min, max);
            }
        }

        for (int x = first_index; x > last_index; x--) {
            if (table_values[x] == table_values[x - 1] and table_values[x] != 0 and table_values[x] % 2 == 0 and table_values[x] > 0) {
                ScoreManager::SetScore(ui, 2 * table_values[x]);
                ResizeLabelAnimation(x);
                setValue_on_Gridindex(x, 2 * table_values[x], x);
                setValue_on_Gridindex(x - 1, -1, x);
                for (int q = x - 1; q >= last_index; q--) {
                    if (table_values[q] != 0 and table_values[q + 1] == 0) {
                        setValue_on_Gridindex(q + 1, table_values[q], q);
                        setValue_on_Gridindex(q, -1, q);
                    }
                }
                if (table_values[x - 1] != table_values[x - 2])
                    x--;
            }
        }
    }
}

void MainWindow::goLeft() {

    for (int row_number = 1; row_number <= 4; row_number++) {

        int last_index = (row_number * 4) - 1;
        int first_index = (row_number * 4) - 4;

        for (int rowCounter = first_index; rowCounter <= last_index; rowCounter++) {
            int min = 100, max = 0, maC = -1;
            if (rowCounter >= first_index) {
                for ( ; table_values[rowCounter] != 0 and table_values[rowCounter - 1] == 0 and rowCounter > first_index; rowCounter--) {

                    setValue_on_Gridindex(rowCounter - 1, table_values[rowCounter], rowCounter);
                    setValue_on_Gridindex(rowCounter, -1, rowCounter);

                    if (rowCounter < min)
                        min = rowCounter;
                    if (maC == -1)
                        max = rowCounter;
                    maC++;
                }
                if (max != 0)
                    AnimationC(max, min - 1);
            }
        }

        for (int x = first_index; x < last_index; x++) {
            if (table_values[x] == table_values[x + 1] and table_values[x] != 0 and table_values[x] % 2 == 0 and table_values[x] > 0) {
                ScoreManager::SetScore(ui, 2 * table_values[x]);
                ResizeLabelAnimation(x);
                setValue_on_Gridindex(x, 2 * table_values[x], x);
                setValue_on_Gridindex(x + 1, -1, x);
                for (int q = x + 1; q <= last_index; q++) {
                    if (table_values[q] != 0 and table_values[q - 1] == 0) {
                        setValue_on_Gridindex(q - 1, table_values[q], q);
                        setValue_on_Gridindex(q, -1, q);
                    }
                }
                if (table_values[x + 1] != table_values[x + 2])
                    x++;
            }
        }
    }
}

void MainWindow::goDown() {

    for (int column_number = 1; column_number <= 4; column_number++) {

        int first_index = column_number + 11;
        int last_index = column_number - 1;

        int min = 0, max = 0, miC = 0;

        for (int x = first_index; x >= last_index; x = x - 4) {
            for (int y = x; y < first_index; y = y + 4) {
                if (table_values[y + 4] == 0 and table_values[y] != 0) {
                    if (y > max)
                        max = y;
                    if (miC == 0)
                        min = y;
                    miC++;

                    setValue_on_Gridindex(y + 4, table_values[y], y);
                    setValue_on_Gridindex(y, -1, y);
                }
            }
            if (max != 0) {
                AnimationC(min, max + 4);
            }
        }

        for (int x = first_index; x > last_index; x -= 4) {
            if (table_values[x] == table_values[x - 4] and table_values[x] > 0 and table_values[x] % 2 == 0) {
                ScoreManager::SetScore(ui, 2 * table_values[x]);
                ResizeLabelAnimation(x);
                setValue_on_Gridindex(x, 2 * table_values[x], x);
                setValue_on_Gridindex(x - 4, -1, x);
                for (int q = x - 4; q >= last_index; q = q - 4) {
                    if (table_values[q] != 0 and table_values[q + 4] == 0) {
                        setValue_on_Gridindex(q + 4, table_values[q], q);
                        setValue_on_Gridindex(q, -1, q);
                    }
                }
                if (table_values[x - 4] != table_values[x - 8])
                    x = x - 4;
            }
        }
    }
}

void MainWindow::goTop() {

    for (int column_number = 1; column_number <= 4; column_number++) {
        int first_index = column_number - 1;
        int last_index = column_number + 11;
        int min = 100, max = 0;

        for (int p = first_index; p <= last_index; p += 4) {
            for (int q = p; q > first_index; q = q - 4) {
                if (table_values[q] != 0 and table_values[q - 4] == 0) {
                    if (q > max)
                        max = q;

                    if (min > q)
                        min = q;

                    setValue_on_Gridindex(q - 4, table_values[q], q);
                    setValue_on_Gridindex(q, -1, q);
                }
            }
            if (max != 0)
                AnimationC(max, min - 4);
        }

        for (int x = first_index; x < last_index; x += 4) {
            if (table_values[x] == table_values[x + 4] and table_values[x] > 0 and table_values[x] % 2 == 0) {
                ScoreManager::SetScore(ui, 2 * table_values[x]);
                ResizeLabelAnimation(x);
                setValue_on_Gridindex(x, 2 * table_values[x], x);
                setValue_on_Gridindex(x + 4, -1, x);
                for (int q = x + 4; q <= last_index; q = q + 4) {
                    if (table_values[q] != 0 and table_values[q - 4] == 0) {
                        setValue_on_Gridindex(q - 4, table_values[q], q);
                        setValue_on_Gridindex(q, -1, q);
                    }
                }
                if (table_values[x + 4] != table_values[x + 8])
                    x = x + 4;
            }
        }
    }
}

int MainWindow::generate_random_index() {

    int num;

    do num = rand() % ARRAY_SIZE;
    while (table_values[num] != 0);

    return num;
}

void MainWindow::setValue_on_Gridindex(int index, int value, int source_index) {

    if (value != -1)
        table_values[index] = value;
    else
        table_values[index] = 0;

    if (source_index == -1)
        set_Config_onLabel_byIndex(indexToQLabel(index), index, -1);
    else
        set_Config_onLabel_byIndex(indexToQLabel(index), index, 1);
}

void MainWindow::set_Config_onLabel_byIndex(QLabel *target_lbl, int index, int isCreate) {

    if (table_values[index] != 0) {

        if (isCreate == -1)
            CreateLabelAnimation(index);
        target_lbl -> setText(QString::number(table_values[index]));

        ThemeChange::Change_Label(target_lbl, table_values[index]);

    } else {
        target_lbl -> setText(QString(" "));
        if (ThemeChange::Get_DarkThemeIsActive())
            target_lbl -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
        else
            target_lbl -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
    }
}

void MainWindow::OpenMenu(int won) {

    game_is_active = false;

    ui -> frame -> setVisible(true);

    if (won)
        ui -> status_label -> setText(QString("You Won"));
    else
        ui -> status_label -> setText(QString("Game Over!"));
}

void MainWindow::StartNewPoint() {

    if (GameStatusCheck::Check_Win(ARRAY_SIZE, table_values)){
        OpenMenu(1);
        return;
    }

    if (GameStatusCheck::Check_Lose(ARRAY_SIZE, table_values)) {
        OpenMenu(0);
        return;
    }

    if (GameStatusCheck::Check_TableIsFull(ARRAY_SIZE, table_values))
        return;

    int rand_index = generate_random_index();

    int rand_value = rand() % 10 < 9 ? 2 : 4;
    setValue_on_Gridindex(rand_index, rand_value, -1);

    if (GameStatusCheck::Check_Lose(ARRAY_SIZE, table_values))
        OpenMenu(0);
}

void MainWindow::NewGame() {

    time_t t;
    srand((unsigned) time(&t));

    if (game_is_crashed) {

        game_is_active = true;

        for (int i = 0; i < ARRAY_SIZE; i++)
            setValue_on_Gridindex(i, table_values[i] != 0 ? table_values[i] : -1, i);

        if (GameStatusCheck::Check_Win(ARRAY_SIZE, table_values)){
            OpenMenu(1);
            return;
        }

        if (GameStatusCheck::Check_Lose(ARRAY_SIZE, table_values)) {
            OpenMenu(0);
            return;
        }
    } else {

        game_is_active = false;

        for (int i = 0; i < ARRAY_SIZE; i++)
            setValue_on_Gridindex(i, -1, i);

        StartNewPoint();
        StartNewPoint();
    }

    ScoreManager::UpdateScore(ui, game_is_crashed);

    game_is_crashed = false;
}

void MainWindow::on_newGame_btn_clicked() {

    ScoreManager::Save_MaxScore();

    NewGame();
}

void MainWindow::on_try_again_btn_clicked() {

    ScoreManager::Save_MaxScore();

    ui -> frame -> setVisible(false);
    NewGame();
}

void MainWindow::on_change_theme_button_pressed() {

    ThemeChange::ChangeTheme_Button_Pressed(ui);
}


void MainWindow::on_change_theme_button_released() {

    for (int i = 0; i < ARRAY_SIZE; i++) {

        QLabel *target_lbl = indexToQLabel(i);

        if (table_values[i] != 0)
            ThemeChange::Change_Label(target_lbl, table_values[i]);
        else
            if (ThemeChange::Get_DarkThemeIsActive())
                target_lbl -> setStyleSheet("background-color: #5e5e7f; border-radius: 3px;");
            else
                target_lbl -> setStyleSheet("background-color: #cdc1b4; border-radius: 3px;");
    }

    ThemeChange::ChangeTheme_Button_Released(ui);
}

/*
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto tm_duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Took " << tm_duration << " microseconds " << std::endl;
 */
