#pragma once

#include <iostream>
#include <string>

#include "Articulo.hpp"
#include "Cliente.hpp"

namespace Cosmeticos
    {
        class Pedido 
            {
                private:
                    int id;
                    Cliente* cliente;           // Agregación PURA.
                    Articulo** articulos;       // Agregación PURA - array de artículos.
                    int* cantidades;            // Array de cantidades por artículo.
                    int cantidadArticulos;      // Artículos actuales en el pedido.
                    int capacidadArticulos;     // Capacidad del array (para redimensionar).
                    
                public:
                    // Constructor y destructor.
                    Pedido(int id = 0, Cliente* cliente = nullptr);
                    ~Pedido();
                    
                    // Getters.
                    int getId() const;
                    Cliente* getCliente() const;
                    int getCantidadArticulos() const;
                    
                    // Setters.
                    void setId(int id);
                    void setCliente(Cliente* cliente);
                    
                    // Gestión de artículos.
                    void agregarArticulo(Articulo* articulo, int cantidad);
                    void mostrarPedido() const;
                    double calcularTotal() const;
            };
    }