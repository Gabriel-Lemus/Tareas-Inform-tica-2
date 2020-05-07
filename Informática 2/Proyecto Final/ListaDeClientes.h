#pragma once

#include "Compras.h"
#include "BestSellers.h"

// Clase que representa a un conjunto de clientes. Esta clase posee cuatro miembros: (1.) un arreglo de objetos Compras, que representan los productos
// adquiridos por los clientes y (2.) un entero que indica la cantidad de clientes dentro de dicho arreglo; así como (3.) un arreglo de BestSellers que
// representa los mejores productos o bien, los productos que fueron comprados en en conjunto dentro del arreglo de Compras, así como (4.) un entero que
// indica la cantidad de bestsellers dentro de dicho arreglo.
class ListaDeClientes
{
public:
    // Constructores

    // Constructor que no toma parámetros.
    ListaDeClientes();

    // Constructor que toma un entero que representa el número de clientes y un arreglo de objetos Compras que representan los productos adquiridos.
    ListaDeClientes(int numeroDeClientes, Compras *&compras);

    // Constructor que toma un entero que representa el número de clientes y un arreglo de objetos Compras que representan los productos adquiridos,
    // así como un entero que representa el número de BestSellers y un arreglo de BestSellers.
    ListaDeClientes(int numeroDeClientes, Compras *&compras, int numeroDeBestSellers, BestSellers *&bestSellers);

    // Setters

    void setCompras(int numeroDeClientes, Compras *&compras);

    void setBestSellers(int numeroDeBestSellers, BestSellers *&bestSellers);

    // Getters

    int getNumeroDeClientes();

    Compras *getCompras();

    int getNumeroDeBestSellers();

    BestSellers *getBestSellers();

    // Otros métodos

    // Método que determina cuáles son los bestsellers (productos más populares entre los clientes) entre el grupo de clientes,
    // así como el número de veces que cada conjunto de productos fue adquirido.
    void encontrarBestSellers();

    // Método que convierte un objeto ListaDeClientes a un string.
    std::string listaDeClientesToString();

    // Método que imprime la ListaDeClientes a la consola.
    void printListaDeClientes();

    // Método que libera la memoria donde se había alojado el arreglo de Compras que representó productos adquiridos por los clientes,
    // así como el arreglo de BestSellers que representó los productos más populares comprados en conjunto entre los clientes.
    void eliminarListaDeClientes();

    // Método destructor.
    ~ListaDeClientes();

private:
    int numeroDeClientes;
    Compras *compras;
    int numeroDeBestSellers;
    BestSellers *bestSellers;

    // Método que determina el número BestSellers presente dentro de los productos adquiridos por los clientes.
    // Este método no discrimina los bestsellers repetidos, por lo que el número obtenido por este método no será el criterio final.
    int gruposDeBestSellers();

    // Método que puebla el miembro bestSellers con un arreglo que contiene los BestSellers del grupo de clientes. Este arreglo de BestSellers
    // no está ordenado por el número de elementos y éstos no cuentan con el número de veces que cada conjunto de productos fue adquirido (miembro "repeticiones").
    void productosComunes();

    // Método que elimina los BestSellers repetidos del arreglo. No obstante, éste método no determina cuántas veces fue adquirido cada conjunto de productos.
    // Para ello, se llama al método contarRepeticiones().
    void reducirBestSellers();

    // Método que itera por el arreglo de BestSellers y determina cúantas veces fue adquirido cada conjunto de productos.
    void contarRepeticiones();

    // Método que ordena de mayor a menor, el arreglo de BestSellers, según las repeticiones de los conjuntos de productos.
    void ordenarBestSellers();

    // Método que ordena el arreglo de BestSellers de mayor a menor, según la cantidad de productos de cada conjunto de productos.
    void maxToMinBestSellers();
};
