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
    Json(utility::string_t json);

    virtual ~Json();

    // METODOS

    void reset();

    void agregarAtributoValor(std::string clave, std::string valor);
    void agregarAtributoValor(std::string clave, unsigned int valor);

    void agregarAtributoArray(std::string clave, std::vector<unsigned long long int> array_valores);
    void agregarAtributoArray(std::string clave, std::vector<std::string> array_valores);

    void agregarAtributoJson(std::string clave, Json* json);

    Json * clonar();

    // GETTERS

    unsigned long long int getAtributoValorUint(std::string clave);
    std::string getAtributoValorString(std::string clave);
    Json* getAtributoValorJson(std::string clave);

    std::vector<unsigned long long int> getAtributoArrayUint(std::string clave);
    std::vector<std::string> getAtributoArrayString(std::string clave);
    std::vector<Json*> getAtributoArrayJson(std::string clave = "");

    rapidjson::Value* getValor();

    std::string jsonString();

    // SETTERS
    void setValor(rapidjson::Value* valor);

private:

    rapidjson::Value* valor;

    rapidjson::Document * documento_alocador;

    std::vector<Json*> copia_atributos_json;
};

};
};
