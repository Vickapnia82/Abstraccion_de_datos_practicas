#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

class PilaDinamica {
private:
    Nodo* tope = nullptr;
public:
    ~PilaDinamica() { limpiar(); }

    void push(int v) {
        Nodo* n = new Nodo{v, tope};
        tope = n;
        cout << "Se metio: " << v << "\n";
    }

    void pop() {
        if (!tope) { cout << "Pila vacia\n"; return; }
        Nodo* tmp = tope;
        cout << "Se saco: " << tmp->dato << "\n";
        tope = tope->sig;
        delete tmp;
    }

    // Para cuando el profe pide "elimina este valor"
    void eliminarPorValor(int v) {
        if (!tope) { cout << "Vacia\n"; return; }
        if (tope->dato == v) { pop(); return; }
        Nodo* act = tope;
        while (act->sig && act->sig->dato != v) act = act->sig;
        if (!act->sig) { cout << "No existe " << v << "\n"; return; }
        Nodo* tmp = act->sig;
        act->sig = tmp->sig;
        delete tmp;
        cout << "Eliminado: " << v << "\n";
    }

    void modificarTope(int nuevo) {
        if (!tope) { cout << "Vacia, no hay tope\n"; return; }
        cout << "Tope " << tope->dato << " -> " << nuevo << "\n";
        tope->dato = nuevo;
    }

    void modificarPorValor(int viejo, int nuevo) {
        Nodo* act = tope;
        while (act && act->dato != viejo) act = act->sig;
        if (!act) { cout << "No existe " << viejo << "\n"; return; }
        act->dato = nuevo;
        cout << "Modificado " << viejo << " -> " << nuevo << "\n";
    }

    void limpiar() {
        while (tope) pop();
        cout << "Pila limpia, lista para iniciar otro proceso\n";
    }

    void mostrar() {
        if (!tope) { cout << "Pila vacia\n"; return; }
        cout << "Pila (tope -> fondo): ";
        Nodo* act = tope;
        while (act) { cout << act->dato << " "; act = act->sig; }
        cout << "\n";
    }
};

int main() {
    PilaDinamica p;
    int op, val, val2;
    do {
        cout << "\n--- PILA DINAMICA 3 ---\n1.Push 2.Pop 3.Modificar Tope 4.Modificar por Valor 5.Eliminar por Valor 6.Mostrar 7.Limpiar / Nuevo Proceso 0.Salir\nOpcion: ";
        cin >> op;
        if (op == 1) { cout << "Valor: "; cin >> val; p.push(val); }
        else if (op == 2) p.pop();
        else if (op == 3) { cout << "Nuevo tope: "; cin >> val; p.modificarTope(val); }
        else if (op == 4) { cout << "Valor a cambiar: "; cin >> val; cout << "Nuevo: "; cin >> val2; p.modificarPorValor(val, val2); }
        else if (op == 5) { cout << "Valor a eliminar: "; cin >> val; p.eliminarPorValor(val); }
        else if (op == 6) p.mostrar();
        else if (op == 7) p.limpiar();
        if (op != 0 && op != 7) p.mostrar();
    } while (op != 0);
    return 0;
}