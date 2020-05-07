# Informática II - Proyecto Final: Supermercado  

## Autores: Jorge Guerrero y Gabriel Lemus  

**Descripción**: El código adjunto es un programa escrito en C++ el cual busca determinar los productos que los clientes compran frecuentemente en conjunto, sabiendo las compras que han realizado dichos clientes.  

****

**Distribución del código:** El código está dividido en cuatro partes: 3 archivos de clases, con sus respectivos headers y el archivo principal (proyecto.cpp), el cual contiene la función main, así como otras funciones auxiliares.  

***Clase Compras:*** La clase Compras representa los productos que han comprado los clientes. Esta clase posee dos miembros: un puntero de números enteros ("*elementos*") que representa los productos comprados por un solo cliente y un número entero ("*longitud*") que representa la cantidad de productos comprados por el cliente. Entre los métodos más importantes de esta clase están minToMax() y maxToMin(), los cuales ordenan los productos de forma ascendente y descendente, respectivamente. Además, el método reducir() se asegura que no haya elementos repetidos, para que la clase BestSellers pueda analizar fácilmente los productos comprados comúnmente entre dos clientes dados.  

***Clase BestSellers:*** Representa los productos comprados frecuentemente en conjunto (los productos más populares - *bestsellers*). Esta clase contiene dos miembros: un puntero a un objeto de la Clase Compras ("*productos*"), el cual representa un conjunto de productos populares; así como un entero ("*repeticiones*"), el que indica cuántas veces fue adquirido este grupo de productos entre un grupo de clientes dados. Esta clase únicamente tiene el propósito de almacenar estos datos. Por lo que, para determinar cuáles son los *bestsellers* y cuántas veces fueron adquiridos, se recurre a la clase *ListaDeClientes*.  

***Clase ListaDeClientes:*** Esta clase representa a un grupo de clientes. Posee cuatro miembros: un entero que representa el número de clientes del grupo ("*numeroDeClientes*"), un arreglo de objetos de la clase Compras ("*compras*") que simboliza los productos comprados por los clientes; un entero ("*numeroDeBestSellers*"), que indica la cantidad de conjuntos de productos más populares comprados en grupo - *bestsellers*; y un arreglo de objetos de la clase BestSellers ("*bestSellers*"), que representa los productos que fueron conseguidos con mayor frecuencia dentro del grupo de clientes analizado. Esta clase posee varios métodos que le sirven para determinar los *bestsellers* al conocer los productos que han adquirido los clientes.  
