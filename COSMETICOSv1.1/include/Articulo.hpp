#pragma once

#include <iostream>
#include <string>

namespace Cosmeticos 
    {
        class Articulo 
            {
                private:
                    int id;
                    std::string nombre;
                    double precio;
                    
                public:
                    // Constructor.
                    Articulo(int id = 0, const std::string& nombre = "", double precio = 0.0);
                    
                    // Getters.
                    int getId() const;
                    std::string getNombre() const;
                    double getPrecio() const;
                    
                    // Setters.
                    void setId(int id);
                    void setNombre(const std::string& nombre);
                    void setPrecio(double precio);
                    
                    // Métodos de utilidad.
                    void mostrarInfo() const;
            };
    }