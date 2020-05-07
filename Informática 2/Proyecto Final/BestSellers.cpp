#include "BestSellers.h"

// Constructores

// Constructor que no toma parámetros.
BestSellers::BestSellers()
{
    this->repeticiones = 0;
    this->productos = nullptr;
}

// Constructor que toma un objeto Compras de enteros para inicializar un objeto Compras.
BestSellers::BestSellers(Compras &productos)
{
    Compras *ptrProductos = new Compras;
    *ptrProductos = productos;

    this->repeticiones = 0;
    this->productos = ptrProductos;
}

// Constructor que toma un entero y un objeto Compras de enteros para inicializar un objeto Compras.
BestSellers::BestSellers(int repeticiones, Compras &productos)
{
    Compras *ptrProductos = new Compras;
    *ptrProductos = productos;

    this->repeticiones = repeticiones;
    this->productos = ptrProductos;
}

// Setter

void BestSellers::setRepeticiones(int repeticiones)
{
    this->repeticiones = repeticiones;
}

void BestSellers::setProductos(Compras &productos)
{
    free(this->productos);

    this->productos = new Compras(productos);
}

// Getters

int BestSellers::getRepeticiones()
{
    return repeticiones;
}

Compras *&BestSellers::getProductos()
{
    return productos;
}

// Otros métodos

// Operador =: retorna una referencia a la copia del objeto Compras dado como parámetro.
BestSellers &BestSellers::operator=(const BestSellers &otro)
{
    eliminarBestSellers();

    Compras *aProductos = new Compras;
    *aProductos = *(otro.productos);

    this->repeticiones = otro.repeticiones;
    this->productos = aProductos;

    return *this;
}

// Método que convierte el objeto BestSellers a un string.
std::string BestSellers::bestSellersToString()
{
    std::string str = "";

    if (repeticiones != 0)
    {
        str += productos->arregloToString();
        str += " | Repeticiones: ";
        str += std::to_string(repeticiones);
    }

    else
    {
        str += "No hubo repeticiones en la compra de productos.";
    }

    return str;
}

// Método que imprime el objeto BestSellers a la consola.
void BestSellers::printBestSellers()
{
    std::cout << bestSellersToString();
}

// Método que libera la memoria donde se había alojado el puntero hacia los productos.
void BestSellers::eliminarBestSellers()
{
    repeticiones = 0;
    delete productos;
}

// Método destructor.
BestSellers::~BestSellers()
{
    eliminarBestSellers();
}
