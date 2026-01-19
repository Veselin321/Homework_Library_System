#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <stdexcept>

class Loan {
private:
    std::string isbn;       
    std::string memberId;  
    std::string startDate;  
    std::string dueDate;    
    bool returned;         

public:
    // Конструктор
    Loan(const std::string& isbn,
         const std::string& memberId,
         const std::string& startDate,
         const std::string& dueDate)
        : isbn(isbn), 
        memberId(memberId),
        startDate(startDate),
        dueDate(dueDate),
          returned(false) {
            
        if (isbn.empty() || memberId.empty()) {
            throw std::invalid_argument("ISBN and Member ID cannot be empty");
          }

         if (dueDate < startDate) {
            throw std::invalid_argument(
                "Loan error: dueDate cannot be earlier than startDate"
            );
        }
    }

    // Getter-и
    const std::string& getIsbn() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }

    // Отбелязва книгата като върната
    void markReturned() { returned = true; }

    // Проверка дали е върната
    bool isReturned() const { return returned; }

    // Проверка за закъснение
    bool isOverdue(const std::string& today) const {
        return !returned && today > dueDate;
    }

    // Връща текстово представяне на заема (без <sstream>)
    std::string to_string() const {
        return std::string("Loan{isbn=\"") + isbn + "\", memberId=\"" + memberId
            + "\", startDate=\"" + startDate + "\", dueDate=\"" + dueDate
            + "\", returned=" + (returned ? "true" : "false") + "}";
    }
};

#endif
// LOAN_H
