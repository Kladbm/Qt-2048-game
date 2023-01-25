#include "importlastgame.h"

#include <QtDebug>

#include <fstream>
#include <vector>

#define ARRAY_SIZE 16

bool critical_program_termination = false;
int table_values_[ARRAY_SIZE];

bool Get_CriticalPrograTermination();
int* Get_TableValues();
int* Return_Array(std::string line);

bool ImportLastGame::Return_CriticalPrograTermination() {

    critical_program_termination = Get_CriticalPrograTermination();

    return critical_program_termination;
}

int* ImportLastGame::Return_TableValues() {

    int* table_value = Get_TableValues();

    for (int i = 0; i < ARRAY_SIZE; i++)
        table_values_[i] = table_value[i];

    return table_value;
}

bool Get_CriticalPrograTermination() {

    std::ifstream file("settings.txt");

    if (!file.is_open()) {
        qWarning("File is not open");
        return false;
    }

    std::string str;
    while (getline(file, str)) {

        QString new_str = QString::fromStdString(str);

        if (new_str.indexOf("critical_program_termination") != -1) {

            file.close();
            return new_str.remove(0, new_str.lastIndexOf(" ") + 1) == "false" ? false : true;
        }
    }

    file.close();
    return false;
}

int* Get_TableValues() {

    std::ifstream file("settings.txt");

    if (!file.is_open()) {
        qWarning("File is not open");
        return (int *) -1;
    }

    std::string str;
    while (getline(file, str)) {

        QString new_str = QString::fromStdString(str);

        if (new_str.indexOf("table") != -1) {

            file.close();
            return Return_Array(new_str.remove(0, new_str.indexOf(" ") + 1).toStdString());
        }
    }

    file.close();

    return (int *) -1;
}

int* Return_Array(std::string str) {

    std::string array_str[ARRAY_SIZE];
    int *array = new int [ARRAY_SIZE];

    for (size_t i = 0, j = 0; i < str.size(); i++) {
        if (isdigit(str[i]))
            array_str[j] += str[i];
        if (!isdigit(str[i]))
            j++;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
        array[i] = std::atoi(array_str[i].c_str());

    return array;
}

void ImportLastGame::Set_CriticalPrograTermination(bool value) {

    critical_program_termination = value;

    std::ifstream file_read("settings.txt");

    if (!file_read.is_open()) {
        qWarning("File is not open");
        return;
    }

    std::string line;
    std::vector<std::string> all_line;

    while (getline(file_read, line)) {

        if (QString::fromStdString(line).indexOf("critical_program_termination") != -1) {

            QString new_line = QString::fromStdString(line);
            std::string new_line_str = (new_line.remove(new_line.lastIndexOf(" ") + 1, new_line.size())
                                        + QString::fromStdString(critical_program_termination ? "true" : "false"))
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

void ImportLastGame::Set_TableValues(int* array) {

    for (int i = 0; i < ARRAY_SIZE; i++)
        table_values_[i] = array[i];

    QString array_str;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array_str += " ";
        array_str += QString::number(table_values_[i]);
    }

    std::ifstream file_read("settings.txt");

    if (!file_read.is_open()) {
        qWarning("File is not open");
        return;
    }

    std::string line;
    std::vector<std::string> all_line;

    while (getline(file_read, line)) {

        if (QString::fromStdString(line).indexOf("table") != -1) {

            QString new_line = QString::fromStdString(line);
            std::string new_line_str = (new_line.remove(new_line.indexOf(" "), new_line.size()) + array_str).toStdString();

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
