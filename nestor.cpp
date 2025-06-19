#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> 
#include <cstdlib> 

using namespace std;


struct Producto {
    char codigo[10]; 
    char nombre[30];
    float precio;
    int stock;
    char categoria[30];
    bool activo;
};
vector<Producto> productos;

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Para Windows
    #else
        system("clear"); // Para Unix/Linux/macOS
    #endif
}

void mostrarMenu() {
    cout << "1. Agregar un nuevo producto\n";
    cout << "2. Mostrar todos los productos activos\n";
    cout << "3. Mostrar productos por categoria\n";
    cout << "4. Buscar un producto por codigo\n";
    cout << "5. Modificar un producto\n";
    cout << "6. Eliminar un producto (borrado logico)\n";
    cout << "7. Recuperar un producto borrado\n";
    cout << "8. Guardar datos en archivo binario\n";
    cout << "9. Cargar datos desde archivo binario\n";
    cout << "10. Salir\n";
    cout << "\nSeleccione una opcion: ";
}
