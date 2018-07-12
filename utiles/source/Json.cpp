#include <utiles/include/Json.h>

// stl
#include <iostream>
#include <sstream>

// rapidjson
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

using namespace herramientas::utiles;

Json::Json() : valor(new rapidjson::Value(rapidjson::kObjectType)), documento_alocador(new rapidjson::Document()), cantidad_maxima_decimales(4)
{
}

Json::Json(rapidjson::Value* valor) : valor(valor), documento_alocador(new rapidjson::Document()), cantidad_maxima_decimales(4)
{
}

Json::Json(std::string json) : valor(NULL), documento_alocador(NULL), cantidad_maxima_decimales(4)
{
    rapidjson::Document* documento = new rapidjson::Document();

    try
    {
        documento->Parse(json.c_str());
    }
    catch (...)
    {
        throw excepciones::JsonMalFormado();
    }

    this->valor = new rapidjson::Value(*documento, documento->GetAllocator());

    this->documento_alocador = documento;
}

Json::~Json()
{
    delete this->valor;
    this->valor = NULL;

    delete this->documento_alocador;
    this->documento_alocador = NULL;

    for (std::vector<Json*>::iterator it = this->copia_atributos_json.begin(); it != this->copia_atributos_json.end(); it++)
    {
        delete *it;
    }

    this->copia_atributos_json.clear();
}

// METODOS

void Json::reset()
{
    delete this->valor;
    this->valor = NULL;

    delete this->documento_alocador;
    this->documento_alocador = NULL;

    for (std::vector<Json*>::iterator it = this->copia_atributos_json.begin(); it != this->copia_atributos_json.end(); it++)
    {
        delete *it;
    }
    this->copia_atributos_json.clear();

    this->valor = new rapidjson::Value(rapidjson::kObjectType);
    this->documento_alocador = new rapidjson::Document();
}

void Json::agregarAtributoValor(std::string clave, std::string valor)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    rapidjson::Value json_valor(valor.c_str(), *alocador);
    this->valor->AddMember(tag, json_valor, *alocador);
}

void Json::agregarAtributoValor(std::string clave, uint64_t valor)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    rapidjson::Value json_valor(valor);
    this->valor->AddMember(tag, json_valor, *alocador);
}

void Json::agregarAtributoValor(std::string clave, uint32_t valor)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    rapidjson::Value json_valor(valor);
    this->valor->AddMember(tag, json_valor, *alocador);
}

void Json::agregarAtributoValor(std::string clave, float valor)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    rapidjson::Value json_valor(valor);
    this->valor->AddMember(tag, json_valor, *alocador);
}

void Json::agregarAtributoValor(std::string clave, bool valor)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    rapidjson::Value json_valor(valor);
    this->valor->AddMember(tag, json_valor, *alocador);
}

void Json::agregarAtributoArray(std::string clave, std::vector<uint64_t> array_valores)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value json_valores(rapidjson::kArrayType);

    for (std::vector<uint64_t>::iterator it = array_valores.begin(); it != array_valores.end(); it++)
    {
        uint64_t valor = (*it);
        json_valores.PushBack(valor, *alocador);
    }

    rapidjson::Value tag(clave.c_str(), *alocador);
    this->valor->AddMember(tag, json_valores, *alocador);
}

void Json::agregarAtributoArray(std::string clave, std::vector<std::string> array_valores)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value json_valores(rapidjson::kArrayType);

    for (std::vector<std::string>::iterator it = array_valores.begin(); it != array_valores.end(); it++)
    {
        rapidjson::Value valor((*it).c_str(), *alocador);
        json_valores.PushBack(valor, *alocador);
    }

    rapidjson::Value tag(clave.c_str(), *alocador);
    this->valor->AddMember(tag, json_valores, *alocador);
}

void Json::agregarAtributoArray(std::string clave, std::vector<Json*> array_valores)
{
    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value json_valores(rapidjson::kArrayType);

    for (std::vector<Json*>::iterator it = array_valores.begin(); it != array_valores.end(); it++)
    {
        Json * copia_atributo = (*it)->clonar();

        rapidjson::Value valor(*(*it)->getValor(), *alocador);
        json_valores.PushBack(valor, *alocador);

        this->copia_atributos_json.push_back(copia_atributo);
    }

    rapidjson::Value tag(clave.c_str(), *alocador);
    this->valor->AddMember(tag, json_valores, *alocador);
}

void Json::agregarAtributoJson(std::string clave, Json * json)
{
    Json * copia_atributo = json->clonar();

    rapidjson::Document::AllocatorType* alocador = &this->documento_alocador->GetAllocator();

    rapidjson::Value tag(clave.c_str(), *alocador);
    this->valor->AddMember(tag, *copia_atributo->getValor(), *alocador);

    this->copia_atributos_json.push_back(copia_atributo);
}

std::string Json::jsonString()
{
    std::stringstream sstream;
    rapidjson::OStreamWrapper osw(sstream);

    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
    writer.SetMaxDecimalPlaces(this->cantidad_maxima_decimales);

    this->getValor()->Accept(writer);

    writer.Flush();

    return sstream.str();
}

std::string Json::jsonStringLindo()
{
    std::stringstream sstream;
    rapidjson::OStreamWrapper osw(sstream);

    rapidjson::PrettyWriter<rapidjson::OStreamWrapper> writer(osw);
    writer.SetMaxDecimalPlaces(this->cantidad_maxima_decimales);

    this->getValor()->Accept(writer);

    writer.Flush();

    return sstream.str();
}

Json * Json::clonar()
{
    return new Json(this->jsonString());
}

// GETTERS

