#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
    Nodo* ant;
};

class ListaDoble {
private:
    Nodo* inicio = nullptr;
    Nodo* fin = nullptr;
public:
    ~ListaDoble() { limpiar(); }

    void insertarInicio(int v) {
        Nodo* n = new Nodo{v, inicio, nullptr};
        if (inicio) inicio->ant = n; else fin = n;
        inicio = n;
        cout << "Inicio: " << v << "\n";
    }
    void insertarFinal(int v) {
        Nodo* n = new Nodo{v, nullptr, fin};
        if (fin) fin->sig = n; else inicio = n;
        fin = n;
        cout << "Final: " << v << "\n";
    }

    void insertarEnPos(int pos, int v) {
        if (pos == 0) { insertarInicio(v); return; }
        Nodo* act = inicio;
        for (int i = 0; act && i < pos; i++) act = act->sig;
        if (!act) { insertarFinal(v); return; }
        Nodo* n = new Nodo{v, act, act->ant};
        act->ant->sig = n;
        act->ant = n;
        cout << "Insertado " << v << " en pos " << pos << "\n";
    }

    void eliminarEnPos(int pos) {
        Nodo* act = inicio;
        for (int i = 0; act && i < pos; i++) act = act->sig;
        if (!act) { cout << "Pos invalida\n"; return; }
        cout << "Eliminado: " << act->dato << " en pos " << pos << "\n";
        if (act->ant) act->ant->sig = act->sig; else inicio = act->sig;
        if (act->sig) act->sig->ant = act->ant; else fin = act->ant;
        delete act;
    }

    void eliminarPorValor(int v) {
        Nodo* act = inicio;
        while (act && act->dato != v) act = act->sig;
        if (!act) { cout << "No existe " << v << "\n"; return; }
        if (act->ant) act->ant->sig = act->sig; else inicio = act->sig;
        if (act->sig) act->sig->ant = act->ant; else fin = act->ant;
        delete act;
        cout << "Eliminado valor: " << v << "\n";
    }

    void modificarEnPos(int pos, int nuevo) {
        Nodo* act = inicio;
        for (int i = 0; act && i < pos; i++) act = act->sig;
        if (!act) { cout << "Pos invalida\n"; return; }
        cout << "Pos " << pos << ": " << act->dato << " -> " << nuevo << "\n";
        act->dato = nuevo;
    }

    void limpiar() {
        while (inicio) { Nodo* tmp = inicio; inicio = inicio->sig; delete tmp; }
        fin = nullptr;
        cout << "Lista limpia, lista para iniciar otro proceso\n";
    }

    void mostrar() {
        if (!inicio) { cout << "Lista vacia\n"; return; }
        cout << "Lista: NULL <-> ";
        Nodo* act = inicio;
        while (act) { cout << act->dato << " <-> "; act = act->sig; }
        cout << "NULL\n";
    }
};

int main() {
    ListaDoble l;
    int op, val, pos, nuevo;
    do {
        cout << "\n--- LISTA DOBLE 5 ---\n1.Inicio 2.Final 3.Insertar en Pos 4.Eliminar en Pos 5.Eliminar por Valor 6.Modificar en Pos 7.Mostrar 8.Limpiar / Nuevo Proceso 0.Salir\nOpcion: ";
        cin >> op;
        if (op == 1) { cout << "Valor: "; cin >> val; l.insertarInicio(val); }
        else if (op == 2) { cout << "Valor: "; cin >> val; l.insertarFinal(val); }
        else if (op == 3) { cout << "Pos: "; cin >> pos; cout << "Valor: "; cin >> val; l.insertarEnPos(pos, val); }
        else if (op == 4) { cout << "Pos a eliminar: "; cin >> pos; l.eliminarEnPos(pos); }
        else if (op == 5) { cout << "Valor a eliminar: "; cin >> val; l.eliminarPorValor(val); }
        else if (op == 6) { cout << "Pos a modificar: "; cin >> pos; cout << "Nuevo: "; cin >> nuevo; l.modificarEnPos(pos, nuevo); }
        else if (op == 7) l.mostrar();
        else if (op == 8) l.limpiar();
        if (op != 0 && op != 8) l.mostrar();
    } while (op != 0);
    return 0;
}