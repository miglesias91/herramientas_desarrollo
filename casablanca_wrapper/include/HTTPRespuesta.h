#pragma once

// stl

// casablanca
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/IContieneJson.h>

namespace herramientas
{
namespace cpprest
{

/// \brief wrapper de las http_response's
class HTTPRespuesta : public herramientas::utiles::IContieneJson
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

    // ATRIBUTOS

	web::http::http_response http_respuesta;
};

}
}
