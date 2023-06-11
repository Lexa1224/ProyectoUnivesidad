#include <iostream>
#include <fstream>
using namespace std;

/*---------------------------------------------------------------------------------*/
/*estas funcion deben agregarse a la opcion del menu principal que 
	permite crear un nuevo ingreso al archivo y que permite leer el fichero*/
void agregarEmpleado();
void lecturaFichero();
/*---------------------------------------------------------------------------------*/





int main(int argc, char** argv) {
	
	/*
	ESTAS DOS FUNCIONES DEBEN AGREGARSE AL MENU EN LAS OPCIONES CORRESPONDIENTES A LA LECTURA Y LA ESCRITURA
	AL DESCOMENTAR ESTAS FUNCIONES NOTARAN COMO FUNCIONAN
	*/
	//agregarEmpleado();
	//lecturaFichero();
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}




//x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0

/*-------------------------------------------------------------------------------------------------------*/
/*LA FUNCION DE ESCRITURA EN EL ARCHIVO*/
void agregarEmpleado(){
	ofstream Escritura;//Creamos el objeto donde se abrira el archivo
	string nombre;//Almacena el nombre
	string apellido;//Almacena el apellido
	string edad;//Almacena la fecha de nacimiento
	string posicion;//Almacena el cargo ocupado
	int salario;//el salario puede agregarse en la clase dependiendo del empleado
	
	Escritura.open("DATOSEMPLEADOS.txt",ios::app);//abrimos el archivo en modo escritura
	//le pedimos al usuario que digite los datos
	cout<<"HA SELECCIONADO INGRESAR UN NUEVO EMPLEADO"<<endl;
	Escritura<<"*********************************\n";
	cout<<"\ningrese nombre"<<endl;//Impresion de requerimiento
	getline(cin,nombre);//lectura de requerimiento
	Escritura<<"Nombre: "+nombre<<endl;//Escritura de requerimieto en el archivo
	
	cout<<"\ningrese apellido"<<endl;//Impresion de requerimiento
	getline(cin,apellido);//lectura de requerimiento
	Escritura<<"Apellido: "+apellido<<endl;//Escritura de requerimieto en el archivo
	
	cout<<"ingrese Fecha de nacimiento"<<endl;//Impresion de requerimiento
	getline(cin,edad);//lectura de requerimiento
	Escritura<<"Fecha de nacimiento: "+edad<<endl;//Escritura de requerimieto en el archivo
	
	cout<<"ingrese posicion"<<endl;//Impresion de requerimiento
	getline(cin,posicion);//lectura de requerimiento
	Escritura<<"Cargo Ocupado: "+posicion<<endl;//Escritura de requerimieto en el archivo
	Escritura<<"\n*********************************";
	//Ingresamos los datos al archivo
	//Escritura<<textoAgregar<<endl;
	
	
	Escritura.close();//Cerramos el fichero
	cout<<"Registros guardados con exito"<<endl;
	
	
	//X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X BUG A CORREGIR 0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0
	/*
	HAY QUE CORREGIR EL PROBLEMA QUE CUANDO SE LLAMA A LA FUNCION YA SEA 
	POR BUCLE O POR RECURSIVIDAD SE SALTA EL INGRESO DEL NOMBRE
	ES ALGO QUE HAY QUE ARREGLAR
	VOY A TRABAJAR PARA PODER CORREGIRLO
	ATTE:ALEX
	
	*/
	//FUNCION RECURSIVA
	cout<<"Desea agregar otro registro?"<<endl;
	char respuesta;
	cin>>respuesta;
	if(respuesta=='s'){
	agregarEmpleado();
	}
	else{
		cout<<"Saliendo de modo escritura"<<endl;
	}
	//X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0
	
}//final de la funcion
/*FIN LA FUNCION DE LECTURA EN EL ARCHIVO*/
/*-------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------------*/
/*LA FUNCION DE ESCRITURA EN EL ARCHIVO*/
void lecturaFichero(){
	string lectura;
//CREAMOS LA INSTANCIA DE LA CLASE
ifstream lecturaArchivo;
lecturaArchivo.open("DATOSEMPLEADOS.txt",ios::in);

//Comprobamos si el archivo se ha abierto correctamente
if(lecturaArchivo.fail()){
	cout<<"La lectura no pudo completarse :C"<<endl;
}//Final de la comprobacion


//leemos el archivo
while(!lecturaArchivo.eof()){//mientras no se llegue al final del archivo leerlo
getline(lecturaArchivo,lectura);
cout<<lectura<<endl;
}//Final de la lectura

//cerramos el archivo
lecturaArchivo.close();








}

/*FIN LA FUNCION DE LECTURA EN EL ARCHIVO*/
/*-------------------------------------------------------------------------------------------------------*/

//x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0
/*-------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------------*/

/*xpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxxppxpxxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxxpxpxp*/
/*creando clase empleado y sus atributos

class Empleado {
protected:
    string nombre;
    string apellido;
    string rol;
    double salario;
public:
    Empleado(const string& nombre, const string& apellido, const string& rol, double salario)
        : nombre(nombre), apellido(apellido), rol(rol), salario(salario) {}

    virtual void imprimirDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Rol: " << rol << endl;
        cout << "Salario: " << salario << endl;
    }

    virtual ~Empleado() {} // Agregamos un destructor virtual
};

class Tecnico : public Empleado {
protected:
    int horasTrabajadas;
public:
    Tecnico(const string& nombre, const string& apellido, const string& rol, double salario, int horasTrabajadas)
        : Empleado(nombre, apellido, rol, salario), horasTrabajadas(horasTrabajadas) {}

    void imprimirDatos() override {
        Empleado::imprimirDatos();
        cout << "Horas trabajadas: " << horasTrabajadas << endl;
    }
};

class JefeArea : public Empleado {
protected:
    string nivel;
public:
    JefeArea(const string& nombre, const string& apellido, const string& rol, double salario, const string& nivel)
        : Empleado(nombre, apellido, rol, salario), nivel(nivel) {}

    void imprimirDatos() override {
        Empleado::imprimirDatos();
        cout << "Nivel: " << nivel << endl;
    }
};

class Supervisor : public Empleado {
protected:
    int proyectos;
public:
    Supervisor(const string& nombre, const string& apellido, const string& rol, double salario, int proyectos)
        : Empleado(nombre, apellido, rol, salario), proyectos(proyectos) {}

    void imprimirDatos() override {
        Empleado::imprimirDatos();
        cout << "Proyectos: " << proyectos << endl;
    }
};
/*fin de la clase empleado
/*xpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxxppxpxxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxpxxpxpx*/


///////////////////////////////////////////////////////////////////////////////////
////////////////////// M E N U    P R I N C I P A L ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//Primer ejemplo para el menu, faltaria estandarizar las variables, anadir una opcion para ver la lista completa para todos los
//los empleados
/*
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
*/