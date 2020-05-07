#include "Compras.h"

// Constructores

// Constructor que no toma parámetros.
Compras::Compras()
{
    this->longitud = 0;
    this->elementos = nullptr;
}

// Constructor que toma un entero y un arreglo de enteros para inicializar un objeto Compras.
Compras::Compras(int longitud, int *elementos)
{
    this->longitud = longitud;
    this->elementos = new int[longitud];

    for (int i = 0; i < longitud; i++)
    {
        this->elementos[i] = elementos[i];
    }

    ordenarElementos();
}

// Constructor que toma un string de números para inicializar un objeto Compras.
Compras::Compras(std::string sElementos)
{
    this->longitud = cantidadDeNumerosEnString(sElementos);
    this->elementos = stringToArreglo(sElementos);
    ordenarElementos();
}

// Setter

// Método que asigna o reasigna los elementos a un objeto Compras.
void Compras::setElementos(int longitud, int *elementos)
{
    delete this->elementos;

    this->longitud = longitud;
    this->elementos = new int[longitud];

    for (int i = 0; i < longitud; i++)
    {
        this->elementos[i] = elementos[i];
    }
}

// Getters

int Compras::getLongitud()
{
    return longitud;
}

int *Compras::getElementos()
{
    return elementos;
}

// Otros métodos

// Método que ordena los elemento del arreglo de menor a mayor.
void Compras::minToMax()
{
    for (int i = 0; i < longitud; i++)
    {
        for (int j = i + 1; j < longitud; j++)
        {
            if (elementos[i] > elementos[j])
            {
                int temporal = elementos[i];
                elementos[i] = elementos[j];
                elementos[j] = temporal;
            }
        }
    }
}

// Método que ordena los elemento del arreglo de mayor a menor.
void Compras::maxToMin()
{
    for (int i = 0; i < longitud; i++)
    {
        for (int j = i + 1; j < longitud; j++)
        {
            if (elementos[i] < elementos[j])
            {
                int temporal = elementos[i];
                elementos[i] = elementos[j];
                elementos[j] = temporal;
            }
        }
    }
}

// Método que ordena los elementos de menor a mayor y reduce el arreglo a su mínima expresión,
// donde ningún número se repite dentro del arreglo.
void Compras::ordenarElementos()
{
    minToMax();
    reducir();
}

// Operador =: retorna una referencia a la copia del objeto Compras dado como parámetro.
Compras &Compras::operator=(const Compras &otro)
{
    eliminarArreglo();

    this->longitud = otro.longitud;
    this->elementos = new int[otro.longitud];

    for (int i = 0; i < otro.longitud; i++)
    {
        this->elementos[i] = otro.elementos[i];
    }

    return *this;
}

// Operador []: retorna el número entero correpondiente al índice dado como parámetro.
int Compras::operator[](const int indice)
{
    return elementos[indice];
}

// Operador ==: determina si dos objetos Compras tienen los mismos elementos en el mismo orden.
bool Compras::operator==(const Compras &otroArreglo)
{
    if (this->longitud != otroArreglo.longitud)
    {
        return false;
    }

    else
    {
        for (int i = 0; i < this->longitud; i++)
        {
            if (this->elementos[i] != otroArreglo.elementos[i])
            {
                return false;
            }
        }

        return true;
    }
}

// Operador !=: determina si los elementos de dos objetos Compras son distintos.
bool Compras::operator!=(const Compras &otroArreglo)
{
    return !(*this == otroArreglo);
}

// Método que retorna el objeto Compras en forma de string.
std::string Compras::arregloToString()
{
    std::string str = "";

    str += "{ ";

    for (int i = 0; i < longitud; i++)
    {
        str += std::to_string(elementos[i]);

        if (i != longitud - 1)
        {
            str += ", ";
        }
    }

    str += " }";

    return str;
}

// Método que imprime el objeto Compras a la consola.
void Compras::printArreglo()
{
    std::cout << arregloToString();
}

// Método que libera la memoria donde se había alojado el arreglo de números enteros que representó los productos.
void Compras::eliminarArreglo()
{
    longitud = 0;
    delete[] elementos;
}

// Método destructor.
Compras::~Compras()
{
    eliminarArreglo();
}

// Método que indica el número de productos únicos que posee el arreglo (elementos sin repetir).
// Para que este método funcione adecuadamente, es necesario que el arreglo esté ordenado de
// menor a mayor o viceversa. Se puede llamar al método minToMax() o maxToMin() para ello.
int Compras::elementosUnicos()
{
    int elementoPrevio = elementos[0];
    int contador = 1;

    if (longitud == 0)
    {
        return 0;
    }

    else
    {
        for (int i = 1; i < longitud; i++)
        {
            if (elementos[i] != elementoPrevio)
            {
                contador++;
            }

            elementoPrevio = elementos[i];
        }
    }

    return contador;
}

// Método que disminuye el tamaño del arreglo para que contengo solamente los elementos sin repetir.
void Compras::reducir()
{
    int iElementosUnicos = elementosUnicos();

    if (iElementosUnicos == longitud)
    {
        return;
    }

    else
    {
        int *nuevoArreglo = new int[iElementosUnicos];
        nuevoArreglo[0] = elementos[0];
        int indice = 1;
        int elementoPrevio = elementos[0];

        for (int i = 1; i < longitud; i++)
        {
            if (elementos[i] != elementoPrevio)
            {
                nuevoArreglo[indice] = elementos[i];
                indice++;
            }

            elementoPrevio = elementos[i];
        }

        delete[] elementos;

        longitud = iElementosUnicos;
        elementos = nuevoArreglo;
    }
}

// Método que determina la cantidad de números presentes dentro de un string, al contar las comas que separan los números.
// Para que funciones adecuadamente, es necesario que el string esté formateado correctamente con la función formatearString().
int Compras::cantidadDeNumerosEnString(std::string numeros)
{
    int contador = 1;

    for (int i = 0; i < (int)numeros.size(); i++)
    {
        if (numeros[i] == ',')
        {
            contador++;
        }
    }

    return contador;
}

// Método que acepta un string de números separados por comas y retorna un arreglo que comprende dichos números.
// Para que funciones adecuadamente, es necesario que el string esté formateado correctamente con la función formatearString().
int *Compras::stringToArreglo(std::string &numeros)
{
    int iNumeros = cantidadDeNumerosEnString(numeros);

    if (iNumeros == 0)
        return nullptr;

    else
    {
        int *arreglo = new int[iNumeros];
        int inicioDeNumero = 0;
        int indice = 0;
        int i;

        for (i = 0; i < (int)numeros.size(); i++)
        {
            if (numeros[i] == ',')
            {
                arreglo[indice] = std::stoi(std::string(numeros, inicioDeNumero, i - inicioDeNumero));
                inicioDeNumero = i + 1;
                indice++;
            }
        }

        arreglo[indice] = std::stoi(std::string(numeros, inicioDeNumero, i - inicioDeNumero));

        return arreglo;
    }
}
