#pragma once

// stl
#include <vector>

// cpprest
#include <cpprest/details/basic_types.h>

// rapidjson
#include <rapidjson/document.h>

namespace herramientas
{
namespace utiles
{

class Json
{
public:
    Json();
    Json(rapidjson::Value* valor);
    Json(std::string json);

    virtual ~Json();

    // METODOS

    virtual void reset();

    virtual void agregarAtributoValor(std::string clave, std::string valor);
    virtual void agregarAtributoValor(std::string clave, unsigned long long int valor);
    virtual void agregarAtributoValor(std::string clave, float valor);

    virtual void agregarAtributoArray(std::string clave, std::vector<unsigned long long int> array_valores);
    virtual void agregarAtributoArray(std::string clave, std::vector<std::string> array_valores);

    virtual void agregarAtributoJson(std::string clave, Json* json);

    virtual Json * clonar();

    // GETTERS

    virtual std::string getAtributoValorString(std::string clave);
    virtual unsigned long long int getAtributoValorUint(std::string clave);
    virtual float getAtributoValorFloat(std::string clave);

    // Devuelve una copia. Cuando se termine de usar, se tiene que destruir (usando 'delete').
    virtual Json* getAtributoValorJson(std::string clave);

    virtual std::vector<unsigned long long int> getAtributoArrayUint(std::string clave);
    virtual std::vector<std::string> getAtributoArrayString(std::string clave);
    virtual std::vector<Json*> getAtributoArrayJson(std::string clave = "");

    virtual rapidjson::Value* getValor();

    virtual std::string jsonString();

    // SETTERS

    virtual void setValor(rapidjson::Value* valor);

    virtual void setCantidadMaximaDecimales(unsigned int cantidad_maxima_decimales);

private:

    rapidjson::Value* valor;

    rapidjson::Document * documento_alocador;

    std::vector<Json*> copia_atributos_json;

    unsigned int cantidad_maxima_decimales;
};

};
};
