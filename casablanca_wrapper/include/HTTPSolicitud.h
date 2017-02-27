#pragma once

//stl
#include <string>

// casablanca wrapper
#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPRespuesta.h>

// casablanca
#include <cpprest/http_client.h>

namespace HerramientasDesarrollo
{
namespace CasablancaWrapper
{
	/// \brief wrapper de las http_request's
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

		void setRespuesta(HTTPRespuesta respuesta);

		// METODOS

		void agregarEncabezado(std::string nombre_encabezado, std::string contenido_encabezado);

	private:

		HTTPRespuesta respuesta;

		web::http::method metodo_http;
		web::http::http_request solicitud;
	};

}
}

