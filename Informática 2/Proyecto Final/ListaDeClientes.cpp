#include "ListaDeClientes.h"

// Funciones auxiliares a la clase ListaDeClientes

// Función que determina el número de elementos comunes entre dos objetos Compras dados.
// Para que funcione adecuadamente, es necesario que las se encuentren Compras ordenadas.
int numeroDeElementosComunes(Compras &compras1, Compras &compras2)
{
    int productosComunes = 0;

    for (int i = 0; i < compras1.getLongitud(); i++)
    {
        for (int j = 0; j < compras2.getLongitud(); j++)
        {
            if (compras1[i] == compras2[j])
            {
                productosComunes++;
            }
        }
    }

    return productosComunes;
}

// Función que retorna una referencia a un objeto Compras con los elementos comunes entre ambas Compras dadas como parámentros.
// Para que funcione adecuadamente, es necesario que las se encuentren Compras ordenadas.
Compras *interseccion(Compras &compras1, Compras &compras2)
{
    int elementos = numeroDeElementosComunes(compras1, compras2);
    int *iInterseccion = new int[elementos];
    int indice = 0;

    for (int i = 0; i < compras1.getLongitud(); i++)
    {
        for (int j = 0; j < compras2.getLongitud(); j++)
        {
            if (compras1[i] == compras2[j])
            {
                iInterseccion[indice] = compras1[i];
                indice++;
            }
        }
    }

    Compras *cInterseccion = new Compras;
    cInterseccion[0] = Compras(elementos, iInterseccion);

    delete[] iInterseccion;

    return cInterseccion;
}

// Función para determinar si entre dos objetos Compras dados, existen por lo menos 2 elementos en común.
bool existenElementosComunes(Compras &compras1, Compras &compras2)
{
    int elementosEnConjunto = 0;

    for (int i = 0; i < compras1.getLongitud(); i++)
    {
        for (int j = 0; j < compras2.getLongitud(); j++)
        {
            if (compras1[i] == compras2[j])
            {
                elementosEnConjunto++;
                break;
            }
        }
    }

    if (elementosEnConjunto >= 2)
        return true;

    else
        return false;
}

// Función que toma un objeto BestSellers y un arreglo de BestSellers, así como la longitud del arreglo.
// Determina si el primer parámetro aparece dentro del arreglo de BestSellers.
bool apareceDentro(BestSellers &bestSeller, BestSellers *&grupoDeBestSellers, int &longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        if (*(bestSeller.getProductos()) == *(grupoDeBestSellers[i].getProductos()))
        {
            return true;
        }
    }

    return false;
}

// Función que determina si un cliente (representado como segundo parámetro) adquirió los BestSellers dado como primer parámetro.
// En otras palabras, esta función determina si los elementos del objeto BestSellers aparecen dentro de los elementos del objeto Compras.
bool apareceDentroDeLasCompras(BestSellers &bestSeller, Compras &compras)
{
    if (bestSeller.getProductos()->getLongitud() > compras.getLongitud())
    {
        return false;
    }

    else
    {
        int elementosComprados = 0;

        for (int i = 0; i < compras.getLongitud(); i++)
        {
            for (int j = 0; j < bestSeller.getProductos()->getLongitud(); j++)
            {
                if ((*(bestSeller.getProductos()))[j] == compras[i])
                {
                    elementosComprados++;
                }
            }
        }

        if (elementosComprados == bestSeller.getProductos()->getLongitud())
        {
            return true;
        }

        else
        {
            return false;
        }
    }
}

// Clase ListaDeClientes ====================================================================================================

// Constructores

// Constructor que no toma parámetros.
ListaDeClientes::ListaDeClientes()
{
    numeroDeClientes = 0;
    compras = nullptr;
    numeroDeBestSellers = 0;
    bestSellers = nullptr;
}

// Constructor que toma un entero que representa el número de clientes y un arreglo de objetos Compras que representan los productos adquiridos.
ListaDeClientes::ListaDeClientes(int numeroDeClientes, Compras *&compras)
{
    this->numeroDeClientes = numeroDeClientes;
    this->numeroDeBestSellers = 0;
    this->compras = new Compras[numeroDeClientes];
    this->bestSellers = nullptr;

    for (int i = 0; i < numeroDeClientes; i++)
    {
        this->compras[i] = compras[i];
    }

    encontrarBestSellers();
}

// Constructor que toma un entero que representa el número de clientes y un arreglo de objetos Compras que representan los productos adquiridos,
// así como un entero que representa el número de BestSellers y un arreglo de BestSellers.
ListaDeClientes::ListaDeClientes(int numeroDeClientes, Compras *&compras, int numeroDeBestSellers, BestSellers *&bestSellers)
{
    this->numeroDeClientes = numeroDeClientes;
    this->numeroDeBestSellers = numeroDeBestSellers;
    this->compras = new Compras[numeroDeClientes];
    this->bestSellers = new BestSellers[numeroDeBestSellers];

    for (int i = 0; i < numeroDeClientes; i++)
    {
        this->compras[i] = compras[i];
    }

    for (int i = 0; i < numeroDeBestSellers; i++)
    {
        this->bestSellers[i] = bestSellers[i];
    }
}

