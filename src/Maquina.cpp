#include "Maquina.h"

Maquina::Maquina() {}

Maquina::Maquina(int identificador, const string &nombre, Producto *producto,
                 const MonederoElectronico &monederoElectronico) : identificador(identificador), nombre(nombre),
                                                                   producto(producto),
                                                                   monederoElectronico(monederoElectronico) {}

Maquina::~Maquina() {}

int Maquina::getIdentificador() { return identificador; }

void Maquina::setIdentificador(int identificador) { Maquina::identificador = identificador; }

string Maquina::getNombre() { return nombre; }

void Maquina::setNombre(const string &nombre) { Maquina::nombre = nombre; }

const vector<Producto *> &Maquina::get_product_list() { return product_list; }

void Maquina::insertar(Producto *product) { product_list.push_back(product); }

Producto *Maquina::getProducto() const { return producto; }

void Maquina::setProducto(Producto *producto) { Maquina::producto = producto; }

MonederoElectronico &Maquina::getMonederoElectronico() { return monederoElectronico; }

void Maquina::setMonederoElectronico(const MonederoElectronico &monederoElectronico) {
    Maquina::monederoElectronico = monederoElectronico;
}

bool Maquina::agregarProvisiones(string idProducto, int cantidad) {
    try {
        for (int i = 0; i < product_list.size(); i++) {
            if (product_list[i]->getNombre() == idProducto) {
                product_list[i]->setCantidad(product_list[i]->getCantidad() + cantidad);
                return true;
            }
        }
    }
    catch (std::invalid_argument in) { return false; }
    return false;
}

bool Maquina::disminuirProvisiones(string idProducto, int cantidad) {
    try {
        for (int i = 0; i < product_list.size(); i++) {
            if (product_list[i]->getNombre() == idProducto && cantidad <= product_list[i]->getCantidad()) {
                product_list[i]->setCantidad(product_list[i]->getCantidad() - cantidad);
                return true;
            }
        }
    }
    catch (std::invalid_argument in) { return false; }
    return false;
}

bool Maquina::borrar(string id) {
    try {
        for (int i = 0; i < product_list.size(); i++) {
            if (product_list[i]->getNombre() == id) {
                product_list.erase(product_list.begin() + i);
                return true;
            }
        }
    }
    catch (std::invalid_argument in) {
        return false;
    }
    return false;
}

Producto *Maquina::consultar(string id) {
    try {
        for (int i = 0; i < product_list.size(); i++) {
            if (product_list[i]->getNombre() == id) {
                return product_list[i];
            }
        }
    }
    catch (std::invalid_argument in) {
        throw std::runtime_error("dato erroneo");
    }
    return 0;
}

void Maquina::ingresarDinero(int cantidad) {
    try {
        monederoElectronico.setDinero(monederoElectronico.getDinero() + cantidad);
    }
    catch (std::invalid_argument in) {
        throw std::runtime_error("dato erroneo");
    }
}

void Maquina::retirarDinero(int cantidad) {
    try {
        if (cantidad <= monederoElectronico.getDinero()) {
            monederoElectronico.setDinero(monederoElectronico.getDinero() - cantidad);
        }
    }
    catch (std::invalid_argument in) {
        throw std::runtime_error("dato erroneo");
    }
}

string Maquina::realizarCompra(string id, int cantidad, int montoPago) {
    try {
        std::ostringstream output;
        for (int i = 0; i < product_list.size(); i++) {
            if (product_list[i]->getNombre() == id && product_list[i]->getCantidad() >= cantidad &&
                montoPago >= (product_list[i]->getPrecio() * cantidad)) {
                ingresarDinero(product_list[i]->getPrecio() * cantidad);
                disminuirProvisiones(id, cantidad);
                output << "Su vuelto es: \n";
                for (Vuelto aux:monederoElectronico.desgloceVuelto(product_list[i]->getPrecio() * cantidad, montoPago)) {
                    output << aux.cantidad << " " << aux.tipo << " de " << aux.valor << endl;
                }
                return output.str();
            }
        }
    }
    catch (std::invalid_argument in) {
        throw std::runtime_error("dato erroneo");
    }
    return "No se realizo la compra";
}

string Maquina::toString() {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);
    output << "Identificador: " << getIdentificador()
           << "\nNombre de la maquina: " << getNombre()
           << "\nLista de Productos: \n";
    for (int j = 0; j < product_list.size(); j++) {
        output << product_list[j]->toString() << endl;
    }
    return output.str();
}