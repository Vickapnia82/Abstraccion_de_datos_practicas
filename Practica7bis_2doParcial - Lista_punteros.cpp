#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//Lista Dinámica-punteros
// Clase que representa cada nodo de la lista
class NodoLista {
public:
    int dato;
    NodoLista* siguiente;
    NodoLista(int d) {
        dato = d;
        siguiente = nullptr;
    }
};

// Clase que maneja la Lista Dinámica (Orientada a Objetos)
class ListaDinamica {
private:
    NodoLista* cabeza;
public:
    ListaDinamica() {
        cabeza = nullptr;
    }

    // Insertar elemento al final de la lista
    void insertarFinal(int v) {
        NodoLista* nuevo = new NodoLista(v);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            NodoLista* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    // Eliminar el primer elemento de la lista
    void eliminarInicio() {
        if (cabeza != nullptr) {
            NodoLista* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            cout << "Elemento eliminado del inicio de la lista.\n";
        } else {
            cout << "Lista vacia, no hay elementos para eliminar.\n";
        }
    }

    // Editar / Modificar un elemento buscando su valor anterior
    bool modificar(int valorBuscar, int nuevoValor) {
        NodoLista* actual = cabeza;
        bool encontrado = false;
        while (actual != nullptr) {
            if (actual->dato == valorBuscar) {
                actual->dato = nuevoValor;
                encontrado = true;
                // Si deseas que reemplace todas las ocurrencias, puedes quitar el break.
                // Aquí reemplazará la primera coincidencia que encuentre.
                break; 
            }
            actual = actual->siguiente;
        }
        return encontrado;
    }

    // Mostrar contenido de la lista
    void mostrar() {
        cout << "Contenido actual de la lista: ";
        NodoLista* actual = cabeza;
        if (actual == nullptr) {
            cout << "[Lista Vacia]";
        }
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n";
    }

    // Verificar si está vacía
    bool estaVacia() {
        return cabeza == nullptr;
    }
};

int main() {
    ListaDinamica lista;
    int num, cantidad;
    string continuar = "si";
    string opcion;

    do {
        // 1. Agregar a elección del usuario
        cout << "\n--- GESTION DE LISTA DINAMICA ---\n";
        cout << "Cuantos elementos deseas ingresar a la lista dinamica?: ";
        if (!(cin >> cantidad)) {
            cout << "Por favor ingrese un valor numerico valido.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        bool errorEntrada = false;
        for (int i = 0; i < cantidad; i++) {
            cout << "Elemento " << i + 1 << ": ";
            if (!(cin >> num)) {
                cout << "Por favor ingrese un valor numerico valido.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                errorEntrada = true;
                break;
            }
            lista.insertarFinal(num);
        }
        
        if (errorEntrada) {
            continue;
        }
        
        lista.mostrar();

        // 2. Editar a elección del usuario (Modificar un elemento existente)
        if (!lista.estaVacia()) {
            cout << "Deseas editar algun elemento de la lista? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                int valorAntiguo, valorNuevo;
                cout << "Ingresa el valor del elemento que deseas buscar y cambiar: ";
                cin >> valorAntiguo;
                cout << "Ingresa el nuevo valor: ";
                cin >> valorNuevo;
                
                if (lista.modificar(valorAntiguo, valorNuevo)) {
                    cout << "Elemento modificado exitosamente.\n";
                } else {
                    cout << "No se encontro el elemento con el valor ingresado en la lista.\n";
                }
                lista.mostrar();
            }
        }

        // 3. Eliminar a elección del usuario (Iterativo con do-while)
        do {
            if (lista.estaVacia()) break;
            cout << "Deseas eliminar un elemento (del inicio) de la lista? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                lista.eliminarInicio();
                lista.mostrar();
            }
        } while (opcion == "si" && !lista.estaVacia());

        // 4. Decisión para continuar o terminar la ejecución
        cout << "Quieres continuar ejecutando el programa completo? (Si/No): ";
        cin >> continuar;
        for (size_t i = 0; i < continuar.length(); i++) {
            continuar[i] = tolower(continuar[i]);
        }
        
    } while (continuar == "si");

    cout << "\nFin del Programa. ¡Hasta luego!\n";
    return 0;
}
