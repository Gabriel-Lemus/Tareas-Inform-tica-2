// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con punteros.

#include <iostream>
#include <cmath>

// Ejercicio #1 ====================================================================================================
int *copiar(int *valores, int cantidad)
{
    int *copia = (int *)malloc(sizeof(int) * cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        copia[i] = valores[i];
    }

    return copia;
}

//Ejercicio #2 ====================================================================================================
bool esPrimo(const int num)
{
    bool esPrimo = true;

    if (num <= 1)
    {
        return false;
    }

    else
    {
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                esPrimo = false;
                break;
            }
        }

        return esPrimo;
    }
}

int primosMenores(int num)
{
    int contador = 0;

    for (int i = 0; i < num; i++)
    {
        if (esPrimo(i))
        {
            contador++;
        }
    }

    return contador;
}

int *primos(const int maximo)
{
    int primosMenoresQueMax = primosMenores(maximo);

    int *resultado = (int *)malloc(sizeof(int) * primosMenoresQueMax);
    int contadorPrimos = 0;

    for (int i = 2; i < maximo; i++)
    {
        if (esPrimo(i))
        {
            resultado[contadorPrimos] = i;
            contadorPrimos++;
        }
    }

    return resultado;
}

// Ejercicio #3 ====================================================================================================
bool verificarCercania(int **vector, const int distancia)
{
    int valor1 = std::pow(vector[0][0], 2);
    int valor2 = std::pow(vector[0][1], 2);

    if (std::sqrt((valor1 + valor2)) < distancia)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int numeroDeVectoresCercanos(int **vectores, const int cantidad, const int distancia)
{
    int vectoresCercanos = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (verificarCercania(&vectores[i], distancia))
        {
            vectoresCercanos++;
        }
    }

    return vectoresCercanos;
}

int **vectoresCercanos(int **vectores, const int cantidad, const int distancia)
{
    int numDeVectoresCercanos = numeroDeVectoresCercanos(vectores, cantidad, distancia);

    int **vectoresCercanos = new int *[numDeVectoresCercanos];
    for (int i = 0; i < numDeVectoresCercanos; ++i)
    {
        vectoresCercanos[i] = new int[2];
    }

    int indiceVector = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (verificarCercania(&vectores[i], distancia))
        {
            vectoresCercanos[indiceVector] = vectores[i];
            indiceVector++;
        }
    }

    return vectoresCercanos;
}

int main()
{
    return 0;
}
