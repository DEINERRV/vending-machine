#ifndef PROGRA2_PROJECT_01_DELTA_MAQUINA_H
#define PROGRA2_PROJECT_01_DELTA_MAQUINA_H

#include <vector>
#include <iomanip>

#include "IMaquinaAdministradora.h"
#include "IMaquinaVendedora.h"
#include "ProductoNoPerecedero.h"
#include "ProductoPerecedero.h"
#include "MonederoElectronico.h"

class Maquina : public IMaquinaAdministradora, public IMaquinaVendedora {
    int identificador;
    string nombre;
    vector<Producto *> product_list;
    Producto *producto;
    MonederoElectronico monederoElectronico;

public:
    Maquina();

    Maquina(int identificador, const string &nombre, Producto *producto,
            const MonederoElectronico &monederoElectronico);

    ~Maquina();

    int getIdentificador() override;

    void setIdentificador(int identificador);

    string getNombre() override;

    void setNombre(const string &nombre) override;

    const vector<Producto *> &get_product_list();

    void insertar(Producto *);

    Producto *getProducto() const;

    void setProducto(Producto *producto);

    MonederoElectronico &getMonederoElectronico() override;

    void setMonederoElectronico(const MonederoElectronico &monederoElectronico) override;

    bool agregarProvisiones(string idProducto, int cantidad) override;

    bool disminuirProvisiones(string idProducto, int cantidad) override;

    bool borrar(string id) override;

    Producto *consultar(string id);

    void ingresarDinero(int cantidad) override;

    void retirarDinero(int cantidad) override;

    string realizarCompra(string, int, int) override;

    string toString() override;
};

#endif //PROGRA2_PROJECT_01_DELTA_MAQUINA_H