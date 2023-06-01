//
// Created by Chris on 9/25/2020.
//
#include <ProductoNoPerecedero.h>
#include "gtest/gtest.h"

TEST(ProductoNoPerecederoSuiteTest, CheckToString){
    ProductoNoPerecedero producto;
    producto.setNombre("Chicky");
    producto.setCantidad(1);
    producto.setPrecio(500);

    EXPECT_EQ(producto.toString(), "-- Producto no perecedero --\nNombre: Chicky\nCantidad: 1\nPrecio: 500\n\n");
}