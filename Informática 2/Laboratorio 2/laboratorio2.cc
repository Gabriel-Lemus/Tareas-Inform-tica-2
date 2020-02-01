// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: conjunto de funciones que trabajan con números primos.

#include <iostream>

// Ejercicio #1 ==============================================================================
// Esta función se llama recursivamente a sí misma para determinar si un número es primo o no.
bool esPrimoRecAux(const int num, int contador)
{
    if (num <= 1)
    {
        return false;
    }
    else if (num == contador)
    {
        return true;
    }
    else if (num % contador == 0)
    {
        return false;
    }
    else
    {
        esPrimoRecAux(num, (contador + 1));
    }
}

// Esta función llama a esPrimoRecAux().
bool esPrimoRec(const int num)
{
    esPrimoRecAux(num, 2);
}



// Ejercicio #2 ==============================================================================
// Esta función determina si un número es primo o no, utilizando un ciclo while.
bool esPrimoCiclica(const int num)
{
    int contador = 2;

    while (contador <= num)
    {
        if (num <= 1)
        {
            return false;
        }
        else if (num == contador)
        {
            return true;
        }
        else if (num % contador == 0)
        {
            return false;
        }
        else
        {
            contador++;
        }
    }
}



// Ejercicio #3 ==============================================================================
// Esta función toma como parámetro un número "x" y se llama a sí misma recursivamente para retornar
// un número primo, de forma que existan "x - 1" números primos menores que el valor retornado.
int obtenerPrimoRecAux(int num, int contador)
{
    if (num == 1 && esPrimoRec(contador))
    {
        return contador;
    }
    else if (!(esPrimoCiclica(contador)))
    {
        obtenerPrimoRecAux(num, (contador + 1));
    }
    else
    {
        return obtenerPrimoRecAux((num - 1), (contador + 1));
    }
}

// Esta función llama a obtenerPrimoRecAux().
int obtenerPrimoRec(int num)
{
    obtenerPrimoRecAux(num, 2);
}



// Ejercicio #4 ==============================================================================
// Esta función toma como parámetro un número "x" y retorna un número primo,
// de forma que existan "x - 1" números primos menores al número retornado.
int obtenerPrimoCiclico(int num)
{
    int contador = 2;

    while (num >= 0)
    {
        if (num == 1 && esPrimoCiclica(contador))
        {
            return contador;
        }
        else if (num == 1 && !esPrimoCiclica(contador))
        {
            contador++;
        }
        else if (!esPrimoCiclica(contador))
        {
            contador++;
        }
        else
        {
            num--;
            contador++;
        }
    }
}

int main()
{

    return 0;
}
