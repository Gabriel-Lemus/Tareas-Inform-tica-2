#include <vector>

#include "Compras.h"
#include "BestSellers.h"
#include "ListaDeClientes.h"

// Función que elimina los espacios adicionales anteriores y posteriores de un string.
void trimString(std::string &str)
{
    std::size_t first = str.find_first_not_of(' ');
    std::size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
}

// Función que elimina los espacios adicionales entre las palabras que conforman un string.
void juntarPalabras(std::string &str)
{
    for (int i = 0; i < (int)str.size(); i++)
        if (str[i] == ' ')
        {
            str = str.erase(i, 1);
            i--;
        }
}

// Función que elimina cualquier caracter de un string que no sea un número, signo negativo o coma.
void eliminarCaracteresAdicionales(std::string &str)
{
    while (true)
    {
        if (str[0] == '-' || str[0] == '\0')
        {
            break;
        }

        else if (!isdigit(str[0]))
        {
            str = str.substr(1, str.size() - 1);
        }

        else
        {
            break;
        }
    }

    while (true)
    {
        if (str == "")
        {
            break;
        }

        else if (!isdigit(str[str.size() - 1]))
        {
            str = str.substr(0, str.size() - 1);
        }

        else
        {
            break;
        }
    }

    for (int i = 0; i < (int)str.size() - 1; i++)
    {
        if ((str[i] == ',' && !isdigit(str[i + 1])) || (str[i] == ',' && !isdigit(str[i + 1])) || !isdigit(str[i]))
        {
            if (str[i] == ',' || str[i] == '-')
            {
                continue;
            }

            else
            {
                str = str.erase(i, 1);
                i--;
            }
        }
    }
}

// Función que elimina las comas adicionales de un string.
void eliminarComasAdicionales(std::string &str)
{
    for (int i = 0; i < (int)str.size() - 1; i++)
    {
        if ((str[i] == ',' && str[i + 1] == ',') || (str[i] == ',' && str[i + 1] == '-' && !isdigit(str[i + 2])))
        {
            str = str.erase(i, 1);
            i--;
        }
    }
}

// Función que elimina los signos negativos adicionales de un string.
void eliminarSignosAdicionales(std::string &str)
{
    for (int i = 0; i < (int)str.size() - 1; i++)
    {
        if (str[i] == '-' && !isdigit(str[i + 1]))
        {
            str = str.erase(i, 1);
            i--;
        }

        else if (isdigit(str[i]) && str[i + 1] == '-')
        {
            str = str.erase(i + 1, 1);
            i--;
        }
    }
}

// Función que llama a trimString(), juntarPalabras(), eliminarCaracteresAdicionales(), eliminarComasAdicionales()
// y eliminarSignosAdicionales() para darle un formato adecuado al string pasado como parámetro.
void formatearString(std::string &str)
{
    trimString(str);
    juntarPalabras(str);
    eliminarCaracteresAdicionales(str);
    eliminarComasAdicionales(str);
    eliminarSignosAdicionales(str);
}

// Función para probar el funcionamiento de las clases.
void prueba()
{
    const int n = 6;
    int nums1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int nums2[4] = {2, 4, 6, 8};
    int nums3[8] = {2, 4, 6, 8, 13, 15, 17, 20};
    int nums4[3] = {13, 15, 17};
    int nums5[2] = {13, 17};
    int nums6[4] = {2, 4, 6, 8};

    Compras arr1(10, nums1);
    Compras arr2(4, nums2);
    Compras arr3(8, nums3);
    Compras arr4(3, nums4);
    Compras arr5(2, nums5);
    Compras arr6(4, nums6);

    Compras *clientes = new Compras[6];

    clientes[0] = arr1;
    clientes[1] = arr2;
    clientes[2] = arr3;
    clientes[3] = arr4;
    clientes[4] = arr5;
    clientes[5] = arr6;

    ListaDeClientes compras(n, clientes);

    compras.printListaDeClientes();

    delete[] clientes;
}

void proyecto()
{
    system("clear");

    std::vector<std::string> vProductos;
    std::string input;
    int cliente = 1;

    std::cout << "A continuación, podrá ingresar los productos adquiridos por los clientes, representados por números separados por comas." << std::endl;
    std::cout << "Cuando haya ingresado los productos del ultimo cliente, solamente presione Enter para continuar." << std::endl
              << std::endl;

    while (true)
    {
        std::cout << "Ingrese los productos del cliente #" << cliente << ": ";
        getline(std::cin, input);

        if (input == "\0")
        {
            break;
        }

        else
        {
            formatearString(input);

            if (input != "")
                vProductos.push_back(input);
        }

        cliente++;
    }

    int longitud = vProductos.size();
    Compras *clientes = new Compras[longitud];

    for (int i = 0; i < longitud; i++)
    {
        clientes[i] = Compras(vProductos[i]);
    }

    system("clear");

    ListaDeClientes compras(longitud, clientes);

    compras.printListaDeClientes();

    delete[] clientes;

    std::cout << std::endl
              << std::endl;
    std::cout << "Presione Enter para finalizar la ejecución del programa...";

    std::cin.get();
}

int main()
{
    prueba();

    // proyecto();

    return 0;
}