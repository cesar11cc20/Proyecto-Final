#ifndef AGREGACION_MENU_H
#define AGREGACION_MENU_H


#include <limits>
#include "Tierra.h"
#include "Tipos.h"

template <typename T>
T input(string label) {
  T value;
  cout << label;
  cin >> value;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  return value;
}

/*
//--- Esta seria la funcion para leer un string,
//--- esta funcion si se quiere generalizar para colocar un label
//--- y leer cualquier tipo de dato se tendria que convertir al template anterior

string&& input(string label) {
  string value;
  cout << label;
  cin >> value;
  return move(value);
}
 */


class Menu {
    TipoEntero opcion;
    Tierra tierra;
    void imprimirMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
    void buscarObjeto();
    void moverObjeto();
    void Boss();
    void cambiarColor();
public:
    Menu(): opcion{} {}
    void ejecutar();
};

#endif
