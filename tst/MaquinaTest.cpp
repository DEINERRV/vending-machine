#include "Maquina.h"
#include "gtest/gtest.h"

TEST(MaquinaTestSuite, InsertarProducto) {
    Maquina maquina;
    ProductoPerecedero *productoPerecedero = new ProductoPerecedero("Soda", 300, 3, 4, 3, 1950);
    ProductoNoPerecedero *productoNoPerecedero = new ProductoNoPerecedero("Refresco", 800, 1);
    EXPECT_EQ(maquina.get_product_list().size(), 0);
    maquina.insertar(productoPerecedero);
    maquina.insertar(productoNoPerecedero);
    EXPECT_EQ(maquina.get_product_list().size(), 2);
    delete productoPerecedero;
    delete productoNoPerecedero;
}

TEST(MaquinaTestSuite, AgregaryDisminuir_Provisiones) {
    Maquina maquina;
    ProductoPerecedero *productoPerecedero = new ProductoPerecedero("Soda", 300, 3, 4, 3, 1950);
    ProductoNoPerecedero *productoNoPerecedero = new ProductoNoPerecedero("Refresco", 800, 3);
    EXPECT_TRUE(maquina.agregarProvisiones("Soda", 1));
    EXPECT_TRUE(maquina.disminuirProvisiones("Refresco", 2));
}

TEST(MaquinaTestSuite, Borrar) {
    Maquina maquina;
    maquina.setIdentificador(4524784);
    maquina.setNombre("Time Machine 1");
    ProductoNoPerecedero *productoNoPerecedero = new ProductoNoPerecedero("Manzana", 800, 3);
    maquina.insertar(productoNoPerecedero);
    EXPECT_TRUE(maquina.borrar("Manzana"));
    delete productoNoPerecedero;
}

TEST(MaquinaTestSuite, ConsultarProduct) {
    Maquina maquina;
    maquina.setIdentificador(4524785);
    maquina.setNombre("Time Machine 2");
    ProductoNoPerecedero *productoNoPerecedero = new ProductoNoPerecedero("Gomitas", 800, 3);
    maquina.insertar(productoNoPerecedero);
    EXPECT_EQ(maquina.consultar("Gomitas"),productoNoPerecedero);
    delete productoNoPerecedero;
}

TEST(MaquinaTestSuite, IngresarDinero) {
    Maquina maquina;
    maquina.setIdentificador(4524786);
    maquina.setNombre("Time Machine 3");
    EXPECT_EQ(maquina.getMonederoElectronico().getDinero(),0);
    maquina.ingresarDinero(1000);
    EXPECT_EQ(maquina.getMonederoElectronico().getDinero(),1000);
}

TEST(MaquinaTestSuite, RetirarDinero) {
    Maquina maquina;
    maquina.setIdentificador(4524787);
    maquina.setNombre("Time Machine 4");
    maquina.ingresarDinero(1000);
    maquina.retirarDinero(400);
    EXPECT_EQ(maquina.getMonederoElectronico().getDinero(),600);
}

TEST(MaquinaTestSuite, ToString) {
    Maquina maquina;
    maquina.setIdentificador(4524788);
    maquina.setNombre("Time Machine 5");
    ProductoPerecedero *productoPerecedero = new ProductoPerecedero("Soda", 300, 3, 4, 3, 1950);
    maquina.insertar(productoPerecedero);
    EXPECT_EQ(maquina.toString(),
              "Identificador: 4524788\nNombre de la maquina: Time Machine 5\nLista de Productos: \nNombre: Soda\nCantidad: 3\nPrecio: 300\n\n");
    delete productoPerecedero;
}