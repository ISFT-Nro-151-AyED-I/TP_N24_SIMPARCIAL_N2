#include "../include/Articulo.hpp"

namespace Cosmeticos
    {
        // Constructor.
        Articulo::Articulo(int id, const std::string& nombre, double precio) 
                : id(id), nombre(nombre), precio(precio) {}

        // Getters.
        int Articulo::getId() const 
            {
                return id;
            }

        std::string Articulo::getNombre() const 
            {
                return nombre;
            }

        double Articulo::getPrecio() const 
            {
                return precio;
            }

        // Setters.
        void Articulo::setId(int id) 
            {
                this->id = id;
            }

        void Articulo::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        void Articulo::setPrecio(double precio) 
            {
                this->precio = precio;
            }

        // Métodos de utilidad.
        void Articulo::mostrarInfo() const 
            {
                std::cout << "🛍️  ID: " << id 
                        << " | Producto: " << nombre 
                        << " | Precio: $" << precio << std::endl;
            }
    }