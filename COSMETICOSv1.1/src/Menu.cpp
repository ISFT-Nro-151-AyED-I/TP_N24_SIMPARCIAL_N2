#include "../include/Menu.hpp"

namespace Cosmeticos
    {
        // ==================== VARIABLES GLOBALES ====================
        Cliente* clientes[MAX_CLIENTES] = {nullptr};
        Articulo* articulos[MAX_ARTICULOS] = {nullptr};
        Pedido* pedidos[MAX_PEDIDOS] = {nullptr};
        
        int totalClientes = 0;
        int totalArticulos = 0;
        int totalPedidos = 0;
        int ultimoIdCliente = 103;
        int ultimoIdArticulo = 5;
        int ultimoIdPedido = 1003;

        // ==================== FUNCIONES PRINCIPALES DEL MENÚ ====================
        void menuPrincipal()
            {
                cargarDatosEjemplo();
                pausa();
                
                int opcion;

                do
                    {
                        limpiarPantalla();
                        mostrarEncabezado();
                        
                        std::cout << "🏠 MENÚ PRINCIPAL\n";
                        std::cout << "==================\n\n";
                        std::cout << "1.Gestión de Clientes 👥\n";
                        std::cout << "2.Gestión de Artículos 🛍️\n";
                        std::cout << "3.Gestión de Pedidos 📋\n";
                        std::cout << "4.Mostrar estadísticas 📊\n";
                        std::cout << "5.Salir 🚪\n\n";
                        std::cout << "Selecciona una opción: ";
                        std::cin >> opcion;
                        std::cin.ignore();

                        switch(opcion)
                            {
                                case 1:
                                    menuClientes();
                                    break;
                                case 2:
                                    menuArticulos();
                                    break;
                                case 3:
                                    menuPedidos();
                                    break;
                                case 4:
                                    {
                                        limpiarPantalla();
                                        mostrarEncabezado();

                                        std::cout << "📊 ESTADÍSTICAS DEL SISTEMA\n";
                                        std::cout << "============================\n\n";
                                        std::cout << "👥 Clientes registrados: " << totalClientes << "/" << MAX_CLIENTES << std::endl;
                                        std::cout << "🛍️  Artículos registrados: " << totalArticulos << "/" << MAX_ARTICULOS << std::endl;
                                        std::cout << "📦 Pedidos registrados: " << totalPedidos << "/" << MAX_PEDIDOS << std::endl;
                                        
                                        double ventasTotales = 0.0;

                                        for(int i = 0; i < totalPedidos; i++)
                                            {
                                                ventasTotales += pedidos[i]->calcularTotal();
                                            }

                                        std::cout << "💰 Ventas totales: $" << std::fixed << std::setprecision(2) << ventasTotales << std::endl;
                                        pausa();
                                    }
                                    break;
                                case 5:
                                    std::cout << "\n👋 ¡Gracias por usar COSMÉTICOS v1.1!\n";
                                    liberarMemoria();
                                    break;
                                default:
                                    std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
                                    pausa();
                            }
                    } while(opcion != 5);
            }

        void mostrarEncabezado()
            {
                std::cout << "\n✨ ====================================== ✨\n";
                std::cout << "✨          COSMÉTICOS v1.1 🎀            ✨\n";
                std::cout << "✨    Sistema de Gestión de Pedidos       ✨\n";
                std::cout << "✨       (Menú Interactivo)               ✨\n";
                std::cout << "✨ ====================================== ✨\n\n";
            }

        void cargarDatosEjemplo()
            {
                // 1. CARGA ARTÍCULOS.
                articulos[0] = new Articulo(1, "Labial Rojo Passion", 25.50);
                articulos[1] = new Articulo(2, "Máscara de Pestañas", 18.75);
                articulos[2] = new Articulo(3, "Base Líquida Natural", 32.00);
                articulos[3] = new Articulo(4, "Sombras Multicolor", 28.90);
                articulos[4] = new Articulo(5, "Crema Hidratante", 45.25);

                std::cout << "\n📦 CARGANDO ARTÍCULOS...\n\n";

                for(int i = 0; i < 5; i++) // Muestra los 5 artículos.
                    {
                        articulos[i]->mostrarInfo();
                    }

                totalArticulos += 5;
                
                // 2. CARGA CLIENTES.
                clientes[0] = new Cliente(101, "Iván Leterribleu");
                clientes[1] = new Cliente(102, "José Coder");
                clientes[2] = new Cliente(103, "Silvana Vengerberg");
                
                std::cout << "\n📦 CARGANDO CLIENTES...\n\n";

                for(int i = 0; i < 3; i++) // Muestra los 3 clientes.
                    {
                        clientes[i]->mostrarInfo();
                    }

                totalClientes += 3;
                
                // 3. CARGA PEDIDOS (sin mostrar mensajes de agregar).
                std::cout << "\n📋 CARGANDO PEDIDOS...\n\n";
                
                // Crea Pedido 1.
                Pedido* pedido1 = new Pedido(1001, clientes[0]);
                pedido1->agregarArticulo(articulos[0], 2); // 2 labiales.
                pedido1->agregarArticulo(articulos[2], 1); // 1 base.
                pedido1->agregarArticulo(articulos[4], 1); // 1 crema.
                pedidos[0] = pedido1;
                
                // Crea Pedido 2.
                Pedido* pedido2 = new Pedido(1002, clientes[1]); 
                pedido2->agregarArticulo(articulos[1], 3); // 3 máscaras.
                pedido2->agregarArticulo(articulos[3], 1); // 1 sombra.
                pedidos[1] = pedido2;
                
                // Crea Pedido 3.
                Pedido* pedido3 = new Pedido(1003, clientes[2]);
                pedido3->agregarArticulo(articulos[0], 1); // 1 labial.
                pedido3->agregarArticulo(articulos[1], 2); // 2 máscaras.
                pedido3->agregarArticulo(articulos[3], 1); // 1 sombra.
                pedido3->agregarArticulo(articulos[4], 1); // 1 crema.
                pedidos[2] = pedido3;
                
                totalPedidos += 3;

                // 4. MUESTRA RESUMEN.
                std::cout << "\n" << std::string(43, '=') << std::endl;
                std::cout << "✅ Datos de ejemplo cargados exitosamente!\n\n";
                std::cout << "   📦 Artículos: " << totalArticulos << std::endl;
                std::cout << "   👥 Clientes: " << totalClientes << std::endl;
                std::cout << "   📋 Pedidos: " << totalPedidos << std::endl;
                std::cout << std::string(43, '=') << std::endl << std::endl;
            }

        void limpiarPantalla()
            {
                system("cls");
            }

        void pausa()
            {
                std::cout << "\n\n👉 Presiona Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
            }

        // ==================== FUNCIONES PARA GESTIÓN DE CLIENTES ====================
        void menuClientes()
            {
                int opcion;

                do
                    {
                        limpiarPantalla();
                        mostrarEncabezado();
                        
                        std::cout << "👥 MENÚ DE CLIENTES\n";
                        std::cout << "====================\n\n";
                        std::cout << "1.Crear nuevo cliente\n";
                        std::cout << "2.Listar todos los clientes\n";
                        std::cout << "3.Buscar cliente por ID\n";
                        std::cout << "4.Volver al menú principal\n\n";
                        std::cout << "Selecciona una opción: ";
                        std::cin >> opcion;
                        std::cin.ignore();

                        switch(opcion)
                            {
                                case 1:
                                    crearCliente();
                                    break;
                                case 2:
                                    listarClientes();
                                    pausa();
                                    break;
                                case 3:
                                    buscarClientePorId();
                                    pausa();
                                    break;
                                case 4:
                                    std::cout << "\nVolviendo al menú principal...\n";
                                    break;
                                default:
                                    std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
                                    pausa();
                            }
                    } while(opcion != 4);
            }

        void crearCliente()
            {
                if(totalClientes >= MAX_CLIENTES)
                    {
                        std::cout << "\n❌ No se pueden agregar más clientes. Capacidad máxima alcanzada.\n";
                        pausa();
                        return;
                    }

                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "👤 CREAR NUEVO CLIENTE\n";
                std::cout << "=======================\n\n";
                
                std::string nombre;
                std::cout << "Ingresa el nombre del cliente: ";
                std::getline(std::cin, nombre);
                
                if(nombre.empty())
                    {
                        std::cout << "❌ El nombre no puede estar vacío.\n";
                        pausa();
                        return;
                    }
                
                ultimoIdCliente++;
                clientes[totalClientes] = new Cliente(ultimoIdCliente, nombre);
                totalClientes++;
                
                std::cout << "\n✅ Cliente creado exitosamente!\n";
                std::cout << "   ID: " << ultimoIdCliente << std::endl;
                std::cout << "   Nombre: " << nombre << std::endl;
                
                pausa();
            }

        void listarClientes()
            {
                limpiarPantalla();
                mostrarEncabezado();
            
                std::cout << "📋 LISTADO DE CLIENTES\n";
                std::cout << "=======================\n\n";
            
            if(totalClientes == 0)
                {
                    std::cout << "📭 No hay clientes registrados.\n";
                    return;
                }
            
            for(int i = 0; i < totalClientes; i++)
                {
                    std::cout << "👤 ID: " << std::setw(4) << clientes[i]->getId() 
                              << " | Nombre: " << clientes[i]->getNombre() << std::endl;
                }
            
            std::cout << "\n📊 Total de clientes: " << totalClientes << std::endl;
        }

        void buscarClientePorId()
            {
                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "🔍 BUSCAR CLIENTE POR ID\n";
                std::cout << "=========================\n\n";
                
                if(totalClientes == 0)
                    {
                        std::cout << "📭 No hay clientes registrados.\n";
                        return;
                    }
                
                int idBuscado;

                std::cout << "Ingresa el ID del cliente: ";
                std::cin >> idBuscado;
                
                for(int i = 0; i < totalClientes; i++)
                    {
                        if(clientes[i]->getId() == idBuscado)
                            {
                                std::cout << "\n✅ Cliente encontrado:\n";
                                std::cout << "   👤 ID: " << clientes[i]->getId() << std::endl;
                                std::cout << "   📛 Nombre: " << clientes[i]->getNombre() << std::endl;
                                
                                int pedidosCliente = 0;

                                std::cout << "\n   📦 Pedidos del cliente:\n";
                                
                                for(int j = 0; j < totalPedidos; j++)
                                    {
                                        if(pedidos[j]->getCliente()->getId() == idBuscado)
                                            {
                                                std::cout << "      • Pedido #" << pedidos[j]->getId() 
                                                          << " - Total: $" << pedidos[j]->calcularTotal() << std::endl;
                                                pedidosCliente++;
                                            }
                                    }
                                
                                if(pedidosCliente == 0)
                                    {
                                        std::cout << "      📭 No tienes pedidos registrados\n";
                                    }
                                
                                return;
                            }
                    }
                
                std::cout << "\n❌ No se encontró ningún cliente con ID " << idBuscado << std::endl;
            }

        // ==================== FUNCIONES PARA GESTIÓN DE ARTÍCULOS ====================
        void menuArticulos()
            {
                int opcion;

                do
                    {
                        limpiarPantalla();
                        mostrarEncabezado();
                        
                        std::cout << "🛍️ MENÚ DE ARTÍCULOS\n";
                        std::cout << "=====================\n\n";
                        std::cout << "1.Crear nuevo artículo\n";
                        std::cout << "2.Listar todos los artículos\n";
                        std::cout << "3.Buscar artículo por ID\n";
                        std::cout << "4.Volver al menú principal\n\n";
                        std::cout << "Selecciona una opción: ";
                        std::cin >> opcion;
                        std::cin.ignore();

                        switch(opcion)
                            {
                                case 1:
                                    crearArticulo();
                                    break;
                                case 2:
                                    listarArticulos();
                                    pausa();
                                    break;
                                case 3:
                                    buscarArticuloPorId();
                                    pausa();
                                    break;
                                case 4:
                                    std::cout << "\nVolviendo al menú principal...\n";
                                    break;
                                default:
                                    std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
                                    pausa();
                            }
                    } while(opcion != 4);
            }

        void crearArticulo()
            {
                if(totalArticulos >= MAX_ARTICULOS)
                    {
                        std::cout << "\n❌ No se pueden agregar más artículos. Capacidad máxima alcanzada.\n";
                        pausa();
                        return;
                    }

                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "🛍️ CREAR NUEVO ARTÍCULO\n";
                std::cout << "========================\n\n";
                
                std::string nombre;
                double precio;
                
                std::cout << "Ingresa el nombre del artículo: ";
                std::getline(std::cin, nombre);
                
                if(nombre.empty())
                    {
                        std::cout << "❌ El nombre no puede estar vacío.\n";
                        pausa();
                        return;
                    }
                
                std::cout << "Ingresa el precio del artículo: $";
                std::cin >> precio;
                
                if(precio < 0)
                    {
                        std::cout << "❌ El precio no puede ser negativo.\n";
                        pausa();
                        return;
                    }
                
                ultimoIdArticulo++;
                articulos[totalArticulos] = new Articulo(ultimoIdArticulo, nombre, precio);
                totalArticulos++;
                
                std::cout << "\n✅ Artículo creado exitosamente!\n";
                std::cout << "   ID: " << ultimoIdArticulo << std::endl;
                std::cout << "   Nombre: " << nombre << std::endl;
                std::cout << "   Precio: $" << precio << std::endl;
                
                pausa();
            }

        void listarArticulos()
            {
                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "📋 LISTADO DE ARTÍCULOS\n";
                std::cout << "========================\n\n";
                
                if(totalArticulos == 0)
                    {
                        std::cout << "📭 No hay artículos registrados.\n";
                        return;
                    }
                
                for(int i = 0; i < totalArticulos; i++)
                    {
                        std::cout << "🛍️  ID: " << std::setw(4) << articulos[i]->getId() 
                                  << " | Nombre: " << std::setw(30) << std::left << articulos[i]->getNombre()
                                  << " | Precio: $" << std::fixed << std::setprecision(2) << articulos[i]->getPrecio() << std::endl;
                    }
                
                std::cout << "\n📊 Total de artículos: " << totalArticulos << std::endl;
            }

        void buscarArticuloPorId()
            {
                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "🔍 BUSCAR ARTÍCULO POR ID\n";
                std::cout << "==========================\n\n";
                
                if(totalArticulos == 0)
                    {
                        std::cout << "📭 No hay artículos registrados.\n";
                        return;
                    }
                
                int idBuscado;
                
                std::cout << "Ingresa el ID del artículo: ";
                std::cin >> idBuscado;
                
                for(int i = 0; i < totalArticulos; i++)
                    {
                        if(articulos[i]->getId() == idBuscado)
                            {
                                std::cout << "\n✅ Artículo encontrado:\n";
                                std::cout << "   🛍️  ID: " << articulos[i]->getId() << std::endl;
                                std::cout << "   📛 Nombre: " << articulos[i]->getNombre() << std::endl;
                                std::cout << "   💰 Precio: $" << articulos[i]->getPrecio() << std::endl;
                                return;
                            }
                    }
                
                std::cout << "\n❌ No se encontró ningún artículo con ID " << idBuscado << std::endl;
            }

        // ==================== FUNCIONES PARA GESTIÓN DE PEDIDOS ====================
        void menuPedidos()
            {
                int opcion;

                do
                    {
                        limpiarPantalla();
                        mostrarEncabezado();
                        
                        std::cout << "📋 MENÚ DE PEDIDOS\n";
                        std::cout << "===================\n\n";
                        std::cout << "1.Crear nuevo pedido\n";
                        std::cout << "2.Listar todos los pedidos\n";
                        std::cout << "3.Buscar pedido por ID\n";
                        std::cout << "4.Volver al menú principal\n\n";
                        std::cout << "Selecciona una opción: ";
                        std::cin >> opcion;
                        std::cin.ignore();

                        switch(opcion)
                            {
                                case 1:
                                    crearPedido();
                                    break;
                                case 2:
                                    listarPedidos();
                                    pausa();
                                    break;
                                case 3:
                                    buscarPedidoPorId();
                                    pausa();
                                    break;
                                case 4:
                                    std::cout << "\nVolviendo al menú principal...\n";
                                    break;
                                default:
                                    std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
                                    pausa();
                            }
                    } while(opcion != 4);
            }

        void crearPedido()
            {
                if(totalPedidos >= MAX_PEDIDOS)
                    {
                        std::cout << "\n❌ No se pueden crear más pedidos. Capacidad máxima alcanzada.\n";
                        pausa();
                        return;
                    }

                if(totalClientes == 0)
                    {
                        std::cout << "\n❌ No hay clientes registrados. Debes crear al menos un cliente primero.\n";
                        pausa();
                        return;
                    }

                if(totalArticulos == 0)
                    {
                        std::cout << "\n❌ No hay artículos registrados. Debes crear al menos un artículo primero.\n";
                        pausa();
                        return;
                    }

                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "📦 CREAR NUEVO PEDIDO\n";
                std::cout << "======================\n\n";
                
                std::cout << "👥 SELECCIONA UN CLIENTE:\n";
                listarClientes();
                
                int idCliente;

                std::cout << "\nIngresa el ID del cliente: ";
                std::cin >> idCliente;
                
                Cliente* clienteSeleccionado = nullptr;
                for(int i = 0; i < totalClientes; i++)
                    {
                        if(clientes[i]->getId() == idCliente)
                            {
                                clienteSeleccionado = clientes[i];
                                break;
                            }
                    }
                
                if(!clienteSeleccionado)
                    {
                        std::cout << "\n❌ Cliente no encontrado.\n";
                        pausa();
                        return;
                    }
                
                ultimoIdPedido++;
                Pedido* nuevoPedido = new Pedido(ultimoIdPedido, clienteSeleccionado);
                
                char continuar = 'S';

                while(continuar == 'S' || continuar == 's')
                    {
                        limpiarPantalla();
                        mostrarEncabezado();
                        
                        std::cout << "🛍️ AGREGAR ARTÍCULOS AL PEDIDO #" << ultimoIdPedido << "\n";
                        std::cout << "========================================\n\n";
                        
                        listarArticulos();
                        
                        int idArticulo, cantidad;

                        std::cout << "\nIngresa el ID del artículo a agregar: ";
                        std::cin >> idArticulo;
                        
                        Articulo* articuloSeleccionado = nullptr;

                        for(int i = 0; i < totalArticulos; i++)
                            {
                                if(articulos[i]->getId() == idArticulo)
                                    {
                                        articuloSeleccionado = articulos[i];
                                        break;
                                    }
                            }
                        
                        if(!articuloSeleccionado)
                            {
                                std::cout << "\n❌ Artículo no encontrado.\n";
                            }
                            else
                                {
                                    std::cout << "Ingresa la cantidad: ";
                                    std::cin >> cantidad;
                                    
                                    if(cantidad <= 0)
                                        {
                                            std::cout << "\n❌ La cantidad debe ser mayor a 0.\n";
                                        }
                                        else
                                            {
                                                nuevoPedido->agregarArticulo(articuloSeleccionado, cantidad);
                                            }
                                }
                        
                        std::cout << "\n¿Deseas agregar otro artículo? (S/N): ";
                        std::cin >> continuar;
                    }
                
                pedidos[totalPedidos] = nuevoPedido;
                totalPedidos++;
                
                std::cout << "\n✅ Pedido creado exitosamente!\n";
                std::cout << "   📦 Número de pedido: " << ultimoIdPedido << std::endl;
                std::cout << "   👤 Cliente: " << clienteSeleccionado->getNombre() << std::endl;
                std::cout << "   💰 Total: $" << nuevoPedido->calcularTotal() << std::endl;
                
                pausa();
            }

        void listarPedidos()
            {
                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "📋 LISTADO DE PEDIDOS\n";
                std::cout << "======================\n\n";
                
                if(totalPedidos == 0)
                    {
                        std::cout << "📭 No hay pedidos registrados.\n";
                        return;
                    }
                
                for(int i = 0; i < totalPedidos; i++)
                    {
                        std::cout << "📦 Pedido #" << pedidos[i]->getId() 
                                  << " | Cliente: " << pedidos[i]->getCliente()->getNombre()
                                  << " | Artículos: " << pedidos[i]->getCantidadArticulos()
                                  << " | Total: $" << std::fixed << std::setprecision(2) 
                                  << pedidos[i]->calcularTotal() << std::endl;
                    }
                
                std::cout << "\n📊 Total de pedidos: " << totalPedidos << std::endl;
            }

        void buscarPedidoPorId()
            {
                limpiarPantalla();
                mostrarEncabezado();
                
                std::cout << "🔍 BUSCAR PEDIDO POR ID\n";
                std::cout << "========================\n\n";
                
                if(totalPedidos == 0)
                    {
                        std::cout << "📭 No hay pedidos registrados.\n";
                        return;
                    }
                
                int idBuscado;

                std::cout << "Ingresa el ID del pedido: ";
                std::cin >> idBuscado;
                
                for(int i = 0; i < totalPedidos; i++)
                {
                    if(pedidos[i]->getId() == idBuscado)
                    {
                        std::cout << "\n✅ Pedido encontrado:\n";
                        mostrarPedidoCompleto(pedidos[i]);
                        return;
                    }
                }
                
                std::cout << "\n❌ No se encontró ningún pedido con ID " << idBuscado << std::endl;
            }

        void mostrarPedidoCompleto(Pedido* pedido)
            {
                pedido->mostrarPedido();
            }

        void liberarMemoria()
            {
                std::cout << "\n\n🧹 LIBERANDO MEMORIA DEL SISTEMA...\n";
                std::cout << "=======================================\n";
                
                // Libera todos los pedidos.
                int pedidosLiberados = 0;

                for(int i = 0; i < totalPedidos; i++)
                    {
                        if(pedidos[i] != nullptr)
                            {
                                delete pedidos[i];
                                pedidos[i] = nullptr;
                                pedidosLiberados++;
                            }
                    }
                std::cout << "✅ " << pedidosLiberados << " pedidos liberados.\n";
                
                // Libera todos los clientes.
                int clientesLiberados = 0;

                for(int i = 0; i < totalClientes; i++)
                    {
                        if(clientes[i] != nullptr)
                            {
                                delete clientes[i];
                                clientes[i] = nullptr;
                                clientesLiberados++;
                            }
                    }
                std::cout << "✅ " << clientesLiberados << " clientes liberados.\n";
                
                // Libera todos los artículos.
                int articulosLiberados = 0;
                
                for(int i = 0; i < totalArticulos; i++)
                    {
                        if(articulos[i] != nullptr)
                            {
                                delete articulos[i];
                                articulos[i] = nullptr;
                                articulosLiberados++;
                            }
                    }
                std::cout << "✅ " << articulosLiberados << " artículos liberados.\n";
                
                // Reinicia los contadores.
                totalClientes = 0;
                totalArticulos = 0;
                totalPedidos = 0;
                
                std::cout << "✅ Memoria liberada exitosamente!\n";
            }
    }

// ==================== FUNCIÓN MENÚ (fuera del namespace) ====================
void menu()
    {
        Cosmeticos::menuPrincipal();
    }