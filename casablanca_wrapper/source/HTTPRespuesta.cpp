#include <casablanca_wrapper/include/HTTPRespuesta.h>

using namespace herramientas::cpprest;

HTTPRespuesta::HTTPRespuesta() : IContieneJson()
{
}

HTTPRespuesta::HTTPRespuesta(web::http::http_response http_respuesta) : http_respuesta(http_respuesta), IContieneJson()
{
    std::string respuesta_json_string = http_respuesta.extract_utf8string().get();

    this->setJson(new herramientas::utiles::Json(respuesta_json_string));
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
