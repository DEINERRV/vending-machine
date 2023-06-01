//
// Created by deine on 8/26/2020.
//

#include "MonederoElectronico.h"
#include<algorithm>
#include<sstream>

bool compareMonedaBillete(const MonedaBillete a1, const MonedaBillete a2) {
    return (a1.valor < a2.valor);
}
//esto funciona para enviarselo como tercer paramentor al metodo sort, que ordena un vector, sort lo tomara como regla para ordenar un vector de MonedaBillete


MonederoElectronico::MonederoElectronico(int _dinero,vector<MonedaBillete> _monedas){
    dinero=_dinero;

    coinList=_monedas;
    sort(coinList.begin(),coinList.end(),compareMonedaBillete);
}
MonederoElectronico::~MonederoElectronico()= default;

void MonederoElectronico::setDinero(int _dinero){
    dinero=_dinero;
}
int MonederoElectronico::getDinero(){
    return dinero;
}

void MonederoElectronico::setCoinlist(vector<MonedaBillete> _monedas){
    try {
        _monedas.empty()?throw "ERROR/ Lista vacia":
        coinList = _monedas;
        sort(coinList.begin(), coinList.end(),compareMonedaBillete);
    }
    catch (const char * error) {
        throw error;
    }
}

vector<MonedaBillete> MonederoElectronico::getCoinList(){
    return coinList;
}

string MonederoElectronico::toString(){
    stringstream s;

    s << "--Informacion del Monedero Electronico--" << endl;
    s << "Dinero: " << dinero << endl;
    s<<"tipo de monedas o billetes que puede delvolver la maquina: "<<endl;
    for( MonedaBillete element : coinList){
        s<<"("<<element.tipo<<") "<<element.valor<<endl;
    }

    return s.str();
}

vector<Vuelto> MonederoElectronico::desgloceVuelto(int precioProducto,int dineroIngresado){
    try {

       if(precioProducto>dineroIngresado){ throw "No alcansa el dinero";}

        vector<Vuelto> vuelto;

        int cantDinvuelto = dineroIngresado - precioProducto;
        int conteoVuelto = 0; //conteo de cuanto plata se lleva, sirve para verificar si ya se llego al monto objetivo(vuelto)
        int cantMismaMoneda = 0;
        int tipoMoneda = coinList.size() - 1;


        //para ir probando desde la moneda de mayor valor a la de menor valor
        while (tipoMoneda >= 0) {
            Vuelto aux;

            //este if funciona para confirmar cuantas "monedas" se un valor se pueden dar en el vuelta
            if (conteoVuelto + coinList[tipoMoneda].valor <= cantDinvuelto) {
                conteoVuelto += coinList[tipoMoneda].valor;
                cantMismaMoneda++;
            }

                //cuando la "moneda" deja de "funcionar" para dar el vuelto pasa aqui,
                //aqui es donde se asignan las variables de aux, el tipo(moneda o billete), el valor y la cantidad
            else {
                if (cantMismaMoneda > 0) {
                    //este if es para que no meta una variable de tipo Vuelto con cero contidad de esa moneda o billete

                    aux.tipo = coinList[tipoMoneda].tipo;
                    aux.valor = coinList[tipoMoneda].valor;
                    aux.cantidad = cantMismaMoneda;

                    vuelto.push_back(aux);
                }

                //se disminuye el tipoMoneda para volver al primer "if" con una moneda de menos valor
                tipoMoneda--;
                //se asigna el valor de 0 a cantMismaMoneda para "ver" cuantas veces se usa la proxima moneda en el vuelta
                cantMismaMoneda = 0;
            }
        }

        return vuelto;
    }
    catch (const char* error) {
        throw error;
    }
}