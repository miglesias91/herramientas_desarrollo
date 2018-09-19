#include <casablanca_wrapper/include/respuesta.h>

namespace herramientas { namespace cpprest {

respuesta::respuesta() : IContieneJson() {}

respuesta::respuesta(web::http::http_response http_respuesta) : http_respuesta(http_respuesta), IContieneJson() {
    std::string respuesta_json_string = http_respuesta.extract_utf8string().get();

    this->setJson(new herramientas::utiles::Json(respuesta_json_string));
}

respuesta::~respuesta() {}

web::http::http_response respuesta::rta() const {
    return this->http_respuesta;
}

std::string respuesta::razon() const {
    return utility::conversions::to_utf8string(this->http_respuesta.reason_phrase().c_str());
}

std::string respuesta::codigo() const {
    return {};
}

std::string respuesta::cuerpo() const {
    return {};
}

bool respuesta::armarJson() {
    return true;
}

bool respuesta::parsearJson() {
    return true;
}
}
}
