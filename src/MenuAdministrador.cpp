//
// Created by deine on 9/4/2020.
//
#include<iostream>

using namespace std;

#include<windows.h>

#include "MenuAdministrador.h"

MenuAdministrador::MenuAdministrador(IMaquinaAdministradora *_maquina) {
    maquina = _maquina;
}

MenuAdministrador::~MenuAdministrador() { delete maquina; }

IMaquinaAdministradora *MenuAdministrador::getMaquina() { return maquina; }

void MenuAdministrador::setMaquina(IMaquinaAdministradora *_maquina) { maquina = _maquina; }


void MenuAdministrador::ingresarDinero() {
    try {
        int dinero = 0;

        cout << "Digite el monto a ingresar a la maquina : ";
        cin >> dinero;

        if (!cin.good() || dinero < 0) {
            throw "Dato invalida";
        }

        maquina->ingresarDinero(dinero);


        Sleep(500);
        system("cls");
        cout << "Se esta realizando la transferencia..." << endl;
        Sleep(500);
        system("cls");
        //esto es para que el menu se vea mas realista

        cout << "Se realizo la transferencia con exito" << endl;
        cout << "Se ingreso " << dinero << "al monedero " << endl;
        //cout<<"La cantidad de dinero actual del monedero es de : "<<maquina.getMonederoElectronico().getDinero()<<endl;

        system("pause");
        system("cls");
        //para pausar la pantalla y luego limpiarla

    }
    catch (const char *error) {
        cout << error << endl;
        cin.clear();
        system("pause");
    }
    catch (std::exception error) {
        cout << error.what() << endl;
        system("pause");
    }
}


void MenuAdministrador::retirarDinero() {
    try {
        int dinero = 0;

        cout << "Digite el monto a retirar de la maquina : ";
        cin >> dinero;

        if (!cin.good() || dinero < 0) { throw "Dato invalido"; }

        maquina->retirarDinero(dinero);


        Sleep(500);
        system("cls");
        cout << "Se esta realizando la transferencia..." << endl;
        Sleep(500);
        system("cls");
        //esto es para que el menu se vea mas realista

        cout << "Se realizo la transferencia con exito" << endl;
        cout << "Se retiro " << dinero << "del monedero " << endl;
        //cout<<"La cantidad de dinero actual del monedero es de : "<<maquina.getMonederoElectronico().getDinero()<<endl;

        system("pause");
        system("cls");
        //para pausar la pantalla y luego limpiarla
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


void MenuAdministrador::consultarDinero() const {
    cout << "El dinero actual del monedero de la maquina es de : " << maquina->getMonederoElectronico().getDinero()<< endl;

    fflush(stdin);
    system("pause");
    system("cls");
}


void MenuAdministrador::agregarProvisiones() {
    try {
        string idProducto = " ";
        int cantidadProducto = 0;

        cout << "Digite el ID del producto : ";

        cin >> idProducto;

        cout << "Digite la cantidad de provisiones a agregar : ";
        cin >> cantidadProducto;

        if (!cin.good() || cantidadProducto < 0) { throw "Dato invalido"; }

        if (maquina->agregarProvisiones(idProducto, cantidadProducto) == true) {
            cout << "Se agregaron las provisiones con exito" << endl;
        } else { cout << "No se pudieron agregar las provisiones" << endl; }

        Sleep(500);
        system("cls");
        cout << "Se estan agregando las provisiones..." << endl;
        Sleep(500);
        system("cls");


        system("pause");
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


void MenuAdministrador::disminuirProvisiones() {
    try {
        string idProducto = " ";
        int cantidadProducto = 0;

        cout << "Digite el ID del producto : ";
        cin.ignore();
        getline(cin, idProducto);

        cout << "Digite la cantidad de provisiones a retirar : ";
        cin >> cantidadProducto;

        if (!cin.good() || cantidadProducto < 0) { throw "Dato invalido"; }

        if (maquina->disminuirProvisiones(idProducto, cantidadProducto) == true) {
            cout << "Se han retirado las provisiones con exito" << endl;
        } else { cout << "No se han podido retirar las provisiones" << endl; }


        Sleep(500);
        system("cls");
        cout << "Se estan retirando las provisiones..." << endl;
        Sleep(500);
        system("cls");


        system("pause");
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


void MenuAdministrador::eliminarDelTodoUnProducto() {
    //Ya que es una opcion tan seria decidi agregar este pequenno codigo que es para confirmar que se desea eliminar un producto
    try {
        int opcion = 0;

        cout << "Esta seguro de que desea ELIMINAR algun producto [ 1) SI o 2) NO ]" << endl;
        cout << "Digite una opcion : ";
        cin >> opcion;

        if (!cin.good()) {
            throw "Dato invalido";
        }

        if (opcion == 2) {
            system("cls");
            cout << "No se eliminara ningun producto" << endl;
            Sleep(500);
            system("cls");
        } else if (opcion == 1) {
            cin.ignore();
            string idProducto;

            cout << "Digite el ID del producto que desea ELIMINAR : ";
            getline(cin, idProducto);

            maquina->borrar(idProducto);

            Sleep(500);
            system("pause");
            cout << "Se esta eliminando el producto..." << endl;
            Sleep(500);
            system("cls");

            cout << "Se elimino correctamente el producto" << endl;

            system("pause");
            system("cls");
        } else {
            cout << "No se digito ninguna opcion valida" << endl;

            system("pause");
            system("cls");
        }
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

void MenuAdministrador::informacionMaquina() {
    cout<< maquina->toString() << endl;
}

void MenuAdministrador::mostrar() {
    try {
        int opcion;

        do {
            cout << "----------MENU----------\n\n";
            cout << "1) Consultar Dinero" << endl;
            cout << "2) Ingresar Dinero" << endl;
            cout << "3) Retirar Dinero" << endl;
            cout << "4) Agregar Provisiones" << endl;
            cout << "5) Disminuir Provisiones" << endl;
            cout << "6) Eliminar Un Producto" << endl;
            cout << "7) Informacion De La Maquina" << endl;
            cout << "0) Salir Del Menu Administrador " << endl;

            cout << "Digite una opcion ";
            cin >> opcion;

            if (!cin.good()) {
                throw "Dato invalido";
            }

            switch (opcion) {
                case 0:
                    break;
                case 1:
                    consultarDinero();
                    break;
                case 2:
                    ingresarDinero();
                    break;
                case 3:
                    retirarDinero();
                    break;
                case 4:
                    agregarProvisiones();
                    break;
                case 5:
                    disminuirProvisiones();
                    break;
                case 6:
                    eliminarDelTodoUnProducto();
                    break;
                case 7:
                    informacionMaquina();
                    break;
                default:
                    cout << "No se digito una opcion valida " << endl;
                    cout << "Por favor digite una opcion valida (1,2,3,4,5,6,7 o 0)" << endl;
                    system("pause");
                    system("cls");
                    break;
            }
            fflush(stdin);
        } while (opcion != 0);

        //esto es para cuando se haya digitado la opcion 0( la de salida)
        system("cls");
        cout << "saliendo del Menu de Administradores..." << endl;
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


