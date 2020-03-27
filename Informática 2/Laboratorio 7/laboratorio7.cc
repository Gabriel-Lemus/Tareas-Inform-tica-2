// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con structs y clases.

#include <iostream>

struct Mapa
{
    bool **posiciones;
    int ancho;
    int largo;
};

struct Vector
{
    int x;
    int y;
};

// Función que suma dos vectores y retorna el resultado.
Vector sumarVectores(const Vector vector1, const Vector vector2)
{
    Vector suma;

    suma.x = vector1.x + vector2.x;
    suma.y = vector1.y + vector2.y;

    return suma;
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

    // Ejercicio #5 ====================================================================================================
    void avanzar(const int tiempo)
    {
        for (int i = 0; i < tiempo; i++)
        {
            Vector posicionActual = posicion;
            Vector posiblePosicion = sumarVectores(posiblePosicion, velocidad);

            if (mapa.posiciones[posiblePosicion.x][posiblePosicion.y])
            {
                posicion = posiblePosicion;
            }

            else
            {
                for (int i = 0; i < mapa.ancho; i++)
                {
                    for (int j = 0; j < mapa.largo; j++)
                    {
                        if (mapa.posiciones[i][j])
                        {
                            posicion = Vector{i, j};
                        }
                    }
                }
            }
        }
    }

private:
    Mapa mapa;
    Vector posicion;
    Vector velocidad;
};

// Ejercicio #4 ====================================================================================================
bool validarAvance(Vehiculo vehiculo, Mapa mapa)
{
    Vector posiblePosicion = sumarVectores(posiblePosicion, vehiculo.getVelocidad());

    for (int i = 0; i < mapa.ancho; i++)
    {
        for (int j = 0; j < mapa.largo; j++)
        {
            if (mapa.posiciones[posiblePosicion.x][posiblePosicion.y])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}