uint64_t Json::getAtributoValorUint(std::string clave)
{
    if (false == this->contieneAtributo(clave))
    {
        throw excepciones::JsonNoExisteClave(clave + " (uint)");
    }

    uint64_t valor = (*this->valor)[clave.c_str()].GetUint64();

    return valor;
}

float Json::getAtributoValorFloat(std::string clave)
{
    if (false == this->contieneAtributo(clave))
    {
        throw excepciones::JsonNoExisteClave(clave + " (float)");
    }

    float valor = (*this->valor)[clave.c_str()].GetFloat();

    return valor;
}

bool Json::getAtributoValorBool(std::string clave)
{
    if (false == this->contieneAtributo(clave))
    {
        throw excepciones::JsonNoExisteClave(clave + " (bool)");
    }

    bool valor = (*this->valor)[clave.c_str()].GetBool();

    return valor;
}

std::string Json::getAtributoValorString(std::string clave)
{
    if (false == this->contieneAtributo(clave))
    {
        throw excepciones::JsonNoExisteClave(clave + " (string)");
    }

    std::string valor = (*this->valor)[clave.c_str()].GetString();

    return valor;
}

Json * Json::getAtributoValorJson(std::string clave)
{
    if (false == this->contieneAtributo(clave))
    {
        throw excepciones::JsonNoExisteClave(clave + " (json)");
    }

    rapidjson::Value* valor = &(*this->valor)[clave.c_str()];

    std::stringstream sstream;
    rapidjson::OStreamWrapper osw(sstream);

    rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
    writer.SetMaxDecimalPlaces(this->cantidad_maxima_decimales);

    valor->Accept(writer);

    writer.Flush();

    Json* json = new Json(sstream.str());

    return json;
}

std::vector<uint64_t> Json::getAtributoArrayUint(std::string clave)
{
    std::vector<uint64_t> valores;

    rapidjson::Value* vector = NULL;

    if (clave.empty())
    {
        if (false == this->esArray())
        {
            throw excepciones::JsonNoEsArray("este valor (array uint)");
        }

        vector = &(*this->valor);
    }
    else
    {
        if (false == this->contieneAtributo(clave))
        {
            return valores;
            //throw excepciones::JsonNoExisteClave(clave + " (array uint)");
        }

        vector = &(*this->valor)[clave.c_str()];

        if (false == vector->IsArray())
        {
            throw excepciones::JsonNoEsArray(clave + " (array uint)");
        }
    }

    for (rapidjson::Value::ValueIterator it = vector->Begin(); it != vector->End(); it++)
    {
        uint64_t valor = it->GetUint64();
        valores.push_back(valor);
    }

    return valores;
}

std::vector<std::string> Json::getAtributoArrayString(std::string clave)
{
    std::vector<std::string> valores;

    rapidjson::Value* vector = NULL;

    if (clave.empty())
    {
        if (false == this->esArray())
        {
            throw excepciones::JsonNoEsArray("este valor (array string)");
        }

        vector = &(*this->valor);
    }
    else
    {
        if (false == this->contieneAtributo(clave))
        {
            return valores;
            //throw excepciones::JsonNoExisteClave(clave + " (array string)");
        }

        vector = &(*this->valor)[clave.c_str()];

        if (false == vector->IsArray())
        {
            throw excepciones::JsonNoEsArray(clave + " (array string)");
        }
    }

    for (rapidjson::Value::ValueIterator it = vector->Begin(); it != vector->End(); it++)
    {
        std::string valor = it->GetString();
        valores.push_back(valor);
    }

    return valores;
}

std::vector<Json*> Json::getAtributoArrayJson(std::string clave)
{
    std::vector<Json*> valores;

    rapidjson::Value* vector = NULL;

    if (clave.empty())
    {
        if (false == this->esArray())
        {
            throw excepciones::JsonNoEsArray("este valor (array json)");
        }

        vector = &(*this->valor);
    }
    else
    {
        if (false == this->contieneAtributo(clave))
        {
            //throw excepciones::JsonNoExisteClave(clave + " (array json)");
            return valores;
        }

        vector = &(*this->valor)[clave.c_str()];

        if (false == vector->IsArray())
        {
            throw excepciones::JsonNoEsArray(clave + " (array json)");
        }
    }

    for (rapidjson::Value::ValueIterator it = vector->Begin(); it != vector->End(); it++)
    {
        rapidjson::Value* valor = &(*it);

        rapidjson::Value* valor_nuevo = new rapidjson::Value(rapidjson::kObjectType);

        valor_nuevo->CopyFrom(*valor, this->documento_alocador->GetAllocator());

        Json* json = new Json(valor_nuevo);

        valores.push_back(json);
    }

    return valores;
}

rapidjson::Value* Json::getValor()
{
    return this->valor;
}

// SETTERS

void Json::setValor(rapidjson::Value * valor)
{
    this->valor = valor;
}

void Json::setCantidadMaximaDecimales(uint32_t cantidad_maxima_decimales)
{
    this->cantidad_maxima_decimales = cantidad_maxima_decimales;
}

// CONSULTAS

bool Json::contieneAtributo(std::string atributo)
{
    return this->valor->HasMember(atributo.c_str());
}

bool Json::esArray(std::string atributo)
{
    if (atributo.empty())
    {
        return this->valor->IsArray();
    }
    else
    {
        if (false == this->contieneAtributo(atributo))
        {
            throw excepciones::JsonNoExisteClave(atributo + " (array)");
        }

        rapidjson::Value* vector = NULL;

        vector = &(*this->valor)[atributo.c_str()];

        return vector->IsArray();
    }
}
