#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

Tierra::Tierra() {plano.resize(ALTURA); for (auto& item: plano) item.resize(ANCHO);}
Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {plano.resize(altura); for (auto& item: plano) item.resize(ancho);}

void Tierra::adicionarObjeto(Objeto* objeto){
    objetos.emplace_back(objeto);
}

Objeto* Tierra::removerObjeto(string& nombre) {
    // Buscando objeto
    if (objetos.size() == 0)
      return nullptr;

    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
      return nullptr;
    // Eliminando objeto
    objetos.erase(iter);
    //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
    return *iter;
}

Objeto* Tierra::buscaroObjeto(string &nombre){
    if (objetos.size() == 0)
        return nullptr;

    auto iter = find_if(begin(objetos), end(objetos), [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
            return nullptr;
    return *iter;

}

Objeto* Tierra::buscarPosicion(TipoEntero x, TipoEntero y) {
    if (objetos.size() == 0)
        return nullptr;

    auto _x = find_if(begin(objetos), end(objetos), [&x](Objeto* obj){ return obj->getPosX() == x; });
    auto _y = find_if(begin(objetos), end(objetos), [&y](Objeto* obj){ return obj->getPosY() == y; });
    if (_x == end(objetos) and _y == end(objetos))
        return nullptr;
    return *_x, *_y;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto& item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    for (auto &row: plano)
        for (auto &cell: row)
            cell = COLOR;

    for (auto& item: objetos)
        plano[item->getPosY()][item->getPosX()]
                = item->getColor();
}

void Tierra::dibujarTierra() {
    cout << '\n';
    cout << setw(3) << ' ';
    for (auto j = 0; j < getAncho(); ++j)
        cout << setw(3) << j;
    cout << '\n';

    for (auto i = 0; i < getAltura(); ++i) {
        cout << setw(3) << i;
        for (auto j = 0; j < getAncho(); ++j) {
            if(i == j)
                cout << setw(3) << "@";
            else
            cout << setw(3) << plano[i][j];
        }
        cout << '\n';
    }
}

TipoEntero Tierra::getAltura() {
    return plano.size();
}

TipoEntero Tierra::getAncho(){
    return plano[0].size();
}

