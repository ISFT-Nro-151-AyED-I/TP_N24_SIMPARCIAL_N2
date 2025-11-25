#include <iostream>
#include <windows.h>
#include <string>

#include "../include/Articulo.hpp"
#include "../include/Cliente.hpp"
#include "../include/Pedido.hpp"

using namespace Cosmeticos;

// Función para mostrar el encabezado de la aplicación.
void mostrarEncabezado();

int main() 
    {
        // Configura consola para caracteres especiales.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        mostrarEncabezado();
        
        std::cout << "\n🚀 INICIALIZANDO DATOS DE PRUEBA..." << std::endl;
        std::cout << "======================================\n" << std::endl;
        
        // 1. CARGA ARTÍCULOS.
        std::cout << "\n📦 CARGANDO ARTÍCULOS..." << std::endl;
        
        Articulo* articulo1 = new Articulo(1, "Labial Rojo Passion", 25.50);
        Articulo* articulo2 = new Articulo(2, "Máscara de Pestañas", 18.75);
        Articulo* articulo3 = new Articulo(3, "Base Líquida Natural", 32.00);
        Articulo* articulo4 = new Articulo(4, "Sombras Multicolor", 28.90);
        Articulo* articulo5 = new Articulo(5, "Crema Hidratante", 45.25);
        
        std::cout << std::endl;

        // Muestra artículos cargados.
        articulo1->mostrarInfo();
        articulo2->mostrarInfo();
        articulo3->mostrarInfo();
        articulo4->mostrarInfo();
        articulo5->mostrarInfo();
        
        std::cout << std::endl;

        // 2. CARGA CLIENTES.
        std::cout << "\n👥 CARGANDO CLIENTES..." << std::endl;
        
        Cliente* cliente1 = new Cliente(101, "Iván Leterribleu");
        Cliente* cliente2 = new Cliente(102, "José Coder");
        Cliente* cliente3 = new Cliente(103, "Silvana Brujilda");
        
        std::cout << std::endl;

        // Muestra clientes cargados.
        cliente1->mostrarInfo();
        cliente2->mostrarInfo();
        cliente3->mostrarInfo();
        
        std::cout << std::endl;
        
        // 3. CARGA PEDIDOS.
        std::cout << "\n📋 CARGANDO PEDIDOS...\n" << std::endl;
        
        // Pedido 1: Iván compra varios artículos.
        Pedido* pedido1 = new Pedido(1001, cliente1);
        pedido1->agregarArticulo(articulo1, 2);  // 2 labiales.
        pedido1->agregarArticulo(articulo3, 1);  // 1 base.
        pedido1->agregarArticulo(articulo5, 1);  // 1 crema.
        
        // Pedido 2: José compra artículos.
        Pedido* pedido2 = new Pedido(1002, cliente2);
        pedido2->agregarArticulo(articulo2, 3);  // 3 máscaras.
        pedido2->agregarArticulo(articulo4, 1);  // 1 sombra.
        
        // Pedido 3: Silvana compra artículos.
        Pedido* pedido3 = new Pedido(1003, cliente3);
        pedido3->agregarArticulo(articulo1, 1);  // 1 labial.
        pedido3->agregarArticulo(articulo2, 2);  // 2 máscaras.
        pedido3->agregarArticulo(articulo4, 1);  // 1 sombra.
        pedido3->agregarArticulo(articulo5, 1);  // 1 crema.
        
        // 4. MUESTRA PEDIDOS DE CLIENTES.
        std::cout << "\n=======================================" << std::endl;
        std::cout << "   📊 MOSTRANDO PEDIDOS DE CLIENTES" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        // Muestra todos los pedidos.
        pedido1->mostrarPedido();
        pedido2->mostrarPedido();
        pedido3->mostrarPedido();
        
        // 5. DEMOSTRACIÓN ADICIONAL: Muestra pedidos por cliente.
        std::cout << "\n=======================================" << std::endl;
        std::cout << "       🔍 RESUMEN POR CLIENTE" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        std::cout << "\n👤 CLIENTE: " << cliente1->getNombre() << std::endl;
        std::cout << "   📦 Pedido #" << pedido1->getId() 
                << " - Total: $" << pedido1->calcularTotal() << std::endl;
        
        std::cout << "\n👤 CLIENTE: " << cliente2->getNombre() << std::endl;
        std::cout << "   📦 Pedido #" << pedido2->getId() 
                << " - Total: $" << pedido2->calcularTotal() << std::endl;
        
        std::cout << "\n👤 CLIENTE: " << cliente3->getNombre() << std::endl;
        std::cout << "   📦 Pedido #" << pedido3->getId() 
                << " - Total: $" << pedido3->calcularTotal() << std::endl;
        
        // 6. LIMPIEZA DE MEMORIA.
        std::cout << "\n\n=======================================" << std::endl;
        std::cout << "       🧹 LIBERANDO MEMORIA" << std::endl;
        std::cout << "=======================================\n" << std::endl;
        
        // Libera pedidos.
        delete pedido1;
        delete pedido2;
        delete pedido3;
        std::cout << "✅ Pedidos liberados." << std::endl;
        
        // Libera clientes.
        delete cliente1;
        delete cliente2;
        delete cliente3;
        std::cout << "✅ Clientes liberados." << std::endl;
        
        // Libera artículos.
        delete articulo1;
        delete articulo2;
        delete articulo3;
        delete articulo4;
        delete articulo5;
        std::cout << "✅ Artículos liberados." << std::endl;
        
        std::cout << "\n\n=======================================" << std::endl;
        std::cout << "🎉 PROGRAMA EJECUTADO EXITOSAMENTE! 🎉" << std::endl;
        std::cout << "=======================================" << std::endl;
        
        std::cout << "\nPresiona Enter para salir...";
        std::cin.get();
        
        return 0;
    }

void mostrarEncabezado() 
    {
        std::cout << "\n✨ ======================================= ✨" << std::endl;
        std::cout << "✨            COSMÉTICOS v1.0 🎀           ✨" << std::endl;
        std::cout << "✨      Sistema de Gestión de Pedidos      ✨" << std::endl;
        std::cout << "✨ ======================================= ✨" << std::endl;
        std::cout << std::endl;
    }