// Setters

void ListaDeClientes::setCompras(int numeroDeClientes, Compras *&compras)
{
    delete[] this->compras;

    this->numeroDeClientes = numeroDeClientes;
    this->compras = new Compras[numeroDeClientes];

    for (int i = 0; i < numeroDeClientes; i++)
    {
        this->compras[i] = compras[i];
    }
}

void ListaDeClientes::setBestSellers(int numeroDeBestSellers, BestSellers *&bestSellers)
{
    delete[] this->bestSellers;

    this->numeroDeBestSellers = numeroDeBestSellers;
    this->bestSellers = new BestSellers[numeroDeBestSellers];

    for (int i = 0; i < numeroDeBestSellers; i++)
    {
        this->bestSellers[i] = bestSellers[i];
    }
}

// Getters

int ListaDeClientes::getNumeroDeClientes()
{
    return numeroDeClientes;
}

Compras *ListaDeClientes::getCompras()
{
    return compras;
}

int ListaDeClientes::getNumeroDeBestSellers()
{
    return numeroDeBestSellers;
}

BestSellers *ListaDeClientes::getBestSellers()
{
    return bestSellers;
}

// Otros métodos

// Método que determina cuáles son los bestsellers (productos más populares entre los clientes) entre el grupo de clientes,
// así como el número de veces que cada conjunto de productos fue adquirido.
void ListaDeClientes::encontrarBestSellers()
{
    if (numeroDeClientes <= 1)
    {
        return;
    }

    else
    {
        productosComunes();
        reducirBestSellers();
        contarRepeticiones();
        ordenarBestSellers();
        maxToMinBestSellers();
    }
}

// Método que convierte un objeto ListaDeClientes a un string.
std::string ListaDeClientes::listaDeClientesToString()
{
    std::string str = "";

    str += "Productos comprados:\n{\n";

    if (numeroDeClientes == 0)
    {
        str += "\tNo se realizó ninguna compra.";
    }

    else
    {
        for (int i = 0; i < numeroDeClientes; i++)
        {
            str += "\t";
            str += "Cliente #";
            str += std::to_string(i + 1);
            str += ": ";
            str += compras[i].arregloToString();

            if (i != numeroDeClientes - 1)
            {
                str += "\n";
            }
        }
    }

    str += "\n}\n\n";

    if (numeroDeBestSellers == 0)
    {
        str += "No hubo productos comprados en conjunto entre los clientes.";
    }

    else
    {
        str += "Productos comprados comunmente:\n{\n";

        for (int i = 0; i < numeroDeBestSellers; i++)
        {
            str += "\t";
            str += "Conjunto de productos #";
            str += std::to_string(i + 1);
            str += ": ";
            str += bestSellers[i].getProductos()->arregloToString();
            str += " | Fue comprado en conjunto: ";
            str += std::to_string(bestSellers[i].getRepeticiones());
            str += " veces.";

            if (i != numeroDeBestSellers - 1)
            {
                str += "\n";
            }
        }

        str += "\n}";
    }

    return str;
}

// Método que imprime la ListaDeClientes a la consola.
void ListaDeClientes::printListaDeClientes()
{
    std::cout << listaDeClientesToString();
}

// Método que libera la memoria donde se había alojado el arreglo de Compras que representó productos adquiridos por los clientes,
// así como el arreglo de BestSellers que representó los productos más populares comprados en conjunto entre los clientes.
void ListaDeClientes::eliminarListaDeClientes()
{
    numeroDeClientes = 0;
    delete[] compras;
    numeroDeBestSellers = 0;
    delete[] bestSellers;
}

// Método destructor.
ListaDeClientes::~ListaDeClientes()
{
    eliminarListaDeClientes();
}

// Método que determina el número BestSellers presente dentro de los productos adquiridos por los clientes.
// Este método no discrimina los bestsellers repetidos, por lo que el número obtenido por este método no será el criterio final.
int ListaDeClientes::gruposDeBestSellers()
{
    int contador = 0;

    for (int i = 0; i < numeroDeClientes; i++)
    {
        for (int j = i + 1; j < numeroDeClientes; j++)
        {
            if (existenElementosComunes(compras[i], compras[j]))
            {
                contador++;
            }
        }
    }

    return contador;
}

