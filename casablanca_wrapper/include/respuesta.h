#pragma once

// casablanca
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/IContieneJson.h>

namespace herramientas { namespace cpprest {

/// \brief wrapper de las http_response's
class respuesta : public herramientas::utiles::IContieneJson
{
public:
	respuesta();
	respuesta(web::http::http_response http_respuesta);
	virtual ~respuesta();

	web::http::http_response rta() const;
    std::string razon() const;
    std::string codigo() const;
    std::string cuerpo() const;

    // metodos de IContieneJson
    virtual bool armarJson() override;
    virtual bool parsearJson() override;

private:
	web::http::http_response http_respuesta;
};

}
}
