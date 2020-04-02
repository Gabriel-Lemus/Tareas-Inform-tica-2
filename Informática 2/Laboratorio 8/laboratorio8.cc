// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Programa que acepta una lista de vectores 3d y encuentra la distancia entre ellos.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Función que divide un string en elementos separados por comas y almacena dichos elementos en un vector de strings.
std::vector<std::string> separarString(const std::string &str)
{
    std::vector<std::string> vString;
    int indiceAnterior = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            vString.push_back(std::string(str, indiceAnterior, i - indiceAnterior));
            indiceAnterior = i + 1;
        }
    }

    vString.push_back(std::string(str, indiceAnterior, str.length() - indiceAnterior));

    return vString;
}

// Ejercicio #1 ====================================================================================================
// Función que convierte un string a un float.
float parseFloat(std::string sFloat)
{
    return std::stof(sFloat);
}

// Ejercicio #2 ====================================================================================================
class Vector3d
{
public:
    Vector3d(std::string sComponentes)
    {
        std::vector<std::string> componentes = separarString(sComponentes);

        x = parseFloat(componentes[0]);
        y = parseFloat(componentes[1]);
        z = parseFloat(componentes[2]);
    }

    // Ejercicio #3 ================================================================================================
    // Función que calcula la distancia entre dos vectores tridimensionales.
    float distancia(Vector3d otroVector)
    {
        return sqrt(pow(x - otroVector.x, 2) + pow(y - otroVector.y, 2) + pow(z - otroVector.z, 2));
    }

    void setX(float x)
    {
        this->x = x;
    }

    void setY(float y)
    {
        this->y = y;
    }

    void setZ(float z)
    {
        this->z = z;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

    float getZ()
    {
        return z;
    }

private:
    float x;
    float y;
    float z;
};

// Función que determina la suma entre las distancias de un vector de vectores tridimensionales.
float sumarDistancias(std::vector<Vector3d> vectores)
{
    float suma = 0;

    for (int i = 0; i < vectores.size() - 1; i++)
    {
        suma += vectores[i].distancia(vectores[i + 1]);
    }

    return suma;
}

// Ejercicio #4 ====================================================================================================
int main()
{
    std::vector<Vector3d> vectores;
    std::string input;
    float suma;

    std::cout << "\nA continuación, podrá ingresar la cantidad de vectores 3D que desee, en un formato \"x,y,z\"." << std::endl;
    std::cout << "Cuando desee finalizar la ejecución del programa, solamente presione Enter." << std::endl << std::endl;

    while (true)
    {
        std::cout << "Ingrese un nuevo vector: ";
        getline(std::cin, input);

        if (input == "\0")
        {
            break;
        }

        else
        {
            vectores.push_back(Vector3d(input));
        }
    }

    if (vectores.empty())
    {
        suma = 0;
    }

    else
    {
        suma = sumarDistancias(vectores);
    }

    std::cout << std::endl;

    printf("La suma de las distancias es: %.2f\n\n", suma);

    return 0;
}
