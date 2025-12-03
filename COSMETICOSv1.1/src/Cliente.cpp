#include "../include/Cliente.hpp"

namespace Cosmeticos 
    {
        // Constructor.
        Cliente::Cliente(int id, const std::string& nombre) 
                : id(id), nombre(nombre) {}

        // Getters.
        int Cliente::getId() const 
            {
                return id;
            }

        std::string Cliente::getNombre() const 
            {
                return nombre;
            }

        // Setters.
        void Cliente::setId(int id) 
            {
                this->id = id;
            }

        void Cliente::setNombre(const std::string& nombre) 
            {
                this->nombre = nombre;
            }

        // Métodos de utilidad.
        void Cliente::mostrarInfo() const 
            {
                std::cout << "👤 ID: " << id 
                        << " | Cliente: " << nombre << std::endl;
            }
    }