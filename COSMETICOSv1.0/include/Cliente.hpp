#pragma once

#include <iostream>
#include <string>

namespace Cosmeticos
    {
        class Cliente 
            {
                private:
                    int id;
                    std::string nombre;
                    
                public:
                    // Constructor.
                    Cliente(int id = 0, const std::string& nombre = "");
                    
                    // Getters.
                    int getId() const;
                    std::string getNombre() const;
                    
                    // Setters.
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    
                    // Métodos de utilidad.
                    void mostrarInfo() const;
            };
    }