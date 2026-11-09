#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class NodoCola {
public:
    int dato;
    NodoCola* siguiente;
    NodoCola(int d) {
        dato = d;
        siguiente = nullptr;
    }
};

class ColaDinamica {
private:
    NodoCola* frente;
    NodoCola* final;
public:
    ColaDinamica() {
        frente = nullptr;
        final = nullptr;
    }

    void enqueue(int v) {
        NodoCola* nuevo = new NodoCola(v);
        if (final == nullptr) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    void dequeue() {
        if (frente != nullptr) {
            NodoCola* temp = frente;
            frente = frente->siguiente;
            if (frente == nullptr) {
                final = nullptr;
            }
            delete temp;
            cout << "Elemento atendido/eliminado del frente.\n";
        } else {
            cout << "Cola vacia, no hay elementos para eliminar.\n";
        }
    }

    void modificar(int nuevoValor) {
        if (frente != nullptr) {
            frente->dato = nuevoValor;
            cout << "Elemento del frente modificado exitosamente.\n";
        } else {
            cout << "La cola esta vacia, no hay elementos para editar.\n";
        }
    }

    void mostrar() {
        cout << "Contenido actual de la cola (Frente -> Final): ";
        NodoCola* actual = frente;
        if (actual == nullptr) {
            cout << "[Cola Vacia]";
        }
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << "\n";
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaDinamica cola;
    int num, cantidad;
    string continuar = "si";
    string opcion;

    do {
        cout << "\n--- GESTION DE COLA DINAMICA ---\n";
        cout << "Cuantos elementos deseas ingresar a la cola?: ";
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
            cola.enqueue(num);
        }
        
        if (errorEntrada) {
            continue;
        }
        
        cola.mostrar();

        if (!cola.estaVacia()) {
            cout << "Deseas editar el elemento del frente de la cola? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                int nuevoDato;
                cout << "Ingresa el nuevo valor para el elemento del frente: ";
                if (cin >> nuevoDato) {
                    cola.modificar(nuevoDato);
                    cola.mostrar();
                } else {
                    cout << "Entrada invalida.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        do {
            if (cola.estaVacia()) break;
            cout << "Deseas eliminar un elemento (dequeue) de la cola? (Si/No): ";
            cin >> opcion;
            for (size_t i = 0; i < opcion.length(); i++) {
                opcion[i] = tolower(opcion[i]);
            }
            
            if (opcion == "si") {
                cola.dequeue();
                cola.mostrar();
            }
        } while (opcion == "si" && !cola.estaVacia());

        cout << "Quieres continuar ejecutando el programa completo? (Si/No): ";
        cin >> continuar;
        for (size_t i = 0; i < continuar.length(); i++) {
            continuar[i] = tolower(continuar[i]);
        }
        
    } while (continuar == "si");

    cout << "\nFin del Programa. ¡Hasta luego!\n";
    return 0;
}
