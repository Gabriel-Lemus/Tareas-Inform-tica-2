// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con structs y clases.

#include <iostream>

struct Mapa
{
    int **posiciones;
    int ancho;
    int largo;
};

struct Vector
{
    int x;
    int y;
};

// Función con propósitos de prueba.
// Función que imprime en la consola los componentes <x, y> de un vector.
void imprimirVector(const Vector vector)
{
    printf("<%i, %i>", vector.x, vector.y);
}

// Función que suma dos vectores y retorna el resultado.
Vector sumarVectores(const Vector vector1, const Vector vector2)
{
    Vector suma;

    suma.x = vector1.x + vector2.x;
    suma.y = vector1.y + vector2.y;

    return suma;
}

// Función que determina si los componentes entre dos vectores son iguales.
bool igualdadEntreVectores(const Vector vector1, const Vector vector2)
{
    if (vector1.x == vector2.x && vector1.y == vector2.y)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// Función que convierte la instancia de vector pasada como parámetro a un arreglo bidimensional.
int *vector_A_Arreglo(Vector vector)
{
    int *posicion = (int *)malloc(sizeof(int) * 2);
    posicion[0] = vector.x;
    posicion[1] = vector.y;

    return posicion;
}

// Función que recibe como parámetros el ancho y largo de un mapa, así como la referencia a un vector.
// Si las componentes del vector están fuera del mapa, la función las reduce hasta que estén dentro del
// mismo y retorna un vector con la nueva posición válida.
void trasladarPunto(const int anchoDelMapa, const int largoDelMapa, Vector &posicion)
{
    while (posicion.x >= anchoDelMapa || posicion.y >= largoDelMapa)
    {
        if (posicion.x >= anchoDelMapa)
        {
            while (posicion.x >= anchoDelMapa)
            {
                posicion.x -= anchoDelMapa;
            }
        }

        else
        {
            while (posicion.y >= largoDelMapa)
            {
                posicion.y -= largoDelMapa;
            }
        }
    }
}

// Función que recibe como parámetros el ancho y largo de un mapa, así como dos vectores: uno que representa la
// posición inicial de un vehículo y otro que representa su velocidad.
// La función determina la cantidad de posibles coordenadas hacia las cuales podría viajar el vehículo si se
// mantiene con la velocidad constante, hasta retornar al punto inicial.
int determinarPosiblesPosiciones(const int anchoDelMapa, const int largoDelMapa, const Vector puntoInicial, const Vector velocidad)
{
    int contador = 1;
    Vector posiblePosicion = sumarVectores(puntoInicial, velocidad);

    while (!igualdadEntreVectores(posiblePosicion, puntoInicial))
    {
        posiblePosicion = sumarVectores(posiblePosicion, velocidad);
        trasladarPunto(anchoDelMapa, largoDelMapa, posiblePosicion);
        contador++;
    }

    return contador;
}

// Ejercicio #1 ====================================================================================================
class Vehiculo
{
public:
    Vehiculo(const Mapa _mapa, const Vector posicionInicial)
    {
        mapa = _mapa;
        posicion = posicionInicial;
        velocidad = Vector{0, 0};
    }

    Vehiculo(const Mapa _mapa, const Vector posicionInicial, const Vector _velocidad)
    {
        mapa = _mapa;
        posicion = posicionInicial;
        velocidad = _velocidad;
    }

    // Setters
    void setMapa(const Mapa _mapa) { mapa = _mapa; }

    void setPosicion(Vector _posicion) { posicion = _posicion; }

    void setVelocidad(Vector _velocidad) { velocidad = _velocidad; }

    // Getters
    Mapa getMapa() { return mapa; }

    Vector getPosicion() { return posicion; }

    Vector getVelocidad() { return velocidad; }

    // Ejercicio #2 ====================================================================================================
    void imprimirEstadoActual()
    {
        printf("Posicion del vehículo: <%i, %i>\nVelocidad: <%i,%i>", posicion.x, posicion.y, velocidad.x, velocidad.y);
    }

    // Ejercicio #3 ====================================================================================================
    void acelerar(Vector nuevaVelocidad)
    {
        velocidad.x += nuevaVelocidad.x;
        velocidad.y += nuevaVelocidad.y;
    }

    // Ejercicio #4 ====================================================================================================
    void validarAvance()
    {
        Vector posicionActual = posicion;
        const int posicionesPermitidas = determinarPosiblesPosiciones(mapa.ancho, mapa.largo, posicion, velocidad);

        mapa.posiciones = new int *[posicionesPermitidas];

        for (int i = 0; i < posicionesPermitidas; i++)
        {
            mapa.posiciones[i] = new int[2];
        }

        for (int i = 0; i < posicionesPermitidas; i++)
        {
            mapa.posiciones[i] = vector_A_Arreglo(posicionActual);
            posicionActual = sumarVectores(posicionActual, velocidad);
            trasladarPunto(mapa.ancho, mapa.largo, posicionActual);
        }
    }

    // Ejercicio #5 ====================================================================================================
    void avanzar(const int tiempo)
    {
        for (int i = 0; i < tiempo; i++)
        {
            posicion = sumarVectores(posicion, velocidad);
            trasladarPunto(mapa.ancho, mapa.largo, posicion);
        }
    }

private:
    Mapa mapa;
    Vector posicion;
    Vector velocidad;
};

int main()
{
    // Condiciones de prueba.
    Mapa mapa{{}, 10, 10};
    Vector inicio{2, 2};
    Vector velocidad = {1, 3};

    Vehiculo carro(mapa, inicio);
    carro.setVelocidad(velocidad);
    carro.validarAvance();

    // Posición: <7, 7>
    // Velocidad: <1, 3>
    carro.avanzar(15);
    carro.imprimirEstadoActual();

    int posiblesPosiciones = determinarPosiblesPosiciones(mapa.ancho, mapa.largo, inicio, velocidad);

    for (size_t i = 0; i < posiblesPosiciones; ++i)
    {
        delete[] carro.getMapa().posiciones[i];
    }

    delete[] carro.getMapa().posiciones;

    return 0;
}
