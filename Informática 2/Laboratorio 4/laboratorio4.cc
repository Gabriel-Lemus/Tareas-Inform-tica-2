// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con arreglos y punteros.

#include <iostream>

// Ejercicio #1 ---------------------------------------------------------------------------
bool divisionSegura(int numerador, int denominador, int *respuesta)
{
    if (denominador != 0)
    {
        *respuesta = numerador / denominador;
        return true;
    }

    else
    {
        return false;
    }
}

// Ejercicio #2 ---------------------------------------------------------------------------
int *valorMayor(int arreglo[], int cantidad)
{
    int *valorMaximo = &arreglo[0];

    for (int i = 0; i < cantidad; i++)
    {
        if (*valorMaximo < arreglo[i])
        {
            valorMaximo = &arreglo[i];
        }
    }

    return valorMaximo;
}

bool sumaMayor(int valores[], int cantidad, int **respuesta)
{
    if (cantidad >= 2)
    {
        respuesta[0] = valorMayor(valores, cantidad);
        int *maxTemporal = &valores[0];

        for (int i = 1; i < cantidad; i++)
        {
            if (valores[i] > *maxTemporal && &valores[i] != respuesta[0])
            {
                maxTemporal = &valores[i];
            }
        }

        respuesta[1] = maxTemporal;

        return true;
    }

    else
    {
        return false;
    }
}

// Ejercicio #3 ---------------------------------------------------------------------------
int fibonacci(int num)
{
    if (num == 0)
    {
        return 0;
    }

    else if (num == 1)
    {
        return 1;
    }

    else
    {
        return fibonacci(num - 2) + fibonacci(num - 1);
    }
}

void fibonacciN(const int n, int *valores)
{
    for (int i = 0; i < n; i++)
    {
        valores[i] = fibonacci(i);
    }
}



// Ejercicio #4 ---------------------------------------------------------------------------
void fibonacciN_Optimizada(const int n, int *valores)
{
    valores[0] = 0;
    valores[1] = 1;

    for (int i = 2; i < n; i++)
    {
        valores[i] = valores[i - 2] + valores[i - 1];
    }
}



int main()
{
    return 0;
}
