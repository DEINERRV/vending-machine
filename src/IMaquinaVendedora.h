#ifndef PROGRA2_PROJECT_01_DELTA_IMAQUINAVENDEDORA_H
#define PROGRA2_PROJECT_01_DELTA_IMAQUINAVENDEDORA_H

#include <sstream>

class IMaquinaVendedora {
public:
    virtual ~IMaquinaVendedora();

    virtual std::string realizarCompra(std::string id, int cantidad, int montoPago) = 0;
};

#endif //PROGRA2_PROJECT_01_DELTA_IMAQUINAVENDEDORA_H