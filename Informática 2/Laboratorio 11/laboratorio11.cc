// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Trabajando con clases y métodos virtuales.

#include <iostream>
#include <vector>

// Clase LinkedList
class LinkedList
{
public:
    LinkedList()
    {
        value = 0;
        rest = nullptr;
    }

    LinkedList(const int valor)
    {
        value = valor;
        rest = nullptr;
    }

    int longitud()
    {
        int contador = 0;
        LinkedList *temp = this;

        while (temp != nullptr)
        {
            contador++;
            temp = temp->rest;
        }

        return contador;
    }

    int longitud() const
    {
        int contador = 1;
        LinkedList *temp = this->rest;

        while (temp != nullptr)
        {
            contador++;
            temp = temp->rest;
        }

        return contador;
    }

    void print()
    {
        LinkedList *temp = this;

        for (int i = 0; i < longitud(); i++)
        {
            printf("Elemento #%i: %i\n", i + 1, temp->value);
            temp = temp->rest;
        }
    }

    void push(int valor)
    {
        LinkedList *nuevoElemento = new LinkedList(valor);

        LinkedList *temp = this;

        while (temp->rest != nullptr)
        {
            temp = temp->rest;
        }

        temp->rest = nuevoElemento;
    }

    std::vector<int> toVector()
    {
        std::vector<int> listaVector;
        LinkedList *temp = this;

        for (int i = 0; i < longitud(); i++)
        {
            listaVector.push_back(temp->value);
            temp = temp->rest;
        }

        return listaVector;
    }

    int &operator[](const int indice)
    {
        int index = indice;
        LinkedList *temp = this;

        while (index != 0)
        {
            index--;
            temp = temp->rest;
        }

        return temp->value;
    }

    int operator[](const int indice) const
    {
        if (indice == 0)
        {
            return value;
        }

        else
        {
            int index = indice;
            LinkedList *temp = this->rest;

            while (index != 1)
            {
                index--;
                temp = temp->rest;
            }

            return temp->value;
        }
    }

    void borrarLista()
    {
        value = 0;
        delete rest;
    }

    ~LinkedList()
    {
        borrarLista();
    }

    LinkedList &operator=(const LinkedList &otra)
    {
        this->borrarLista();

        int size = otra.longitud();
        this->value = otra[0];

        for (int i = 1; i < size; i++)
        {
            this->push(otra[i]);
        }

        return *this;
    }

private:
    int value;
    LinkedList *rest;
};

// Ejercicio #1 - Clase Coleccion ====================================================================================================
template <typename TContenedor>
class Coleccion
{
public:
    // Constructores
    Coleccion() : longitud(0) {}

    Coleccion(std::vector<TContenedor> contenedor) : longitud(1), contenedores(contenedores.push_back(contenedor)) {}

    // Getters

    int &getLongitud()
    {
        return longitud;
    }

    std::vector<TContenedor> &getContenedores()
    {
        return contenedores;
    }

    // Ejercicio #1 - Métodos virtuales de la clase Coleccion ====================================================================================================
    virtual int getNumeroDeElementos() = 0;

    virtual void agregarElemento(const TContenedor contenedor) = 0;

    virtual void setElemento(const int indice, const TContenedor contenedor) = 0;

    virtual TContenedor &operator[](const int indice) = 0;

protected:
    std::vector<TContenedor> contenedores;

private:
    int longitud;
};

// Ejercicio #2 - Clase ColeccionVector ====================================================================================================
template <typename TContenedor>
class ColeccionVector : public Coleccion<std::vector<int>>
{
public:
    // Constructores
    ColeccionVector() : Coleccion(){};

    ColeccionVector(std::vector<int> vNumeros) : Coleccion(vNumeros){};

    // Métodos
    int getNumeroDeElementos() override
    {
        return getLongitud();
    }

    void agregarElemento(const TContenedor contenedor) override
    {
        contenedores.push_back(contenedor);
        getLongitud() += 1;
    }

    void setElemento(const int indice, const TContenedor contenedor) override
    {
        getContenedores()[indice] = contenedor;
    }

    TContenedor &operator[](const int indice) override
    {
        return getContenedores()[indice];
    }
};

// Ejercicio #3 - Clase ColeccionLinkedList ====================================================================================================
template <typename TContenedor>
class ColeccionLinkedList : public Coleccion<std::vector<LinkedList>>
{
    // Constructores
    ColeccionLinkedList() : Coleccion(){};

    ColeccionLinkedList(std::vector<LinkedList> lista) : Coleccion(lista){};

    // Métodos
    int getNumeroDeElementos() override
    {
        return getLongitud();
    }

    void agregarElemento(const TContenedor contenedor) override
    {
        contenedores.push_back(contenedor);
        getLongitud() += 1;
    }

    void setElemento(const int indice, const TContenedor contenedor) override
    {
        getContenedores()[indice] = contenedor;
    }

    TContenedor &operator[](const int indice) override
    {
        return getContenedores()[indice];
    }
};

// Ejercicio #4 ====================================================================================================
// Función que toma un objeto Colección ordena sus elementos de menor a mayor.
template <typename TContenedor>
void ordenar(Coleccion<std::vector<TContenedor>> &valores)
{
    for (int i = 0; i < (int)valores.getLongitud(); i++)
    {
        for (int j = i + 1; j < (int)valores.getLongitud(); j++)
        {
            if (valores[i].size() > valores[j].size())
            {
                std::vector<TContenedor> temporal{valores[i]};
                valores[i] = valores[j];
                valores[j] = temporal;
            }
        }
    }
}

// Función Main para comprobar el funcionamiento adecuado de las clases.
int main()
{
    std::vector<int> vNums1{1, 2, 3, 4, 5};
    std::vector<int> vNums2{13, 23, 33};
    std::vector<int> vNums3{-58};

    ColeccionVector<std::vector<int>> vCol;
    vCol.agregarElemento(vNums1);
    vCol.agregarElemento(vNums2);
    vCol.agregarElemento(vNums3);

    ordenar(vCol);

    for (int i = 0; i < (int)vCol.getLongitud(); i++)
    {
        std::cout << "Vector #" << i + 1 << ": " << std::endl;

        for (int j = 0; j < (int)vCol[i].size(); j++)
        {
            std::cout << "Elemento #" << j + 1 << ": " << vCol[i][j] << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
