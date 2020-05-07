#pragma once

#include <iostream>
#include <string>

// La clase Compras representa los productos adquiridos por un cliente. Ésta agrupa un arreglo de números enteros, que
// representa los productos comprados por un cliente, así como un número entero que indica la longitud de dicho arreglo.
class Compras
{
public:
    // Constructores

    // Constructor que no toma parámetros.
    Compras();

    // Constructor que toma un entero y un arreglo de enteros para inicializar un objeto Compras.
    Compras(int longitud, int *elementos);

    // Constructor que toma un string de números para inicializar un objeto Compras.
    Compras(std::string sElementos);

    // Setter

    // Método que asigna o reasigna los elementos a un objeto Compras.
    void setElementos(int longitud, int *elementos);

    // Getters

    int getLongitud();

    int *getElementos();

    // Otros métodos

    // Método que ordena los elemento del arreglo de menor a mayor.
    void minToMax();

    // Método que ordena los elemento del arreglo de mayor a menor.
    void maxToMin();

    // Método que ordena los elementos de menor a mayor y reduce el arreglo a su mínima expresión,
    // donde ningún número se repite dentro del arreglo.
    void ordenarElementos();

    // Operador =: retorna una referencia a la copia del objeto Compras dado como parámetro.
    Compras &operator=(const Compras &otro);

    // Operador []: retorna el número entero correpondiente al índice dado como parámetro.
    int operator[](const int indice);

    // Operador ==: determina si dos objetos Compras tienen los mismos elementos en el mismo orden.
    bool operator==(const Compras &otroArreglo);

    // Operador !=: determina si los elementos de dos objetos Compras son distintos.
    bool operator!=(const Compras &otroArreglo);

    // Método que retorna el objeto Compras en forma de string.
    std::string arregloToString();

    // Método que imprime el objeto Compras a la consola.
    void printArreglo();

    // Método que libera la memoria donde se había alojado el arreglo de números enteros que representó los productos.
    void eliminarArreglo();

    // Método destructor.
    ~Compras();

private:
    int longitud;
    int *elementos;

    // Método que indica el número de productos únicos que posee el arreglo (elementos sin repetir).
    // Para que este método funcione adecuadamente, es necesario que el arreglo esté ordenado de
    // menor a mayor o viceversa. Se puede llamar al método minToMax() o maxToMin() para ello.
    int elementosUnicos();

    // Método que disminuye el tamaño del arreglo para que contengo solamente los elementos sin repetir.
    void reducir();

    // Método que determina la cantidad de números presentes dentro de un string, al contar las comas que separan los números.
    // Para que funciones adecuadamente, es necesario que el string esté formateado correctamente con la función formatearString().
    int cantidadDeNumerosEnString(std::string numeros);

    // Método que acepta un string de números separados por comas y retorna un arreglo que comprende dichos números.
    // Para que funciones adecuadamente, es necesario que el string esté formateado correctamente con la función formatearString().
    int *stringToArreglo(std::string &numeros);
};
