#pragma once

// modelo
#include <utiles/include/Json.h>

namespace herramientas
{
namespace utiles
{

class IContieneJson
{
public:
    // CONSTRUCTORES

    IContieneJson(Json * json = NULL);
    virtual ~IContieneJson();

    // GETTERS

    virtual Json * getJson();

    // SETTERS

    virtual void setJson(Json * json);

    // METODOS

    // completa el 'json' interno con los atributos de la entidad heredera.
    virtual bool armarJson() = 0;

    // lee los datos del 'json' interno para completar los atributos de la entidad heredera.
    virtual bool parsearJson() = 0;

private:

    Json * json;
};

};
};

