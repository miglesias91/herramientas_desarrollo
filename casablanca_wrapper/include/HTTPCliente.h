#pragma once

// stl
#include <string>

// casablanca
#include <cpprest/http_client.h>

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPSolicitud.h>

namespace HerramientasDesarrollo
{
namespace CasablancaWrapper
{
	/// \brief wrapper de los http_client's
	class HTTPCliente
	{
	public:
		HTTPCliente(std::string nombre_cliente);
		virtual ~HTTPCliente();

		// GETTERS

		// SETTERS

		// METODOS

		void solicitar(HTTPSolicitud& solicitud);

	private:

		web::http::client::http_client cliente;
		std::string nombre_cliente;
	};

}
}

