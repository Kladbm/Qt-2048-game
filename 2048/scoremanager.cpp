#include "scoremanager.h"

#include <fstream>
#include <vector>

int total_score = 0;
int max_score = 0;

void Set_MaxScore(Ui::MainWindow *ui, int score);
int Get_MaxScore();
int Get_TotalScore();

void ScoreManager::UpdateScore(Ui::MainWindow *ui, bool test) {

    if (test)
        total_score = Get_TotalScore();
    else
        total_score = 0;
    ui -> Score_lbl -> setText(QString("Score: ") + QString::number(total_score));
    max_score = Get_MaxScore();
    ui -> Max_Score_lbl -> setText(QString("Max score: " + QString::number(max_score)));
}

void ScoreManager::SetScore(Ui::MainWindow *ui, int score) {

    total_score += score;

    ui -> Score_lbl -> setText(QString("Score: " + QString::number(total_score)));

    if (max_score <= total_score)
        Set_MaxScore(ui, total_score);
}

void Set_MaxScore(Ui::MainWindow *ui, int total_score) {

    max_score = total_score;

    ui -> Max_Score_lbl -> setText(QString("Max score: " + QString::number(max_score)));
}

int Get_MaxScore() {

    std::ifstream file("settings.txt");

    if (!file.is_open()) {
        qWarning("File is not open");
        return -1;
    }

    std::string str;
    while (getline(file, str)) {

        QString new_str = QString::fromStdString(str);

        if (new_str.indexOf("max_score") != -1) {

            file.close();
            return new_str.remove(0, new_str.lastIndexOf(" ") + 1).toInt();
        }
    }

    file.close();
    return -1;
}

void ScoreManager::Save_MaxScore() {

    std::ifstream file_read("settings.txt");

    if (!file_read.is_open()) {
        qWarning("File is not open");
        return;
    }

    std::string line;
    std::vector<std::string> all_line;

    while (getline(file_read, line)) {

        if (QString::fromStdString(line).indexOf("max_score") != -1) {

            QString new_line = QString::fromStdString(line);
            std::string new_line_str = (new_line.remove(new_line.lastIndexOf(" ") + 1, new_line.size())
                                        + QString::number(max_score)).toStdString();

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

int Get_TotalScore() {

    std::ifstream file("settings.txt");

    if (!file.is_open()) {
        qWarning("File is not open");
        return -1;
    }

    std::string str;
    while (getline(file, str)) {

        QString new_str = QString::fromStdString(str);

        if (new_str.indexOf("total_score") != -1) {

            file.close();
            return new_str.remove(0, new_str.lastIndexOf(" ") + 1).toInt();
        }
    }

    file.close();
    return -1;
}

void ScoreManager::Save_TotalScore() {

    std::ifstream file_read("settings.txt");

    if (!file_read.is_open()) {
        qWarning("File is not open");
        return;
    }

    std::string line;
    std::vector<std::string> all_line;

    while (getline(file_read, line)) {

        if (QString::fromStdString(line).indexOf("total_score") != -1) {

            QString new_line = QString::fromStdString(line);
            std::string new_line_str = (new_line.remove(new_line.lastIndexOf(" ") + 1, new_line.size())
                                        + QString::number(total_score)).toStdString();

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
