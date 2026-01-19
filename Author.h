#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
using namespace std;

class Author {
private:
    std::string name;  
    int birthYear;     

public:
    // Конструктор по подразбиране
    Author() : name("Unknown"), birthYear(1900) {}

    // Конструктор с параметри
    Author(const std::string& name, int birthYear)
        : name(name), birthYear(1900) {
        setBirthYear(birthYear);
    }

    // Връща името
    const std::string& getName() const { return name; }

    // Връща годината на раждане
    int getBirthYear() const { return birthYear; }

    // Задава година на раждане с проверка
    void setBirthYear(int year) {
        if (year >= 1850 && year <= 2025)
            birthYear = year;
    }

    // Текстово представяне
    std::string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};

#endif
// AUTHOR_H
