#include "MonederoElectronico.h"
#include "gtest/gtest.h"

TEST(MonederoTestSuite, desgloceVuelto) {

    vector<MonedaBillete> monedasBilletes;
    MonedaBillete cien;
    cien.tipo = "moneda";
    cien.valor = 100;

    MonedaBillete quinientos;
    quinientos.tipo = "moneda";
    quinientos.valor = 500;

    MonedaBillete mil;
    mil.tipo = "billete";
    mil.valor = 1000;

    MonedaBillete dosmil;
    dosmil.tipo = "billete";
    dosmil.valor = 2000;

    MonedaBillete cincomil;
    cincomil.tipo = "billete";
    cincomil.valor = 5000;


    monedasBilletes.push_back(cien);
    monedasBilletes.push_back(quinientos);
    monedasBilletes.push_back(mil);
    monedasBilletes.push_back(dosmil);
    monedasBilletes.push_back(cincomil);

    MonederoElectronico monedero(5000, monedasBilletes);
    vector<Vuelto> aux;
    Vuelto cienAux;
    cienAux.cantidad = 4;
    cienAux.tipo = "moneda";
    cienAux.valor = 100;
    aux.push_back(cienAux);

    vector<Vuelto> auxDesgloceVuelto = monedero.desgloceVuelto(100, 500);

    ASSERT_EQ(auxDesgloceVuelto.size(), aux.size());
    for (int i; i < aux.size(); i++) {
        ASSERT_EQ(auxDesgloceVuelto[i].cantidad, aux[i].cantidad);
        ASSERT_EQ(auxDesgloceVuelto[i].valor, aux[i].valor);
        ASSERT_EQ(auxDesgloceVuelto[i].tipo, aux[i].tipo);
    }


}