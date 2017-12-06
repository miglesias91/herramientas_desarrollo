#pragma once

// stl

// casablanca
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/Json.h>

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

    Json * getJson();

	// SETTERS

    void setJson(Json * json);

	// METODOS

private:
    // ATRIBUTOS

	web::http::http_response http_respuesta;

    Json * json;
};

}
}
