#include <log/include/ConfiguracionLogger.h>

using namespace herramientas::log;

// stl
#include <fstream>
#include <sstream>

// utiles
#include <utiles/include/Json.h>

// rapidjson
#include <rapidjson/document.h>

ConfiguracionLogger::ConfiguracionLogger(std::string path_archivo_configuracion)
{
    if (false == path_archivo_configuracion.empty())
    {
        this->leerConfiguracion(path_archivo_configuracion);
    }
}

ConfiguracionLogger::~ConfiguracionLogger()
{
}

void ConfiguracionLogger::leerConfiguracion(std::string path_archivo_configuracion)
{
    std::ifstream archivo(path_archivo_configuracion);

    if (false == archivo.good())
    {
        throw - 1;
    }

    std::ostringstream sstream;
    sstream << archivo.rdbuf();
    const std::string string_config(sstream.str());

    herramientas::utiles::Json config_json(string_config);

    herramientas::utiles::Json * config_log_json = config_json.getAtributoValorJson("log");

    this->nombre_logger = config_log_json->getAtributoValorString(ConfiguracionLogger::tagNombreLogger());
    this->tamanio_cola_async = config_log_json->getAtributoValorUint(ConfiguracionLogger::tagTamanioColaAsync());
    this->nivel = config_log_json->getAtributoValorString(ConfiguracionLogger::tagNivel().c_str());
    this->flush = config_log_json->getAtributoValorString(ConfiguracionLogger::tagFlush().c_str());
    this->patron = config_log_json->getAtributoValorString(ConfiguracionLogger::tagPatron());
    this->agrupar_por_fecha = config_log_json->getAtributoValorBool(ConfiguracionLogger::tagAgruparPorFecha());
    this->salidas_logger = config_log_json->getAtributoArrayString(ConfiguracionLogger::tagSalidas());

    delete config_log_json;
}

// CONFIGURACIONES

std::string ConfiguracionLogger::getNombreLogger()
{
    return this->nombre_logger;
}

unsigned long long int ConfiguracionLogger::getTamanioColaAsync()
{
    return this->tamanio_cola_async;
}

bool ConfiguracionLogger::getAgruparPorFecha()
{
    return this->agrupar_por_fecha;
}

std::string ConfiguracionLogger::getNivel()
{
    return this->nivel;
}

std::string ConfiguracionLogger::getFlush()
{
    return this->flush;
}

std::string ConfiguracionLogger::getPatron()
{
    return this->patron;
}

std::vector<std::string> ConfiguracionLogger::getSalidas()
{
    return this->salidas_logger;
}

// TAGS

std::string ConfiguracionLogger::tagNombreLogger()
{
    return "nombre";
}

std::string ConfiguracionLogger::tagTamanioColaAsync()
{
    return "tamanio_cola_async";
}

std::string ConfiguracionLogger::tagNivel()
{
    return "nivel";
}

std::string ConfiguracionLogger::tagFlush()
{
    return "flush";
}

std::string ConfiguracionLogger::tagPatron()
{
    return "patron";
}

std::string ConfiguracionLogger::tagAgruparPorFecha()
{
    return "agrupar_por_fecha";
}

std::string ConfiguracionLogger::tagSalidas()
{
    return "salidas";
}

std::string ConfiguracionLogger::tagSalidaTipo()
{
    return "tipo";
}

std::string ConfiguracionLogger::tagSalidaPath()
{
    return "path";
}
