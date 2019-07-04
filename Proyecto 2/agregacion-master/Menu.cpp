#include "Menu.h"
#include "Objeto.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

enum class Opciones { Agregar=1, Remover=2, Mostrar=3, Buscar = 4, Mover = 5, Boss = 6, Color = 7};


void limpiar() {
    cout << "";
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout << "4. Buscar objeto\n";
    cout << "5. Mover objeto\n";
    cout << "6. Agregar Boss\n";
    cout << "7. Cambiar color\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    int n = 0;

    auto nombre = input<TipoString>(" Ingrese Nombre : ");
    while(tierra.buscaroObjeto(nombre) != nullptr){
        cout << "El nombre ya existe, ingrese otro." << endl;
        nombre = input<TipoString>("Ingrese Nombre: ");
    }

    auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");

    do{
        n = 0;
        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        if(y == x){
            cout << "Existe un obstaculo escoja otra posicion." << endl;
            n++;
        }

        if (tierra.buscarPosicion(x,y) != nullptr and y != x) {
            cout << "Ya existe un robot en esa posicion." << endl;
            n++;
        }
        else
            tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
    }while (n > 0);

}

void Menu::Boss() {
    int n = 0;
    auto nombre = input<TipoString>(" Ingrese Nombre : ");
    while(tierra.buscaroObjeto(nombre) != nullptr){
        cout << "El nombre ya existe, ingrese otro." << endl;
        nombre = input<TipoString>("Ingrese Nombre: ");
    }

    auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");

    do{
        n = 0;
        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }

        TipoEntero Filas = input<TipoEntero>("Ingrese filas : ");
        TipoEntero Columnas = input<TipoEntero>("Ingrese columnas : ");


        if(y == x){
            cout << "Existe un obstaculo escoja otra posicion." << endl;
            n++;
        }

        if (tierra.buscarPosicion(x,y) != nullptr and y != x) {
            cout << "Ya existe un robot en esa posicion." << endl;
            n++;
        }
        else
            for(int i = x; i < Filas + x; i++){
                for(int j = y; j < Columnas + y; j++){
                    tierra.adicionarObjeto(new Objeto(nombre, color, i, j));
                }
            }

    }while (n > 0);

}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::cambiarColor() {
    int x, y;
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    while(obj == nullptr) {
        cout << "Objeto No existe\n";
        nombre = input<TipoString>("Ingrese Nombre: ");
    }
    if(obj != nullptr) {
        x = obj->getPosX();
        y = obj->getPosY();
        delete obj;
    }
    auto color  = input<TipoCaracter>("Ingrese nuevo color (Un caracter): ");
    tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
    esperar();
}

void Menu::buscarObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.buscaroObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        cout << "Objeto: " << nombre << " se encuentra en : " << obj->mostrarPosicion() << endl;
    }
    esperar();
}

void Menu::moverObjeto() {
    int n = 0;
    char color;
    auto nombre = input<TipoString>("Ingrese Nombre: ");
    Objeto *obj = tierra.removerObjeto(nombre);
    while (obj == nullptr) {
        cout << "Objeto No existe\n";
        nombre = input<TipoString>("Ingrese Nombre: ");
    }
    if(obj != nullptr){
        color = obj->getColor();
        delete obj;
    }


    do{
        n = 0;

        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        if(y == x){
            cout << "Existe un obstaculo escoja otra posicion." << endl;
            n++;
        }
        else
            tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
    }while (n > 0);

    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}

void Menu::ejecutar() {
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case Opciones::Buscar:
            buscarObjeto();
            break;
        case Opciones::Mover:
            moverObjeto();
            break;
        case Opciones::Boss:
            Boss();
            break;
        case Opciones::Color:
            cambiarColor();
            break;
    }
}