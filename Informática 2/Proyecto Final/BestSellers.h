#pragma once

#include "Compras.h"

// La clase BestSellers representa los productos adquiridos con mayor frecuencia entre un grupo de clientes.
// Esta calse contiene un puntero a un objeto Compras que representa un conjunto de productos que fueron comprados por un
// grupo de clientes, así como un número entero que indica cuántas veces fue adquirido este conjunto de BestSellers entre los clientes.
class BestSellers
{
public:
    // Constructores

    // Constructor que no toma parámetros.
    BestSellers();

    // Constructor que toma un objeto Compras de enteros para inicializar un objeto Compras.
    BestSellers(Compras &productos);

    // Constructor que toma un entero y un objeto Compras de enteros para inicializar un objeto Compras.
    BestSellers(int repeticiones, Compras &productos);

    // Setter

    void setRepeticiones(int repeticiones);

    void setProductos(Compras &productos);

    // Getters

    int getRepeticiones();

    Compras *&getProductos();

    // Otros métodos

    // Operador =: retorna una referencia a la copia del objeto Compras dado como parámetro.
    BestSellers &operator=(const BestSellers &otro);

    // Método que convierte el objeto BestSellers a un string.
    std::string bestSellersToString();

    // Método que imprime el objeto BestSellers a la consola.
    void printBestSellers();

    // Método que libera la memoria donde se había alojado el puntero hacia los productos.
    void eliminarBestSellers();

    // Método destructor.
    ~BestSellers();

private:
    int repeticiones;
    Compras *productos;
};
