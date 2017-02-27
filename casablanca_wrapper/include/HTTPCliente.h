#pragma once

// stl

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPSolicitud.h>

namespace HerramientasDesarrollo
{
namespace CasablancaWrapper
{

	class HTTPCliente
	{
	public:
		HTTPCliente(std::string cliente);
		virtual ~HTTPCliente();

		// GETTERS

		// SETTERS

		// METODOS

		void solicitar(HTTPSolicitud& solicitud);

	private:

		std::string cliente;
	};

}
}

