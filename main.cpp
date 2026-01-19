#include <iostream>
#include "Library.h"
#include "Author.h"
#include "Book.h"
#include "Member.h"

int main() {
    Library lib;

    // Създаваме автори
    Author vazov("Ivan Vazov", 1850);
    Author orwell("George Orwell", 1903);

    // Създаваме книги
    Book b1("Pod igoto", vazov, 1894, 25.50, "ISBN-001");
    Book b2("Nema zemya", vazov, 1900, 18.90, "ISBN-002");
    Book b3("1984", orwell, 1949, 9.99, "ISBN-1984");

    // Добавяме книги в библиотеката
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    // Добавяме членове
    lib.addMember(Member("Petar Petrov", "M001", 2023));
    lib.addMember(Member("Maria Ivanova", "M002", 2024));

    // Преглед на библиотеката
    std::cout << "Library summary: " << lib.to_string() << "\n";

    // Даем книги под наем
    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        std::cout << "Loan created for ISBN-001 by M001\n";

    if (lib.loanBook("ISBN-1984", "M002", "2025-11-05", "2025-11-20"))
        std::cout << "Loan created for ISBN-1984 by M002\n";

    // Проверка за наличност
    std::cout << "Is ISBN-001 available? " 
              << std::boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    // Връщане на книга
    lib.returnBook("ISBN-001", "M001");
    std::cout << "Is ISBN-001 available after return? " 
              << std::boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    // Търсене по автор
    std::cout << "\nBooks by Vazov:\n";
    for (const auto& bk : lib.findByAuthor("Vazov"))
        std::cout << "  - " << bk.to_string() << "\n";

    // Търсене по заглавие
    std::cout << "\nBooks containing '1984':\n";
    for (const auto& bk : lib.findByTitle("1984"))
        std::cout << "  - " << bk.to_string() << "\n";

    // Финален статус на библиотеката
    std::cout << "\nFinal Library summary: " << lib.to_string() << "\n";
    std::cout << "Total books ever created: " << Book::getTotalBooks() << "\n";

    return 0;
}
