#include <herramientas_desarrollo/casablanca_wrapper/include/HTTPRespuesta.h>

using namespace herramientas::cpprest;

HTTPRespuesta::HTTPRespuesta()
{
}

HTTPRespuesta::HTTPRespuesta(web::http::http_response http_respuesta) : http_respuesta(http_respuesta)
{
}

HTTPRespuesta::~HTTPRespuesta()
{
}

// GETTERS

web::http::http_response HTTPRespuesta::getRespuesta()
{
	return this->http_respuesta;
}

// SETTERS

// METODOS
