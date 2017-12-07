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

private:

    Json * json;
};

};
};

