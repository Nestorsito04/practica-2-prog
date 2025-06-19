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

void agregarProducto() {
    limpiarPantalla();
    Producto nuevo;
    cout << "\nNuevo Producto\n";
    cout << "Codigo: ";
    cin.ignore();
    cin.getline(nuevo.codigo, 10);
    cout << "Nombre: ";
    cin.getline(nuevo.nombre, 30);
    cout << "Precio: ";
    cin >> nuevo.precio;
    cout << "Stock: ";
    cin >> nuevo.stock;
    cout << "Categoria: ";
    cin.ignore();
    cin.getline(nuevo.categoria, 30);
    nuevo.activo = true;

    productos.push_back(nuevo);
    cout << "Producto agregado con exito.\n";
}

void mostrarProductosActivos() {
    limpiarPantalla();
    if (productos.empty()) {
        cout << "No hay productos almacenados.\n";
        return;
    }
    cout << "\n Productos Activos \n";
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].activo) {
            cout << i + 1 << ". Codigo: " << productos[i].codigo << ", Nombre: " << productos[i].nombre
                 << ", Precio: " << productos[i].precio << ", Stock: " << productos[i].stock
                 << ", Categoria: " << productos[i].categoria << endl;
        }
    }
}

void mostrarProductosPorCategoria() {
    limpiarPantalla();
    if (productos.empty()) {
        cout << "No hay productos almacenados.\n";
        return;
    }
    char categoria[30];
    cout << "\nIngrese la categoria: ";
    cin.ignore();
    cin.getline(categoria, 30);

    cout << "\n Productos en la categoria " << categoria << " \n";
