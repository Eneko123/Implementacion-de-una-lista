#pragma once
class List
{
public:
	List();
	~List();

	void init(int initialCapacity); // inicializa la lista reservando memoria inicial
	void freeList(); // libera la memoria utilizada y deja el puntero en nullptr
	void ensureCapacity(); // si la lista esta llena, duplica la capacidad del array
	void add(int value); // aniade un elemento al final de la lista
	void insertAt(int index, int value); // inserta un elemento en una posicion concreta desplazando los demas
	void removeAt(int index); // elimina un elemento desplazando el resto hacia la izquierda
	int indexOf(int value); // devuelve el indice de un elemento o -1 si no existe
	void printList(); // muestra el contenido de la lista junto con size y capacity

	void SetV(int* newV) { v = newV; };
	void SetSize(int newSize) { size = newSize; };
	void SetCapacity(int newCapacity) { capacity = newCapacity; };

	int* GetV() { return v; };
	int GetSize() { return size; };
	int GetCapacity() { return capacity; }

private:
	int* v; // Array dinamico donde se almacenan los elementos
	int size; // Numero de elementos actualmente almacenados
	int capacity; //Capacidad total del array reservado
};

