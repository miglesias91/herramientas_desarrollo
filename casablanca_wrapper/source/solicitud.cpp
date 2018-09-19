#include <casablanca_wrapper/include/solicitud.h>

namespace herramientas { namespace cpprest {

    const std::array<std::string, 4> solicitud::nombres_metodos = { u8"GET", u8"POST", u8"PUT", u8"DELETE" };
    const std::array<web::http::method, 4> solicitud::metodos_web = { web::http::methods::GET, web::http::methods::POST, web::http::methods::PUT, web::http::methods::DEL };

solicitud::solicitud() : solicitud_http_ptr(new web::http::http_request()), metodo_solicitud(GET), cuerpo_solicitud({}), uri_solicitud({}) {}

solicitud::~solicitud() {}

// GETTERS

web::http::http_request* solicitud::solicitud_http() const {
    return this->solicitud_http_ptr.get();
}

std::string solicitud::cuerpo() const {
    return this->cuerpo_solicitud;
}

solicitud::metodos solicitud::metodo() const {
    return this->metodo_solicitud;
}

std::string solicitud::nombre_metodo() const {
    return this->nombres_metodos.at(this->metodo_solicitud);
}

std::string solicitud::uri() const {
    return this->uri_solicitud;
}

std::vector<std::string> solicitud::encabezados() const {
    return this->encabezados_solicitud;
}

void solicitud::cuerpo(const std::string &cuerpo_solicitud) {
    this->solicitud_http_ptr->set_body(cuerpo_solicitud);

    this->cuerpo_solicitud = cuerpo_solicitud;
}

void solicitud::uri(const std::string &uri_solicitud) {
    utility::string_t uri_t = utility::conversions::to_string_t(uri_solicitud);

    web::uri web_uri(uri_t);

    this->solicitud_http_ptr->set_request_uri(web_uri);

    this->uri_solicitud = uri_solicitud;
}

void solicitud::metodo(const metodos &metodo_solicitud) {
    this->metodo_solicitud = metodo_solicitud;
    this->solicitud_http_ptr->set_method(metodos_web.at(this->metodo_solicitud));
}

void solicitud::nuevo_encabezado(const std::string &nombre_encabezado, const std::string &contenido_encabezado) {
    utility::string_t nombre_encabezado_t = utility::conversions::to_string_t(nombre_encabezado);

    utility::string_t contenido_encabezado_t = utility::conversions::to_string_t(contenido_encabezado);

    this->solicitud_http_ptr->headers().add(nombre_encabezado_t, contenido_encabezado_t);

    this->encabezados_solicitud.push_back(nombre_encabezado + ": " + contenido_encabezado);
}

}
}