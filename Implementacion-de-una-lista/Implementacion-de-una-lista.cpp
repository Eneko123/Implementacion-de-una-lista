// Implementacion-de-una-lista.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "List.h"
#include <iostream>

int main() {
    List l;

    std::cout << "--- 1. Inicializacion ---\n";
    l.init(4); // Capacidad inicial 4
    l.printList();

    std::cout << "\n--- 2. Aniadir elementos y forzando resize ---\n";
    for (int i = 1; i <= 6; i++)
    {
        l.add(i * 10);
    }
    l.printList(); // Debería mostrar capacity=8

    std::cout << "\n--- 3. Inserciones ---\n";
    l.insertAt(0, 99);      // Al principio
    l.insertAt(3, 55);      // En medio
    l.insertAt(l.GetSize(), 88); // Al final
    l.printList();

    std::cout << "\n--- 4. Eliminaciones ---\n";
    l.removeAt(0); // Quita el 99
    l.removeAt(2); // Quita un elemento del medio
    l.printList();

    std::cout << "\n--- 5. Busquedas ---\n";
    int pos1 = l.indexOf(30);
    int pos2 = l.indexOf(999);
    std::cout << "Valor 30 en indice: " << pos1 << "\n";
    std::cout << "Valor 999 en indice: " << pos2 << " (-1 = no existe)\n";

    std::cout << "\n--- 6. Limpieza de memoria ---\n";
    l.freeList();
    l.printList(); // Deberia mostrar lista vacia y capacity=0

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
