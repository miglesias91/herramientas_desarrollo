#include <casablanca_wrapper/include/HTTPRespuesta.h>

using namespace herramientas::cpprest;

HTTPRespuesta::HTTPRespuesta() : json(NULL)
{
}

HTTPRespuesta::HTTPRespuesta(web::http::http_response http_respuesta) : http_respuesta(http_respuesta), json(NULL)
{
    std::string respuesta_string = utility::conversions::to_utf8string(http_respuesta.extract_string().get());

    this->json = new Json(respuesta_string);
}

HTTPRespuesta::~HTTPRespuesta()
{
    if (NULL != this->json)
    {
        delete this->json;
        this->json = NULL;
    }
}

// GETTERS

web::http::http_response HTTPRespuesta::getRespuesta()
{
	return this->http_respuesta;
}

Json * HTTPRespuesta::getJson()
{
    return this->json;
}

void HTTPRespuesta::setJson(Json * json)
{
    this->json = json;
}

// SETTERS

// METODOS
