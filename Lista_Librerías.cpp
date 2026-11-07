#include <iostream>
#include <list>
#include <string>
#include <cctype>
using namespace std;

class ListaSTL {
private:
    list<int> lista;
public:
    void insertarFinal(int v) { 
        lista.push_back(v); 
        cout << "Elemento " << v << " agregado correctamente al final de la lista.\n";
    }
    
    void eliminarInicio() {
        if (!lista.empty()) { 
            cout << "Elemento del inicio (" << lista.front() << ") removido.\n";
            lista.pop_front(); 
        } else { 
            cout << "La lista esta vacia, no hay elementos que eliminar.\n"; 
        }
    }

    void eliminarEspecifico(int v) {
        bool encontrado = false;
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (*it == v) {
                lista.erase(it);
                encontrado = true;
                cout << "Valor " << v << " encontrado y eliminado de la lista.\n";
                break;
            }
        }
        if (!encontrado) {
            cout << "El valor " << v << " no se encuentra en la lista.\n";
        }
    }

    void editar(int viejo, int nuevo) {
        bool encontrado = false;
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (*it == viejo) {
                *it = nuevo;
                encontrado = true;
                cout << "Valor " << viejo << " actualizado por " << nuevo << " exitosamente.\n";
                break;
            }
        }
        if (!encontrado) {
            cout << "El valor " << viejo << " no se encuentra en la lista para ser editado.\n";
        }
    }

    void mostrar() {
        if (lista.empty()) {
            cout << "La lista esta actualmente vacia.\n";
            return;
        }
        cout << "Contenido de la lista: ";
        for (int elemento : lista) { 
            cout << elemento << " "; 
        }
        cout << "\n";
    }
};

int main() {
    ListaSTL lista;
    int opcion = 0, num, num2;
    
    do {
        cout << "\n--- MENU INTERACTIVO: LISTA STL ---\n";
        cout << "1. Agregar elemento (Push Back)\n";
        cout << "2. Eliminar inicio (Pop Front estandar)\n";
        cout << "3. Eliminar un valor especifico a eleccion\n";
        cout << "4. Editar un valor existente a eleccion\n";
        cout << "5. Mostrar contenido de la lista\n";
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
                    lista.insertarFinal(num); 
                } else { 
                    cout << "Error en el formato de entrada.\n"; 
                    cin.clear(); cin.ignore(10000, '\n'); 
                }
                break;
            case 2:
                lista.eliminarInicio();
                break;
            case 3:
                cout << "Ingrese el valor exacto que desea eliminar: ";
                if (cin >> num) { 
                    lista.eliminarEspecifico(num); 
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
                        lista.editar(num, num2); 
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
                lista.mostrar();
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