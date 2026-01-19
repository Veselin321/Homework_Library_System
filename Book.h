#ifndef BOOK_H
#define BOOK_H

#include "Author.h"
#include <string>

class Book {
private:
    std::string title;   
    Author author;      
    int year;          
    double price;      
    std::string isbn;   

    static int totalBooks; 

    static bool validYear(int y) {
        return y >= 1500 && y <= 2025;
    }

public:
    // Конструктор по подразбиране
    Book()
        : title("Untitled"), author(), year(1900), price(0), isbn("") {
        totalBooks++;
    }

    // Параметризиран конструктор + валидация
    Book(const std::string& title, const Author& author,
         int year, double price, const std::string& isbn)
        : title(title),
          author(author),
          year(validYear(year) ? year : 1900),
          price(price >= 0 ? price : 0),
          isbn(isbn) {
        totalBooks++;
    }

    // Копиращ конструктор
    Book(const Book& other)
        : title(other.title),
          author(other.author),
          year(other.year),
          price(other.price),
          isbn(other.isbn) {
        totalBooks++;
    }

    // Преместващ конструктор
    Book(Book&& other)
        : title(other.title),
          author(other.author),
          year(other.year),
          price(other.price),
          isbn(other.isbn) {
        totalBooks++;
    }

    // Копиращ оператор 
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }

    // Преместващ оператор 
    Book& operator=(Book&& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }

    // Деструктор
    ~Book() { totalBooks--; }

    // Getter-и
    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    const std::string& getIsbn() const { return isbn; }

    // Setter-и с валидация
    void setPrice(double p) { if (p >= 0) price = p; }
    void setYear(int y) { if (validYear(y)) year = y; }

    // Текстово представяне
    std::string to_string() const {
        return title + " by " + author.to_string()
             + " (" + std::to_string(year) + "), ISBN: "
             + isbn + ", price: " + std::to_string(price);
    }

    // Статичен getter
    static int getTotalBooks() { return totalBooks; }
};

int Book::totalBooks = 0;

#endif
