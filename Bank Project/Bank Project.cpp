#include "Admin.h"
#include "Client.h"
#include "Employee.h"

int main() {

    Client c1(1, "Ali", "Ali12345", 5000);
    Client c2(2, "Omar", "Omar12345", 3000);

    c1.deposit(1000);
    c1.withdraw(500);
    c1.transferTo(1000, c2);
    c1.checkBalance();

    c1.display();
    c2.display();

    Employee e1(101, "Ahmed", "Ahmed123", 7000);
    e1.display();

    Admin a1(201, "Mazen", "Mazen123", 10000);
    a1.display();

    return 0;
}