// Método que puebla el miembro bestSellers con un arreglo que contiene los BestSellers del grupo de clientes. Este arreglo de BestSellers
// no está ordenado por el número de elementos y éstos no cuentan con el número de veces que cada conjunto de productos fue adquirido (miembro "repeticiones").
void ListaDeClientes::productosComunes()
{
    if (numeroDeClientes <= 1)
        return;

    else
    {
        int gruposDeElementosComunes = gruposDeBestSellers();

        if (gruposDeElementosComunes == 0)
            return;

        else
        {
            numeroDeBestSellers = gruposDeElementosComunes;
            bestSellers = new BestSellers[numeroDeBestSellers];
            int indiceBestSellers = 0;

            for (int i = 0; i < numeroDeClientes; i++)
            {
                for (int j = i + 1; j < numeroDeClientes; j++)
                {
                    if (existenElementosComunes(compras[i], compras[j]))
                    {
                        int elementos = numeroDeElementosComunes(compras[i], compras[j]);
                        int *iInterseccion = new int[elementos];
                        int indice = 0;

                        for (int k = 0; k < compras[i].getLongitud(); k++)
                        {
                            for (int l = 0; l < compras[j].getLongitud(); l++)
                            {
                                if (compras[i][k] == compras[j][l])
                                {
                                    iInterseccion[indice] = compras[i][k];
                                    indice++;
                                }
                            }
                        }

                        Compras temp(elementos, iInterseccion);
                        bestSellers[indiceBestSellers] = BestSellers(temp);
                        indiceBestSellers++;

                        delete[] iInterseccion;
                    }
                }
            }
        }
    }
}

// Método que elimina los BestSellers repetidos del arreglo. No obstante, éste método no determina cuántas veces fue adquirido cada conjunto de productos.
// Para ello, se llama al método contarRepeticiones().
void ListaDeClientes::reducirBestSellers()
{
    if (numeroDeBestSellers == 0)
    {
        return;
    }

    else
    {
        // Se emplea un arreglo temporal de BestSellers donde se irán almacenando los BestSellers únicos entre el grupo de clientes.
        // En caso exista más de un bestseller, éste arreglo aumentará en tamaño.
        BestSellers *bestSellersReducidos = new BestSellers[1];
        *bestSellersReducidos = bestSellers[0];

        int bestSellersUnicos = 1;
        BestSellers anterior;
        anterior = bestSellers[0];

        for (int i = 1; i < numeroDeBestSellers; i++)
        {
            // Esta condicional determina si el bestseller actual no es igual al anterior y si no aparece dentro del arreglo de BestSellers únicos dentro del grupo de clientes.
            if ((*(bestSellers[i].getProductos()) != *(anterior.getProductos())) && !apareceDentro(bestSellers[i], bestSellersReducidos, bestSellersUnicos))
            {
                bestSellersUnicos++;
                BestSellers *temp = new BestSellers[bestSellersUnicos];

                for (int j = 0; j < bestSellersUnicos; j++)
                {
                    if (j != bestSellersUnicos - 1)
                        temp[j] = bestSellersReducidos[j];

                    else
                        temp[j] = bestSellers[i];
                }

                delete[] bestSellersReducidos;
                bestSellersReducidos = new BestSellers[bestSellersUnicos];

                for (int j = 0; j < bestSellersUnicos; j++)
                {
                    bestSellersReducidos[j] = temp[j];
                }

                delete[] temp;
            }

            anterior = bestSellers[i];
        }

        delete[] bestSellers;

        numeroDeBestSellers = bestSellersUnicos;
        bestSellers = bestSellersReducidos;
    }
}

// Método que itera por el arreglo de BestSellers y determina cúantas veces fue adquirido cada conjunto de productos.
void ListaDeClientes::contarRepeticiones()
{
    int iRepeticiones = 0;
    int indice = 0;

    for (int i = 0; i < numeroDeBestSellers; i++)
    {
        for (int j = 0; j < numeroDeClientes; j++)
        {
            if (apareceDentroDeLasCompras(bestSellers[i], compras[j]))
            {
                iRepeticiones++;
            }
        }

        bestSellers[indice].setRepeticiones(iRepeticiones);
        iRepeticiones = 0;
        indice++;
    }
}

// Método que ordena de mayor a menor, el arreglo de BestSellers, según las repeticiones de los conjuntos de productos.
void ListaDeClientes::ordenarBestSellers()
{
    for (int i = 0; i < numeroDeBestSellers; i++)
    {
        for (int j = i + 1; j < numeroDeBestSellers; j++)
        {
            if (bestSellers[i].getRepeticiones() < bestSellers[j].getRepeticiones())
            {
                BestSellers temp;
                temp = bestSellers[i];
                bestSellers[i] = bestSellers[j];
                bestSellers[j] = temp;
            }
        }
    }
}

// Método que ordena el arreglo de BestSellers de mayor a menor, según la cantidad de productos de cada conjunto de productos.
void ListaDeClientes::maxToMinBestSellers()
{
    for (int i = 0; i < numeroDeBestSellers; i++)
    {
        for (int j = i + 1; j < numeroDeBestSellers; j++)
        {
            if (bestSellers[i].getProductos()->getLongitud() < bestSellers[j].getProductos()->getLongitud())
            {
                BestSellers temp;
                temp = bestSellers[i];
                bestSellers[i] = bestSellers[j];
                bestSellers[j] = temp;
            }
        }
    }
}
