#include <iostream>

#include "mensaje.hh"
#include "Mensaje1.hh"
#include "Valor3.hh"

int main()
{

    /*
    Se utiliza el prefijo std para aceder a los
    métodos incluidos en el lenguaje.
    */
    std::printf(MENSAJE);
    std::cout << std::endl;
    std::printf("%s, %i", MENSAJE1, VALOR3);

    /*
    Retornamos el valor 0 para indicar que
    el programa se ejecuto sin errores.
    */
    return 42;
}