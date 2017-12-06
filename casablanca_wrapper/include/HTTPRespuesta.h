#pragma once

// stl

// casablanca
#include <cpprest/http_client.h>

namespace herramientas
{
namespace cpprest
{

/// \brief wrapper de las http_response's
class HTTPRespuesta
{
public:
	HTTPRespuesta();

	HTTPRespuesta(web::http::http_response http_respuesta);
	virtual ~HTTPRespuesta();

	// GETTERS

	web::http::http_response getRespuesta();

	// SETTERS

	// METODOS

private:

	web::http::http_response http_respuesta;
};

}
}
