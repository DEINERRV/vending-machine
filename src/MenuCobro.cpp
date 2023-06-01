//
// Created by deine on 9/5/2020.
//

#include "MenuCobro.h"
#include<windows.h>

MenuCobro::MenuCobro(Maquina *_maquina) {
    maquina = _maquina;
}

MenuCobro::~MenuCobro() { delete maquina; }

Maquina *MenuCobro::getMaquina() { return maquina; }

void MenuCobro::setMaquina(Maquina *_maquina) { maquina = _maquina; }

void MenuCobro::mostrarProductos() {
    cout << maquina->toString() << endl;
    system("pause");
    system("cls");
}

void MenuCobro::realizarCompra() {
    try {
        int cantidad;
        int dinero;
        string id;

        cout << "Digite el ID del producto que desea seleccionar: ";
        cin.ignore();
        getline(cin, id);

        cout << "Digite la cantidad que desea de este producto : ";
        cin >> cantidad;

        if (!cin.good() || cantidad < 0) { throw "Dato invalido"; }

        cout << "Digite cuanto dinero va a ingresar a la maquina : ";
        cin >> dinero;

        if (!cin.good() || dinero<0) { throw "Dato invalido"; }

        cout << maquina->realizarCompra(id, cantidad, dinero) << endl;
        Sleep(500);
    }
    catch (const char *error) {
        cout << error << endl;
        cin.clear();
        system("pause");
    }
    catch (exception error) {
        cout << error.what() << endl;
        system("pause");
    }
}


void MenuCobro::mostrar() {
    try {
        int opcion = 100;

        while (opcion != 0) {
            fflush(stdin);

            cout << "----------MENU----------\n\n";
            cout << "1) Mostrar Productos" << endl;
            cout << "2) Realizar Compra" << endl;
            cout << "0) Salir Del Menu Administrador " << endl;

            cout << "Digite una opcion ";
            cin >> opcion;

            if (!cin.good()) {
                throw "Dato invalido";
            }

            switch (opcion) {
                case 1:
                    mostrarProductos();
                    break;
                case 2:
                    realizarCompra();
                    break;
                default:
                    cout << "No se digito una opcion valida " << endl;
                    cout << "Por favor digite una opcion valida (1,2 o 0)" << endl;
                    system("pause");
                    system("cls");
                    break;
            }
        }

        //esto es para cuando se haya digitado la opcion 0 ( la de salida)
        system("cls");
        cout << "saliendo del Menu de Cobro..." << endl;
        Sleep(500);
        system("cls");
    }
    catch (const char *error) {
        cout << error << endl;
        cin.clear();
        system("pause");
    }
    catch (exception error) {
        cout << error.what() << endl;
        system("pause");
    }
}