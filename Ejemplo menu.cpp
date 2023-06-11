#include <iostream>
#include <vector>
#include <algorithm>

struct Employee {
    std::string firstName;
    std::string lastName;
    double salary;
    std::string role;
};

bool sortByLastName(const Employee& emp1, const Employee& emp2) {
    return emp1.lastName < emp2.lastName;
}

bool sortBySalary(const Employee& emp1, const Employee& emp2) {
    return emp1.salary < emp2.salary;
}

void displayEmployees(const std::vector<Employee>& employees) {
    for (const auto& emp : employees) {
        std::cout << emp.firstName << " " << emp.lastName << ", Salary: $" << emp.salary << ", Role: " << emp.role << "\n";
    }
    std::cout << "\n";
}

void displayEmployeeCountByRole(const std::vector<Employee>& employees) {
    std::cout << "Empleado por puesto:\n";
    std::vector<std::string> roles;
    for (const auto& emp : employees) {
        if (std::find(roles.begin(), roles.end(), emp.role) == roles.end()) {
            roles.push_back(emp.role);
        }
    }
    for (const auto& role : roles) {
        int count = std::count_if(employees.begin(), employees.end(),
            [&role](const Employee& emp) { return emp.role == role; });
        std::cout << role << ": " << count << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<Employee> employees;
    int choice;

    while (true) {
        std::cout << "======= Menu principal =======\n";
        std::cout << "1. Ordenar empleados por nombre\n";
        std::cout << "2. Ordernar empleados por salario\n";
        std::cout << "3. Mostrar lista de empleados por puesto\n";
        std::cout << "4. Anadir empleado\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese opcion: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::sort(employees.begin(), employees.end(), sortByLastName);
                std::cout << "Empleados ordenados por apellido:\n";
                displayEmployees(employees);
                break;
            case 2:
                std::sort(employees.begin(), employees.end(), sortBySalary);
                std::cout << "Empleados ordenados por salario:\n";
                displayEmployees(employees);
                break;
            case 3:
                displayEmployeeCountByRole(employees);
                break;
            case 4: {
                Employee newEmployee;
                std::cout << "Introduzca nombre del empleado: ";
                std::cin >> newEmployee.firstName;
                std::cout << "Introduzca apellido del empleado: ";
                std::cin >> newEmployee.lastName;
                std::cout << "Introduzca salario del empleado: ";
                std::cin >> newEmployee.salary;
                std::cout << "Introduzca puesto del empleado: ";
                std::cin >> newEmployee.role;
                employees.push_back(newEmployee);
                std::cout << "Empleado anadido.\n\n";
                break;
            }
            case 5:
                std::cout << "Saliendo del programa...\n";
                return 0;
            default:
                std::cout << "Opcion invalida.\n\n";
                break;
        }
    }

    return 0;
}
