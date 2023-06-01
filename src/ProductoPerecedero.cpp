//
// Created by Chris on 8/29/2020.
//

#include <sstream>
#include "ProductoPerecedero.h"

ProductoPerecedero::ProductoPerecedero(){}

ProductoPerecedero::ProductoPerecedero(string name, int precio, int cantidad,int day, int month, int year)
        : Producto(name, precio, cantidad),dia(day),mes(month),anho(year){}


ProductoPerecedero::~ProductoPerecedero() {}

int ProductoPerecedero::aplicacionDelDescuento() const{
    return (getPrecio() - (getPrecio() * 0.50));
}

int ProductoPerecedero::getDia() {
    return dia;
}
void ProductoPerecedero::setDia(int day) {
    dia = day;
}

int ProductoPerecedero::getMes() {
    return mes;
}
void ProductoPerecedero::setMes(int month) {
    mes = month;
}

int ProductoPerecedero::getAnho() {
    return anho;
}
void ProductoPerecedero::setAnho(int year) {
    anho = year;
}

int ProductoPerecedero::fechaVencimiento(fecha fechaVen,fecha actual) {
    int vencimiento = 0;
    vencimiento = actual.anho - fechaVen.anho;
    if (fechaVen.mes == actual.mes && fechaVen.dia > actual.dia) {
        vencimiento--;
    }
    else {
        if (fechaVen.mes > actual.mes) {
            vencimiento--;
        }
    }
    return vencimiento;
}

bool ProductoPerecedero::Vencimiento(fecha const& f1, fecha const& f2) {
    ProductoPerecedero fecha;
    if (f1.mes == f2.mes) {
        return aplicacionDelDescuento();
    }
    else {
        if (f1.mes != f2.mes) {
            return "No se aplica el descuento";
        }
    }
    return true;
}

std::string ProductoPerecedero::toString() const{
    stringstream s;
    s<<"-- Producto perecedero --"<<endl
    <<Producto::toString()<<endl;
    return s.str();
}