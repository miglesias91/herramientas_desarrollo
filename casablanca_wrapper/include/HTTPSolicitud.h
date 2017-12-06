#pragma once

//stl
#include <string>

// casablanca wrapper
#include <casablanca_wrapper/include/HTTPRespuesta.h>

// casablanca
#include <cpprest/http_client.h>

namespace herramientas
{
namespace cpprest
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

	// METODOS

	void agregarEncabezado(std::string nombre_encabezado, std::string contenido_encabezado);

private:

	web::http::method metodo_http;
	web::http::http_request solicitud;
};

}
}

