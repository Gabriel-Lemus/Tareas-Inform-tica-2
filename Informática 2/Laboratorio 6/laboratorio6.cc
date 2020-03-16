#include <iostream>

struct Lista
{
	int valor;
	Lista *resto;
};

// Ejercicio #1
Lista *crear(const int *valores, const int cantidad)
{
	Lista *lista = (Lista *)malloc(sizeof(Lista) * cantidad);

	if (cantidad == 0)
	{
		return nullptr;
	}

	else
	{
		for (int i = cantidad - 1; i >= 0; i--)
		{
			int j = i + 1;

			lista[i].valor = valores[i];

			if (i == cantidad - 1)
			{
				lista[i].resto = nullptr;
			}

			else
			{
				lista[i].resto = &lista[j];
			}
		}

		return lista;
	}
}

// Ejercicio #2
void eliminar(Lista *valores)
{
	Lista *listaTemporal = valores->resto;

	while (listaTemporal != nullptr)
	{
		valores = listaTemporal->resto;
		delete listaTemporal;
		listaTemporal = valores;
	}
}

// Ejercicio #3
void unir(Lista *primera, Lista *segunda)
{
	while (primera->resto != nullptr)
	{
		primera = primera->resto;
	}

	primera->resto = segunda;
}

// Ejercicio #4
int longitud(const Lista *lista)
{
	if (lista->resto == nullptr)
	{
		return 0;
	}
	else
	{
		int contador = 1;

		while (lista->resto != nullptr)
		{
			contador++;
			lista = lista->resto;
		}

		return contador;
	}
}

// Ejercicio #5
bool lookup(const Lista *valores, const int indice, int &resultado)
{
	int rango = longitud(valores);
	int index = indice;

	if (indice >= 0 && indice <= rango)
	{
		while (index > 0)
		{
			index--;
			valores = valores->resto;
		}

		resultado = valores->valor;

		return true;
	}
	else
	{
		return false;
	}
}

// Ejercicio #6
struct Triangulo
{
	float vertice1[2];
	float vertice2[2];
	float vertice3[2];
};

struct ListaTriangulos
{
	Triangulo triangulo;
	ListaTriangulos *siguienteTriangulo;
};

// Ejercicio #7
float area(const Triangulo &triangulo)
{
	float x1, x2, x3, y1, y2, y3;
	x1 = triangulo.vertice1[0];
	y1 = triangulo.vertice1[1];
	x2 = triangulo.vertice2[0];
	y2 = triangulo.vertice2[1];
	x3 = triangulo.vertice3[0];
	y3 = triangulo.vertice3[1];

	/*
	    Área de un triángulo, dadas las coordenadas de sus vértices:

	    		| x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
	    		|-----------------------------------------|
	    		|                     2                   |

	*/

	float area = abs((((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2));

	return area;
}

// Ejercicio #8
int longitudListaDeTriangulos(const ListaTriangulos *triangulos)
{
	if (triangulos->siguienteTriangulo == nullptr)
	{
		return 0;
	}
	else
	{
		int contador = 1;

		while (triangulos->siguienteTriangulo != nullptr)
		{
			contador++;
			triangulos = triangulos->siguienteTriangulo;
		}

		return contador;
	}
}

float areaPromedio(const ListaTriangulos *triangulos)
{
	float areaP = 0;
	int numDeTriangulos = longitudListaDeTriangulos(triangulos);

	while (triangulos->siguienteTriangulo != nullptr)
	{
		areaP += area(triangulos->triangulo);
		triangulos = triangulos->siguienteTriangulo;
	}

	areaP += area(triangulos->triangulo);
	areaP /= numDeTriangulos;

	return areaP;
}

int main()
{
	return 0;
}
