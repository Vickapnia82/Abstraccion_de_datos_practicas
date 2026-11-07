#include <iostream>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

class ColaSTL {
private:
    queue<int> cola;
public:
    void enqueue(int v) { 
        cola.push(v); 
        cout << "Elemento " << v << " agregado correctamente al final de la cola.\n";
    }
    
    void dequeue() {
        if (!cola.empty()) { 
            cout << "Elemento del frente (" << cola.front() << ") removido.\n";
            cola.pop(); 
        } else { 
            cout << "La cola esta vacia, no hay elementos que eliminar.\n"; 
        }
    }
    
    void eliminarEspecifico(int v) {
        int s = cola.size();
        bool encontrado = false;
        for (int i = 0; i < s; i++) {
            int actual = cola.front();
            cola.pop();
            if (actual == v && !encontrado) {
                encontrado = true;
                cout << "Valor " << v << " encontrado y eliminado de la cola.\n";
            } else {
                cola.push(actual);
            }
        }
        if (!encontrado) {
            cout << "El valor " << v << " no se encuentra en la cola.\n";
        }
    }

    void editar(int viejo, int nuevo) {
        int s = cola.size();
        bool encontrado = false;
        for (int i = 0; i < s; i++) {
            int actual = cola.front();
            cola.pop();
            if (actual == viejo && !encontrado) {
                cola.push(nuevo);
                encontrado = true;
                cout << "Valor " << viejo << " actualizado por " << nuevo << " exitosamente.\n";
            } else {
                cola.push(actual);
            }
        }
        if (!encontrado) {
            cout << "El valor " << viejo << " no se encuentra en la cola para ser editado.\n";
        }
    }

    void mostrar() {
        if (cola.empty()) {
            cout << "La cola esta actualmente vacia.\n";
            return;
        }
        cout << "Contenido de la cola (desde el frente): ";
        queue<int> copia = cola;
        while (!copia.empty()) {
            cout << copia.front() << " ";
            copia.pop();
        }
        cout << "\n";
    }
};

int main() {
    ColaSTL cola;
    int opcion = 0, num, num2;
    
    do {
        cout << "\n--- MENU INTERACTIVO: COLA STL ---\n";
        cout << "1. Agregar elemento (Enqueue)\n";
        cout << "2. Eliminar frente (Dequeue estandar)\n";
        cout << "3. Eliminar un valor especifico a eleccion\n";
        cout << "4. Editar un valor existente a eleccion\n";
        cout << "5. Mostrar contenido de la cola\n";
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
                    cola.enqueue(num); 
                } else { 
                    cout << "Error en el formato de entrada.\n"; 
                    cin.clear(); cin.ignore(10000, '\n'); 
                }
                break;
            case 2:
                cola.dequeue();
                break;
            case 3:
                cout << "Ingrese el valor exacto que desea eliminar: ";
                if (cin >> num) { 
                    cola.eliminarEspecifico(num); 
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
                        cola.editar(num, num2); 
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
                cola.mostrar();
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
