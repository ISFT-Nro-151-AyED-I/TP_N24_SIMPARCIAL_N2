#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

#include "../include/Articulo.hpp"
#include "../include/Cliente.hpp"
#include "../include/Pedido.hpp"

namespace Cosmeticos
    {
        // Constantes para límites de arreglos estáticos (actualizadas a 50).
        const int MAX_CLIENTES = 50;
        const int MAX_ARTICULOS = 50;
        const int MAX_PEDIDOS = 50;
        const int CAPACIDAD_PEDIDO = 50;  // Capacidad interna de cada pedido.

        // Variables globales para almacenamiento estático.
        extern Cliente* clientes[MAX_CLIENTES];
        extern Articulo* articulos[MAX_ARTICULOS];
        extern Pedido* pedidos[MAX_PEDIDOS];
        extern int totalClientes;
        extern int totalArticulos;
        extern int totalPedidos;
        extern int ultimoIdCliente;
        extern int ultimoIdArticulo;
        extern int ultimoIdPedido;

        // Prototipos de funciones del menú.
        void menuPrincipal();
        void mostrarEncabezado();
        void cargarDatosEjemplo();
        void limpiarPantalla();
        void pausa();

        // Funciones para gestión de clientes.
        void menuClientes();
        void crearCliente();
        void listarClientes();
        void buscarClientePorId();

        // Funciones para gestión de artículos.
        void menuArticulos();
        void crearArticulo();
        void listarArticulos();
        void buscarArticuloPorId();

        // Funciones para gestión de pedidos.
        void menuPedidos();
        void crearPedido();
        void listarPedidos();
        void buscarPedidoPorId();
        void mostrarPedidoCompleto(Pedido* pedido);

        // Función para borrar Todo.
        void liberarMemoria();
    }

// Declaración de la función menu() que será llamada desde main.cpp.
void menu();