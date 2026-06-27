#include "Validation.h"
#include "person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "DataSourceInterface.h"
#include "FileManager.h"
#include "AdminService.h"
#include "EmployeeService.h"

// بعد كده الـ main function بتاعتك زي ما هي تحتهم
int main() {

   /* fstream file;
    file.open("habo.txt");
    if (!file.is_open()) {
        cout << "Error While Reading";
    }
    else {
        while (file.good()) {
            string line;
            getline(file, line);
            cout << line << endl;

        }
    }*/



    /*ofstream file("habiba.txt");
    if (!file.is_open()) {
        cout << "Error While Reading";
    }
    else {
        file << "Habiba loves me" << endl;
        file << "ehab loves u" << endl;
        file << "i love u" << endl;
        file.close();
    }*/


   /* Client c1(1, "Ali", "Ali12345", 5000);
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
    a1.display();*/
   /*A dmin a1(1, "Hany", "Hany6400", 36500);
    AdminService as(a1);
    as.listClients();
    as.addEmployee(a1);*/

    cout << "========== CLIENTS ==========\n";
    for (Client c : FileManager::getAllClients())
        c.display();

    cout << "\n========== EMPLOYEES ==========\n";
    for (Employee e : FileManager::getAllEmployees())
        e.display();

    cout << "\n========== ADMINS ==========\n";
    for (Admin a : FileManager::getAllAdmins())
        a.display();


    return 0;
}
