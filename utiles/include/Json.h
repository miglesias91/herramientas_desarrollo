#pragma once

// stl
#include <vector>

// rapidjson
#include <rapidjson/document.h>

// utiles
#include <utiles/include/JsonMalFormado.h>
#include <utiles/include/JsonNoExisteClave.h>
#include <utiles/include/JsonNoEsArray.h>

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
    virtual void agregarAtributoValor(std::string clave, uint64_t valor);
    virtual void agregarAtributoValor(std::string clave, uint32_t valor);
    virtual void agregarAtributoValor(std::string clave, float valor);
    virtual void agregarAtributoValor(std::string clave, bool valor);

    virtual void agregarAtributoArray(std::string clave, std::vector<uint64_t> array_valores);
    virtual void agregarAtributoArray(std::string clave, std::vector<std::string> array_valores);
    virtual void agregarAtributoArray(std::string clave, std::vector<Json*> array_valores);

    virtual void agregarAtributoJson(std::string clave, Json* json);

    virtual Json * clonar();

    // GETTERS

    virtual std::string getAtributoValorString(std::string clave);
    virtual uint64_t getAtributoValorUint(std::string clave);
    virtual float getAtributoValorFloat(std::string clave);
    virtual bool getAtributoValorBool(std::string clave);

    // Devuelve una copia. Cuando se termine de usar, se tiene que destruir (usando 'delete').
    virtual Json* getAtributoValorJson(std::string clave);

    virtual std::vector<uint64_t> getAtributoArrayUint(std::string clave);
    virtual std::vector<std::string> getAtributoArrayString(std::string clave);

    // Devuelve una copia de los valores. Cuando se terminen de usar, se tienen que destruir (usando 'delete').
    virtual std::vector<Json*> getAtributoArrayJson(std::string clave = "");

    virtual rapidjson::Value * getValor();

    virtual std::string jsonString();

    virtual std::string jsonStringLindo();

    // SETTERS

    virtual void setValor(rapidjson::Value* valor);

    virtual void setCantidadMaximaDecimales(uint32_t cantidad_maxima_decimales);

    // CONSULTA

    virtual bool contieneAtributo(std::string atributo);

    virtual bool esArray(std::string atributo = "");

private:

    rapidjson::Value* valor;

    rapidjson::Document * documento_alocador;

    std::vector<Json*> copia_atributos_json;

    uint32_t cantidad_maxima_decimales;
};

};
};
