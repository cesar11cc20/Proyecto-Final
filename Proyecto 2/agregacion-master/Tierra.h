#ifndef AGREGACION_TIERRA_H
#define AGREGACION_TIERRA_H

#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"

using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    vector<vector<char>> plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra(){};
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    Objeto* buscaroObjeto(string& nombre);
    Objeto* buscarPosicion(TipoEntero x, TipoEntero y);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void dibujarTierra();
    void actualizarTierra();

};

#endif

