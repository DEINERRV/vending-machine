#include "MenuManager.h"
#include "Maquina.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"

int main() {

    MenuManager menu;

    vector<MonedaBillete> monedasBilletes;
    MonedaBillete cien; cien.tipo="moneda";cien.valor=100;
    MonedaBillete quinientos; quinientos.tipo="moneda";quinientos.valor=500;
    MonedaBillete mil; mil.tipo="billete";mil.valor=1000;
    MonedaBillete dosmil;dosmil.tipo="billete";dosmil.valor=2000;
    MonedaBillete cincomil; cincomil.tipo="billete"; cincomil.valor=5000;


    monedasBilletes.push_back(cien);
    monedasBilletes.push_back(quinientos);
    monedasBilletes.push_back(mil);
    monedasBilletes.push_back(dosmil);
    monedasBilletes.push_back(cincomil);

    MonederoElectronico monedaro(5000,monedasBilletes);
    for(Vuelto aux : monedaro.desgloceVuelto(100,1000)){
        cout<<aux.valor<<endl;
    }

    Maquina maquina(1, "Maquina", nullptr, monedaro);

    ProductoPerecedero ProductoPerecedero1("Perecedero1", 100, 1, 1, 1, 1);
    ProductoPerecedero ProductoPerecedero2("Perecedero2", 200, 2, 2, 2, 2);
    ProductoPerecedero ProductoPerecedero3("Perecedero3", 300, 3, 3, 3, 3);
    ProductoPerecedero ProductoPerecedero4("Perecedero4", 400, 4, 4, 4, 4);


    ProductoNoPerecedero ProductoNoPerecedero1("NoPerecedero", 100, 1);
    ProductoNoPerecedero ProductoNoPerecedero2("NoPerecedero2",200,2);
    ProductoNoPerecedero ProductoNoPerecedero3("NoPerecedero3",300,3);
    ProductoNoPerecedero ProductoNoPerecedero4("NoPerecedero4",400, 4);

    maquina.insertar(&ProductoPerecedero1);
    maquina.insertar(&ProductoPerecedero2);
    maquina.insertar(&ProductoPerecedero3);
    maquina.insertar(&ProductoPerecedero4);

    maquina.insertar(&ProductoNoPerecedero1);
    maquina.insertar(&ProductoNoPerecedero2);
    maquina.insertar(&ProductoNoPerecedero3);
    maquina.insertar(&ProductoNoPerecedero4);


    MenuAdministrador menuAdmin(&maquina);
    MenuCobro menuCobro(&maquina);



    int opcion = 2;
    while(opcion!=0) {
        try {
            fflush(stdin);
            cout << "1 MenuAdmin" << endl;
            cout << "2 MenuCobro" << endl;
            cout << "0 Salir" << endl;
            cin>>opcion;

            if(!cin.good()){
                throw "ERROR";
            }

            switch (opcion) {
                case 1:
                    menu.mostrarMenu(&menuAdmin);
                    break;
                case 2:
                    menu.mostrarMenu(&menuCobro);
                    break;
                case 0:cout<<"salir"; break;
                default: cout<<"no se digito una opcion valida"<<endl;break;
            }
        }
        catch (const char * error) {
            cout<<error<<endl;
            cin.clear();
            opcion=2;
            system("pause");
        }
        fflush(stdin);
    }


    return 0;
}