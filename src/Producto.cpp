#include <sstream>
#include "Producto.h"

Producto::Producto(){
    nombre="";
    precio=0;
    cantidad=0;
}
Producto::Producto(string _nom,int _pre,int _cant)
    :nombre(_nom),precio(_pre),cantidad(_cant){}
Producto::~Producto(){}

string Producto::getNombre() const{
    return nombre;
}
void Producto::setNombre(string _nom){
    nombre=_nom;
}

int Producto::getPrecio() const{
    return precio;
}

void Producto::setPrecio(int _pre){
    precio=_pre;
}

int Producto::getCantidad() const{
    return cantidad;
}
void Producto::setCantidad(int _cant){
    cantidad=_cant;
}

int Producto::aplicacionDelDescuento() const{
    return getPrecio();
}

string Producto::toString() const{
    stringstream s;
    s<<"Nombre: "<<nombre<<endl
    <<"Cantidad: "<<cantidad<<endl
    <<"Precio: "<<precio<<endl;
    return s.str();
}