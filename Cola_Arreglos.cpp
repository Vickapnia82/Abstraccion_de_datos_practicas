#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

class ColaDinamica {
private:
    Nodo* frente = nullptr;
    Nodo* final = nullptr;
public:
    ~ColaDinamica() { limpiar(); }

    void enqueue(int v) {
        Nodo* n = new Nodo{v, nullptr};
        if (!frente) frente = final = n;
        else { final->sig = n; final = n; }
        cout << "Entro: " << v << "\n";
    }

    void dequeue() {
        if (!frente) { cout << "Cola vacia\n"; return; }
        Nodo* tmp = frente;
        cout << "Salio: " << tmp->dato << "\n";
        frente = frente->sig;
        if (!frente) final = nullptr;
        delete tmp;
    }

    void eliminarPorValor(int v) {
        if (!frente) { cout << "Vacia\n"; return; }
        if (frente->dato == v) { dequeue(); return; }
        Nodo* act = frente;
        while (act->sig && act->sig->dato != v) act = act->sig;
        if (!act->sig) { cout << "No existe " << v << "\n"; return; }
        Nodo* tmp = act->sig;
        act->sig = tmp->sig;
        if (tmp == final) final = act;
        delete tmp;
        cout << "Eliminado: " << v << "\n";
    }

    void modificarFrente(int nuevo) {
        if (!frente) { cout << "Vacia\n"; return; }
        cout << "Frente " << frente->dato << " -> " << nuevo << "\n";
        frente->dato = nuevo;
    }

    void modificarPorValor(int viejo, int nuevo) {
        Nodo* act = frente;
        while (act && act->dato != viejo) act = act->sig;
        if (!act) { cout << "No existe " << viejo << "\n"; return; }
        act->dato = nuevo;
        cout << "Modificado " << viejo << " -> " << nuevo << "\n";
    }

    void limpiar() {
        while (frente) dequeue();
        cout << "Cola limpia, lista para iniciar otro proceso\n";
    }

    void mostrar() {
        if (!frente) { cout << "Cola vacia\n"; return; }
        cout << "Cola (frente -> final): ";
        Nodo* act = frente;
        while (act) { cout << act->dato << " "; act = act->sig; }
        cout << "\n";
    }
};

int main() {
    ColaDinamica c;
    int op, val, val2;
    do {
        cout << "\n--- COLA DINAMICA 4 ---\n1.Enqueue 2.Dequeue 3.Modificar Frente 4.Modificar por Valor 5.Eliminar por Valor 6.Mostrar 7.Limpiar / Nuevo Proceso 0.Salir\nOpcion: ";
        cin >> op;
        if (op == 1) { cout << "Valor: "; cin >> val; c.enqueue(val); }
        else if (op == 2) c.dequeue();
        else if (op == 3) { cout << "Nuevo frente: "; cin >> val; c.modificarFrente(val); }
        else if (op == 4) { cout << "Valor a cambiar: "; cin >> val; cout << "Nuevo: "; cin >> val2; c.modificarPorValor(val, val2); }
        else if (op == 5) { cout << "Valor a eliminar: "; cin >> val; c.eliminarPorValor(val); }
        else if (op == 6) c.mostrar();
        else if (op == 7) c.limpiar();
        if (op != 0 && op != 7) c.mostrar();
    } while (op != 0);
    return 0;
}