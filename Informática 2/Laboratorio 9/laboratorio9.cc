// Autores: Jorge Guerrero y Gabriel Lemus.
// Descripción: Clase LinkedList.

#include <iostream>
#include <vector>

class LinkedList
{
public:
    // Constructor que no toma parámetros;
    LinkedList()
    {
        value = 0;
        rest = nullptr;
    }

    // Constructor que toma un número entero como parámetro.
    LinkedList(const int valor)
    {
        value = valor;
        rest = nullptr;
    }

    // Método para determinar la longitud de una LinkedList.
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

    // Método para determinar la longitud de una const LinkedList.
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

    // Método con propósitos de prueba.
    // Método que imprime en la consola los elementos de la LinkedList.
    void print()
    {
        LinkedList *temp = this;

        for (int i = 0; i < longitud(); i++)
        {
            printf("Elemento #%i: %i\n", i + 1, temp->value);
            temp = temp->rest;
        }
    }

    // Ejercicio #1 ====================================================================================================
    // Método que agrega un elemento al final de la LinkedList.
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

    // Ejercicio #2 ====================================================================================================
    // Método que crea un vector a partir de la LinkedList.
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

    // Ejercicio #3 ====================================================================================================
    // Método que retorna una referencia al elemento correspondiente del índice dado como parámetro.
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

    // operador[] para un const LinkedList.
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

    // Método para eliminar el miembro resto de una instancia de LinkedList.
    void borrarLista()
    {
        value = 0;
        delete rest;
    }

    // Ejercicio #4 ====================================================================================================
    // Método destructor.
    ~LinkedList()
    {
        borrarLista();
    }

    // Ejercicio #5 ====================================================================================================
    // Operador =
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

// Función main para probar la clase LinkedList.
int main()
{
    LinkedList el1(1);

    el1.push(2);
    el1.push(3);

    LinkedList el2;
    el2 = el1;

    el1.push(-22);
    el1.push(378);
    el1.push(45);

    std::cout << "Lista 1:\n";
    el1.print();

    std::cout << std::endl;
    std::cout << "Lista 2:\n";
    el2.print();

    return 0;
}
