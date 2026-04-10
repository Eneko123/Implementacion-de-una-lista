#include "List.h"

#include <iostream>

List::List()
{
	v = nullptr;
	size = 0;
	capacity = 0;
}

List::~List()
{
}

void List::init(int initialCapacity)
{
	freeList();
	capacity = initialCapacity;
	size = 0;
	v = new int[initialCapacity];
}

void List::freeList()
{
	delete[] v;
	v = nullptr;
	capacity = 0;
	size = 0;
}

void List::ensureCapacity()
{
	if (size == capacity) {
		int newCapacity = capacity * 2;
		int* newArray = new int[newCapacity]; // Pedimos bloque nuevo mas grande

		for (int i = 0; i < size; i++) {
			newArray[i] = v[i]; // Copiamos todos los datos existentes
		}

		delete[] v; // Liberamos el bloque antiguo
		v = newArray; // Actualizamos el puntero al nuevo bloque
		capacity = newCapacity; // Actualizamos la capacidad
	}
}

void List::add(int value) {
	ensureCapacity(); // Aseguramos que haya espacio
	v[size] = value; // Guardamos el valor en la siguiente posición libre
	size++; // Incrementamos el contador de elementos usados
}

void List::insertAt(int index, int value) {
	ensureCapacity();
	// Desplazamos elementos hacia la derecha para hacer hueco
	for (int i = size; i > index; i--) {
		v[i] = v[i - 1];
	}
	v[index] = value;
	size++;
}

void List::removeAt(int index) {
	// Desplazamos elementos hacia la izquierda para tapar el hueco
	for (int i = index; i < size - 1; i++) {
		v[i] = v[i + 1];
	}
	size--; // Reducimos el contador
}

int List::indexOf(int value) {
	for (int i = 0; i < size; i++) {
		if (v[i] == value) return i; // Encontrado
	}
	return -1; // No existe
}

void List::printList() {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "] | Size: " << size << " | Capacity: " << capacity << "\n";
}
