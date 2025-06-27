#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
    int stock;
    char categoria[30];
    bool activo;
};

long pos(int c) {
    return (c - 1) * sizeof(Producto);
}

void limpiarPantalla() {
    cout << string(50, '\n');
}

void crearArchivo() {
    fstream f("nombreArchivo", ios::in | ios::binary);
    if (!f) f.open("nombreArchivo", ios::out | ios::binary);
}

bool existe(int code) {
    fstream f("nombreArchivo", ios::in | ios::binary);
    if (!f) return false;
    Producto p;
    f.seekg(pos(code));
    return f.read((char*)&p, sizeof(p)) && p.activo;
}

void agregarProducto() {
    Producto p; 
 cout << "Codigo: "; cin >> p.codigo;
    if (p.codigo <= 0 || existe(p.codigo)) {
        cout << "Invalido o existente."; return;
    }
    cin.ignore();
    cout << "Nombre: "; cin.getline(p.nombre, 31);
    cout << "Precio: "; cin >> p.precio;
    cout << "Stock: "; cin >> p.stock; cin.ignore();
    cout << "Categoria: "; cin.getline(p.categoria, 40);
    p.activo = true;
    fstream f("nombreArchivo", ios::in | ios::out | ios::binary);
    f.seekp(pos(p.codigo));
    f.write((char*)&p, sizeof(p));
}

void mostrarProductosActivos() {
    ifstream f("nombreArchivo", ios::binary);
    Producto p;
    while (f.read((char*)&p, sizeof(p))) {
        if (p.activo) {
            cout << "Codigo: " << p.codigo << ", Nombre: " << p.nombre << ", Precio: " << p.precio
                 << ", Stock: " << p.stock << ", Categoria: " << p.categoria << "\n";
        }
    }
}

void mostrarProductosPorCategoria() {
    char cat[30];
    cout << "Categoria: "; cin.ignore(); cin.getline(cat, 30);
    ifstream f("nombreArchivo", ios::binary);
    Producto p;
    while (f.read((char*)&p, sizeof(p))) {
        if (p.activo && strcmp(p.categoria, cat) == 0) {
            cout << "Codigo: " << p.codigo << ", Nombre: " << p.nombre << ", Precio: " << p.precio << ", Stock: " << p.stock << "\n";
        }
    }
}

void buscarProductoPorCodigo() {
    int c;
    cout << "Codigo (entero): "; cin >> c;
    fstream f("nombreArchivo", ios::in | ios::binary);
    Producto p;
    f.seekg(pos(c));
    if (f.read((char*)&p, sizeof(p)) && p.activo) {
        cout << "Codigo: " << p.codigo << ", Nombre: " << p.nombre << ", Precio: " << p.precio
             << ", Stock: " << p.stock << ", Categoria: " << p.categoria << "\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void modificarProducto() {
    int c;
    cout << "Codigo (entero): "; cin >> c;
    fstream f("nombreArchivo", ios::in | ios::out | ios::binary);
    Producto p;
    f.seekg(pos(c));
    if (f.read((char*)&p, sizeof(p)) && p.activo) {
        cout << "Nuevo Precio: "; cin >> p.precio;
        cout << "Nuevo Stock: "; cin >> p.stock; cin.ignore();
        cout << "Nueva Categoria: "; cin.getline(p.categoria, 30);
        f.seekp(pos(c));
        f.write((char*)&p, sizeof(p));
        cout << "Producto modificado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

void eliminarProducto() {
    int c;
    cout << "Codigo (entero): "; cin >> c;
    fstream f("nombreArchivo", ios::in | ios::out | ios::binary);
    Producto p;
    f.seekg(pos(c));
    if (f.read((char*)&p, sizeof(p)) && p.activo) {
        p.activo = false;
        f.seekp(pos(c));
        f.write((char*)&p, sizeof(p));
        cout << "Producto eliminado logicamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

int main() {
    crearArchivo();
    int opcion;
    do {
        cout << "1. Agregar un nuevo producto\n";
        cout << "2. Mostrar todos los productos activos\n";
        cout << "3. Mostrar productos por categoria\n";
        cout << "4. Buscar un producto por codigo\n";
        cout << "5. Modificar un producto\n";
        cout << "6. Eliminar un producto (borrado logico)\n";
        cout << "0. Salir\n";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: mostrarProductosActivos(); break;
            case 3: mostrarProductosPorCategoria(); break;
            case 4: buscarProductoPorCodigo(); break;
            case 5: modificarProducto(); break;
            case 6: eliminarProducto(); break;
        }

        if (opcion != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 0);

    return 0;
}
