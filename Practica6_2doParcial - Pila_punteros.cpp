#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class NodoPila {
public:
    int dato;
    NodoPila* siguiente;
    NodoPila(int d) {
        dato = d;
        siguiente = nullptr;
    }
};

class PilaDinamica {
private:
    NodoPila* tope;
public:
    PilaDinamica() {
        tope = nullptr;
    }

    void push(int v) {
        NodoPila* nuevo = new NodoPila(v);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    void pop() {
        if (tope != nullptr) {
            NodoPila* temp = tope;
            tope = tope->siguiente;
            delete temp;
            cout << "Elemento eliminado del tope.\n";
        } else {
            cout << "Pila vacia, no hay elementos para eliminar.\n";
        }
    }

    void modificar(int nuevoValor) {
        if (tope != nullptr) {
            tope->dato = nuevoValor;
            cout << "Elemento modificado exitosamente.\n";
        } else {
            cout << "La pila esta vacia, no hay elementos para editar.\n";
        }
    }

    void mostrar() {
        cout << "Contenido actual de la pila (Tope -> Base): ";
        NodoPila* actual = tope;
        if (actual == nullptr) {
            cout << "[Pila Vacia]";
        }
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n";
    }
    
    bool estaVacia() {
        return tope == nullptr;
    }
};

int main() {
    PilaDinamica pila;
    int num, cantidad;
    string continuar = "si";
    string opcion;

    do {
        cout << "\n--- GESTION DE PILA DINAMICA ---\n";
        cout << "Cuantos elementos deseas ingresar a la pila?: ";
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
            pila.push(num);
        }
        
        if (errorEntrada) {
            continue;
        }
        
        pila.mostrar();

        if (!pila.estaVacia()) {
            cout << "Deseas editar el elemento superior (tope) de la pila? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                int nuevoDato;
                cout << "Ingresa el nuevo valor para el elemento superior: ";
                if (cin >> nuevoDato) {
                    pila.modificar(nuevoDato);
                    pila.mostrar();
                } else {
                    cout << "Entrada invalida.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        do {
            if (pila.estaVacia()) break;
            cout << "Deseas eliminar un elemento (pop) de la pila? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                pila.pop();
                pila.mostrar();
            }
        } while (opcion == "si" && !pila.estaVacia());

        cout << "Quieres continuar ejecutando el programa completo? (Si/No): ";
        cin >> continuar;
        for (size_t i = 0; i < continuar.length(); i++) {
            continuar[i] = tolower(continuar[i]);
        }
        
    } while (continuar == "si");

    cout << "\nFin del Programa. ¡Hasta luego!\n";
    return 0;
}
