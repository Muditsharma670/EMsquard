#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Employee Class
class Employee {
private:
    int id;
    string name;
    string department;
    double baseSalary;
    int leavesTaken;
    double performanceRating; // (1.0 to 5.0)

public:
    // Constructor
    Employee(int idParam, string nameParam, string departmentParam, double salaryParam)
        : id(idParam), name(nameParam), department(departmentParam),
          baseSalary(salaryParam), leavesTaken(0), performanceRating(3.0) {}

    // Getters
    int getId() { return id; }
    string getName() { return name; }
    string getDepartment() { return department; }

    // Update details
    void update(string newName, string newDepartment, double newSalary) {
        name = newName;
        department = newDepartment;
        baseSalary = newSalary;
    }

    // Leave management
    void takeLeave(int days) { leavesTaken += days; }
    int getLeaves() { return leavesTaken; }

    // Performance
    void setPerformance(double rating) { performanceRating = rating; }

    // Salary Calculation
    double calculateFinalSalary() {
        double deduction = leavesTaken * 500;             // ₹500 per leave
        double bonus = (performanceRating / 5.0) * 2000;  // performance bonus
        return baseSalary - deduction + bonus;
    }

    // Display details
    void display() {
        cout << "ID: " << id 
             << " | Name: " << name
             << " | Dept: " << department
             << " | Base Salary: " << baseSalary
             << " | Leaves: " << leavesTaken
             << " | Performance: " << performanceRating
             << " | Final Salary: " << calculateFinalSalary()
             << endl;
    }
};

// Global vector to store employees
vector<Employee> employees;

// Add new employee
void addEmployee() {
    int id;
    string name, department;
    double salary;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Department: ";
    cin >> department;
    cout << "Enter Salary: ";
    cin >> salary;

    employees.push_back(Employee(id, name, department, salary));
    cout << " Employee Added!\n";
}

// Display all employees
void displayAll() {
    if (employees.empty()) {
        cout << "⚠ No employees found.\n";
        return;
    }
    cout << "\n--- Employee List ---\n";
    for (auto &emp : employees) {
        emp.display();
    }
}

// Search employee
void searchEmployee() {
    int choice;
    cout << "Search by: 1.ID  2.Name  3.Department : ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        for (auto &emp : employees) {
            if (emp.getId() == id) { emp.display(); return; }
        }
    } else if (choice == 2) {
        string name;
        cout << "Enter Name: ";
        cin >> name;
        for (auto &emp : employees) {
            if (emp.getName() == name) { emp.display(); return; }
        }
    } else if (choice == 3) {
        string department;
        cout << "Enter Department: ";
        cin >> department;
        for (auto &emp : employees) {
            if (emp.getDepartment() == department) { emp.display(); }
        }
        return;
    }
    cout << " Employee not found.\n";
}

// Update employee
void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    for (auto &emp : employees) {
        if (emp.getId() == id) {
            string name, department;
            double salary;
            cout << "Enter new Name: "; cin >> name;
            cout << "Enter new Department: "; cin >> department;
            cout << "Enter new Salary: "; cin >> salary;
            emp.update(name, department, salary);
            cout << " Employee Updated!\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

// Delete employee
void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    for (auto it = employees.begin(); it != employees.end(); it++) {
        if (it->getId() == id) {
            employees.erase(it);
            cout << "🗑 Employee Deleted!\n";
            return;
        }
    }
    cout << " Employee not found.\n";
}

// Add leave
void addLeave() {
    int id, days;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter no. of leave days: ";
    cin >> days;

    for (auto &emp : employees) {
        if (emp.getId() == id) {
            emp.takeLeave(days);
            cout << " Leave Added!\n";
            return;
        }
    }
    cout << " Employee not found.\n";
}

// Update performance
void updatePerformance() {
    int id;
    double rating;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Performance Rating (1.0 - 5.0): ";
    cin >> rating;

    for (auto &emp : employees) {
        if (emp.getId() == id) {
            emp.setPerformance(rating);
            cout << " Performance Updated!\n";
            return;
        }
    }
    cout << " Employee not found.\n";
}

// Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Add Leave\n";
        cout << "7. Update Performance\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: addLeave(); break;
            case 7: updatePerformance(); break;
            case 8: cout << " Exiting..."; return 0;
            default: cout << " Invalid choice!\n";
        }
    }
}