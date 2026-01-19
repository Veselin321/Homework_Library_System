#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string name;      
    std::string memberId;  
    int yearJoined;        

public:
    // Конструктор по подразбиране
    Member() : name("Unknown"), memberId(""), yearJoined(1900) {}

    // Конструктор с параметри
    Member(const std::string& name,
           const std::string& memberId,
           int yearJoined)
        : name(name), memberId(memberId), yearJoined(yearJoined) {}

    // Getter-и
    const std::string& getName() const { return name; }
    const std::string& getMemberId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    // Проверка за валиден читател
    bool valid() const { return !memberId.empty(); }
};

#endif
// MEMBER_H
