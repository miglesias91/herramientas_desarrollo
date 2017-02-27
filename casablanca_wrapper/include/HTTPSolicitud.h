#pragma once

//stl
#include <string>

// casablanca
#include <cpprest/http_client.h>

namespace HerramientasDesarrollo
{
namespace CasablancaWrapper
{

	class HTTPSolicitud
	{
	public:
		HTTPSolicitud();
		virtual ~HTTPSolicitud();

		// GETTERS
		
		web::http::http_request getSolicitud();

		// SETTERS

		void setCuerpo(std::string cuerpo);

		void setURI(std::string uri);

		void setPOST();

		void setGET();

		void setPUT();

		// METODOS

		void agregarEncabezado(std::string nombre_encabezado, std::string contenido_encabezado);

	private:

		web::http::method metodo_http;
		web::http::http_request solicitud;
	};

}
}

