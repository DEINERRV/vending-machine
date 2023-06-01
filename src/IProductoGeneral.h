//
// Created by Chris on 9/7/2020.
//

#ifndef PROYECTOS_IPRODUCTOGENERAL_H
#define PROYECTOS_IPRODUCTOGENERAL_H

#include <string>

class IProductoGeneral {
public:
    virtual ~IProductoGeneral();
    virtual std::string toString() const =0;
};


#endif //PROYECTOS_IPRODUCTOGENERAL_H
