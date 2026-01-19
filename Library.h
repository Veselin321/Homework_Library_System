#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;      
    std::vector<Member> members;  
    std::vector<Loan> loans;      
public:
    // Default constructor
    Library() = default;

    // Rule of 5 (default, няма собствен ресурс)
    Library(const Library&) = default;
    Library& operator=(const Library&) = default;
    Library(Library&&) = default;
    Library& operator=(Library&&) = default;
    ~Library() = default;

    // Добавя книга (връща true ако е добавена)
    bool addBook(const Book& b) {
        if (hasBook(b.getIsbn()))
            return false;
        books.push_back(b);
        return true;
    }

    // Проверява дали член съществува
    bool hasMember(const std::string& memberId) const {
        for (const auto& m : members)
            if (m.getMemberId() == memberId)
                return true;
        return false;
    }

    // Добавя читател (връща true ако е добавен)
    bool addMember(const Member& m) {
        if (!m.valid() || hasMember(m.getMemberId()))
            return false;
        members.push_back(m);
        return true;
    }

    // Проверява дали книга съществува
    bool hasBook(const std::string& isbn) const {
        for (const auto& b : books)
            if (b.getIsbn() == isbn)
                return true;
        return false;
    }

    // Проверява дали книга е налична
    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& l : loans)
            if (l.getIsbn() == isbn && !l.isReturned())
                return false;
        return hasBook(isbn);
    }

    // Дава книга под наем
    bool loanBook(const std::string& isbn,
                  const std::string& memberId,
                  const std::string& start,
                  const std::string& due) {
        if (!isBookAvailable(isbn)) return false;
        if (!hasMember(memberId)) return false;

        try {
            loans.emplace_back(isbn, memberId, start, due); // Loan конструктор валидира датите
        } catch (const std::invalid_argument&) {
            return false;
        }

        return true;
    }

    // Връща книга
    bool returnBook(const std::string& isbn,
                    const std::string& memberId) {
        for (auto& l : loans)
            if (l.getIsbn() == isbn &&
                l.getMemberId() == memberId &&
                !l.isReturned()) {
                l.markReturned();
                return true;
            }
        return false;
    }

    // Намира книги по автор 
    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> res;
        for (const auto& b : books)
            if (b.getAuthor().to_string().find(authorName) != std::string::npos)
                res.push_back(b);
        return res;
    }

    // Намира книги по заглавие 
    std::vector<Book> findByTitle(const std::string& titlePart) const {
        std::vector<Book> res;
        for (const auto& b : books)
            if (b.getTitle().find(titlePart) != std::string::npos)
                res.push_back(b);
        return res;
    }

    // Обобщена информация: брой книги / членове / активни заеми
    std::string to_string() const {
        size_t activeLoans = 0;
        for (const auto& l : loans)
            if (!l.isReturned()) ++activeLoans;

        return "Books: " + std::to_string(books.size())
             + ", Members: " + std::to_string(members.size())
             + ", Active loans: " + std::to_string(activeLoans);
    }
};

#endif
