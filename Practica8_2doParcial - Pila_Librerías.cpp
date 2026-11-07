#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class PilaSTL {
private:
    stack<int> pila;
public:
    void push(int v) { 
        pila.push(v); 
        cout << "Elemento " << v << " agregado correctamente a la pila.\n";
    }
    
    void pop() {
        if (!pila.empty()) { 
            cout << "Elemento del tope (" << pila.top() << ") removido.\n";
            pila.pop(); 
        } else { 
            cout << "La pila esta vacia, no hay elementos que eliminar.\n"; 
        }
    }
    
    void eliminarEspecifico(int v) {
        stack<int> temp;
        bool encontrado = false;
        while (!pila.empty()) {
            if (pila.top() == v && !encontrado) {
                pila.pop();
                encontrado = true;
                cout << "Valor " << v << " encontrado y eliminado de la pila.\n";
            } else {
                temp.push(pila.top());
                pila.pop();
            }
        }
        while (!temp.empty()) {
            pila.push(temp.top());
            temp.pop();
        }
        if (!encontrado) {
            cout << "El valor " << v << " no se encuentra en la pila.\n";
        }
    }

    void editar(int viejo, int nuevo) {
        stack<int> temp;
        bool encontrado = false;
        while (!pila.empty()) {
            if (pila.top() == viejo && !encontrado) {
                temp.push(nuevo);
                pila.pop();
                encontrado = true;
                cout << "Valor " << viejo << " actualizado por " << nuevo << " exitosamente.\n";
            } else {
                temp.push(pila.top());
                pila.pop();
            }
        }
        while (!temp.empty()) {
            pila.push(temp.top());
            temp.pop();
        }
        if (!encontrado) {
            cout << "El valor " << viejo << " no se encuenta en la pila para ser editado.\n";
        }
    }

    void mostrar() {
        if (pila.empty()) {
            cout << "La pila esta actualmente vacia.\n";
            return;
        }
        cout << "Contenido de la pila (desde el tope): ";
        stack<int> copia = pila;
        while (!copia.empty()) {
            cout << copia.top() << " ";
            copia.pop();
        }
        cout << "\n";
    }
};

int main() {
    PilaSTL pila;
    int opcion = 0, num, num2;
    
    do {
        cout << "\n--- MENU INTERACTIVO: PILA STL ---\n";
        cout << "1. Agregar elemento (Push)\n";
        cout << "2. Eliminar tope (Pop estandar)\n";
        cout << "3. Eliminar un valor especifico a eleccion\n";
        cout << "4. Editar un valor existente a eleccion\n";
        cout << "5. Mostrar contenido de la pila\n";
        cout << "6. Salir de la ejecucion\n";
        cout << "Seleccione una opcion de operacion: ";
        
        if (!(cin >> opcion)) {
            cout << "Por favor ingrese un valor numerico valido.\n";
            cin.clear(); cin.ignore(10000, '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor numerico que desea agregar: ";
                if (cin >> num) { 
                    pila.push(num); 
                } else { 
                    cout << "Error en el formato de entrada.\n"; 
                    cin.clear(); cin.ignore(10000, '\n'); 
                }
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                cout << "Ingrese el valor exacto que desea eliminar: ";
                if (cin >> num) { 
                    pila.eliminarEspecifico(num); 
                } else { 
                    cout << "Error en el formato de entrada.\n"; 
                    cin.clear(); cin.ignore(10000, '\n'); 
                }
                break;
            case 4:
                cout << "Ingrese el valor que desea buscar para editar: ";
                if (cin >> num) {
                    cout << "Ingrese el nuevo valor con el que se reemplazara: ";
                    if (cin >> num2) { 
                        pila.editar(num, num2); 
                    } else { 
                        cout << "Error en el formato de entrada.\n"; 
                        cin.clear(); cin.ignore(10000, '\n'); 
                    }
                } else { 
                    cout << "Error en el formato de entrada.\n"; 
                    cin.clear(); cin.ignore(10000, '\n'); 
                }
                break;
            case 5:
                pila.mostrar();
                break;
            case 6:
                cout << "Finalizando la ejecucion del programa. ¡Hasta luego!\n";
                break;
            default:
                cout << "Opcion no valida. Seleccione una opcion del 1 al 6.\n";
        }
    } while (opcion != 6);
    
    return 0;
}
