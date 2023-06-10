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
