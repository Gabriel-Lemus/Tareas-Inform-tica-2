#include <iostream>
#include <cmath>


// Ejercicio #1
void imprimirBinario(int i)
{
    int contador = 31;

    while (contador >= 0)
    {
        // Esta línea mueve el bit más significativo de "i", haciéndolo el menos significativo, 
        // lo compara contra "1" y lo muestra en la consola.
        printf("%i", ((i >> contador) & 1));
        contador--;
    }
}


// Ejercicio #2
bool existe(char valor, long numero)
{
    while (numero > 0)
    {
        if ((valor & numero) == valor)
        {
            return true;
        }
        else
        {
            numero >>= 1;
        }
    }

    return false;
}


// Ejercicio #3
short conteo(long numero)
{
    short contador = 0;

    while (numero > 0)
    {
        if ((numero & 1) == 1) // Si el bit se encuentra activado, el contador incrementa.
        {
            contador++;
            numero >>= 1;
        }
        else
        {
            numero >>= 1;
        }
    }

    return contador;
}


// Ejercicio #4
int andOr(int valor1, int valor2)
{
    int contador = 1;
    int exponente = 0;
    int nuevo = 0;
    int bit1 = valor1 & 1;
    int bit2 = valor2 & 1;

    while (valor1 > 0 && valor2 > 0)
    {
        // Bit impares
        if (contador % 2 != 0)
        {
            if ((bit1 | bit2) == 1)
            {
                nuevo += pow(2, exponente);
            }
        }

        // Bit pares
        else
        {
            if ((bit1 & bit2) == 1)
            {
                nuevo += pow(2, exponente);
            }
        }

        valor1 >>= 1;
        valor2 >>= 1;
        bit1 = valor1 & 1;
        bit2 = valor2 & 1;
        contador++;
        exponente++;
    }

    return nuevo;
}


// Ejercicio #5
int acumularCaracter(char caracter, int exponente)
{
    int resultado = 0;

    while (caracter > 0)
    {
        if ((caracter & 1) == 1) // Verifica si el bit está activado.
        {
            resultado += pow(2, exponente);
        }

        caracter >>= 1;
        exponente++;
    }

    return resultado;
}

int codificar(char c1, char c2, char c3, char c4)
{
    int resultado = 0;

    resultado += acumularCaracter(c1, 0);   // Agrega el primer caracter a la codificación.
    resultado += acumularCaracter(c2, 8);   // Agrega el segundo caracter a la codificación.
    resultado += acumularCaracter(c4, 24);  // Agrega el tercer caracter a la codificación.
    resultado += acumularCaracter(c3, 16);  // Agrega el cuarto caracter a la codificación.

    return resultado;
}


int main()
{
    return 0;
}
