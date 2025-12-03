#include <iostream>
#include <windows.h>

#include "../include/Menu.hpp"

int main() 
    {
        // Configura consola para caracteres especiales y emojis.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        // Llama al menú interactivo.
        menu();
        
        return 0;
    }