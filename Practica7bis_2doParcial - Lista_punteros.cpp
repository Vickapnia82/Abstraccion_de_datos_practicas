#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class NodoLista {
public:
    int dato;
    NodoLista* siguiente;
    NodoLista(int d) {
        dato = d;
        siguiente = nullptr;
    }
};

class ListaDinamica {
private:
    NodoLista* cabeza;
public:
    ListaDinamica() {
        cabeza = nullptr;
    }

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
    bool modificar(int valorBuscar, int nuevoValor) {
        NodoLista* actual = cabeza;
        bool encontrado = false;
        while (actual != nullptr) {
            if (actual->dato == valorBuscar) {
                actual->dato = nuevoValor;
                encontrado = true;
                break; 
            }
            actual = actual->siguiente;
        }
        return encontrado;
    }

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

        cout << "Quieres continuar ejecutando el programa completo? (Si/No): ";
        cin >> continuar;
        for (size_t i = 0; i < continuar.length(); i++) {
            continuar[i] = tolower(continuar[i]);
        }
        
    } while (continuar == "si");

    cout << "\nFin del Programa. ¡Hasta luego!\n";
    return 0;
}
