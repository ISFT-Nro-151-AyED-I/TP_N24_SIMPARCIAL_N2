#include "../include/Pedido.hpp"

namespace Cosmeticos
    {
        // Constructor.
        Pedido::Pedido(int id, Cliente* cliente) 
               : id(id), cliente(cliente), cantidadArticulos(0), capacidadArticulos(10) 
            {
                // Inicializa arrays dinámicos con capacidad fija.
                articulos = new Articulo*[capacidadArticulos];
                cantidades = new int[capacidadArticulos];
            }
        
        // Destructor.
        Pedido::~Pedido() 
            {
                // 🔥 MUCHO MUY IMPORTANTE: Solo liberamos los arrays, NO los objetos (agregación PURA).
                delete[] articulos;
                delete[] cantidades;
            }

        // Getters.
        int Pedido::getId() const 
            {
                return id;
            }

        Cliente* Pedido::getCliente() const 
            {
                return cliente;
            }

        int Pedido::getCantidadArticulos() const 
            {
                return cantidadArticulos;
            }

        // Setters.
        void Pedido::setId(int id) 
            {
                this->id = id;
            }

        void Pedido::setCliente(Cliente* cliente) 
            {
                this->cliente = cliente;
            }

        // Agrega artículo al pedido.
        void Pedido::agregarArticulo(Articulo* articulo, int cantidad) 
            {
                if (cantidadArticulos >= capacidadArticulos) 
                    {
                        std::cout << "❌ No se puede agregar más artículos. Capacidad máxima alcanzada: " 
                                  << capacidadArticulos << std::endl;

                        return;
                    }
                
                // Agrega artículo y cantidad a los arrays.
                articulos[cantidadArticulos] = articulo;
                cantidades[cantidadArticulos] = cantidad;
                cantidadArticulos++;

                std::cout << "✅ Artículo agregado: " << articulo->getNombre() 
                          << " (Cantidad: " << cantidad << ")" << std::endl;
            }

        // Muestra información completa del pedido.
        void Pedido::mostrarPedido() const 
            {
                if (!cliente) 
                    {
                        std::cout << "❌ Pedido sin cliente asignado" << std::endl;
                        return;
                    }

                std::cout << "\n\n📦 PEDIDO #" << id << std::endl;
                std::cout << "=================\n" << std::endl;
                std::cout << "👤 Cliente: " << cliente->getNombre() << std::endl;
                std::cout << "\n🛍️  Artículos en el pedido:\n" << std::endl;
                
                if (cantidadArticulos == 0) 
                    {
                        std::cout << "   📭 No hay artículos en este pedido" << std::endl;
                    } else 
                        {
                            for (int i = 0; i < cantidadArticulos; i++) 
                                {
                                    std::cout << "   " << (i + 1) << ". " << articulos[i]->getNombre()
                                            << " | Cantidad: " << cantidades[i]
                                            << " | Precio unitario: $" << articulos[i]->getPrecio()
                                            << " | Subtotal: $" << (articulos[i]->getPrecio() * cantidades[i])
                                            << std::endl;
                                }
                        }
                std::cout << "\n------------------------------" << std::endl;
                std::cout << "💰 TOTAL DEL PEDIDO: $" << calcularTotal() << std::endl;
                std::cout << "------------------------------" << std::endl;
            }

        // Calcula total del pedido.
        double Pedido::calcularTotal() const 
            {
                double total = 0.0;

                for (int i = 0; i < cantidadArticulos; i++) 
                    {
                        total += articulos[i]->getPrecio() * cantidades[i];
                    }

                return total;
            }
    }