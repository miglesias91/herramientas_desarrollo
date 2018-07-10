#include <log/include/ConfiguracionLogger.h>

using namespace herramientas::log;

// stl
#include <fstream>
#include <sstream>

// utiles
#include <utiles/include/Fecha.h>
#include <utiles/include/Json.h>

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

    this->activado = config_log_json->getAtributoValorBool(ConfiguracionLogger::tagActivado());
    this->nombre_logger = config_log_json->getAtributoValorString(ConfiguracionLogger::tagNombreLogger());
    this->tamanio_cola_async = config_log_json->getAtributoValorUint(ConfiguracionLogger::tagTamanioColaAsync());
    this->nivel_log = config_log_json->getAtributoValorString(ConfiguracionLogger::tagNivelLog().c_str());
    this->nivel_flush = config_log_json->getAtributoValorString(ConfiguracionLogger::tagNivelFlush().c_str());
    this->patron = config_log_json->getAtributoValorString(ConfiguracionLogger::tagPatron());
    this->agrupar_por_fecha = config_log_json->getAtributoValorBool(ConfiguracionLogger::tagAgruparPorFecha());
    this->salidas_logger = config_log_json->getAtributoArrayString(ConfiguracionLogger::tagSalidas());

    delete config_log_json;
}

// CONFIGURACIONES

bool ConfiguracionLogger::getActivado()
{
    return this->activado;
}

std::string ConfiguracionLogger::getNombreLogger()
{
    return this->nombre_logger;
}

uint64_t ConfiguracionLogger::getTamanioColaAsync()
{
    return this->tamanio_cola_async;
}

bool ConfiguracionLogger::getAgruparPorFecha()
{
    return this->agrupar_por_fecha;
}

std::string ConfiguracionLogger::getNivelLog()
{
    return this->nivel_log;
}

std::string ConfiguracionLogger::getNivelFlush()
{
    return this->nivel_flush;
}

std::string ConfiguracionLogger::getPatron()
{
    return this->patron;
}

std::vector<std::string> ConfiguracionLogger::getSalidas()
{
    std::vector<std::string> salidas = this->salidas_logger;

    if (this->getAgruparPorFecha())
    {
        std::string string_fecha_actual = herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDD();

        for (std::vector<std::string>::iterator it = salidas.begin(); it != salidas.end(); it++)
        {
            *it = string_fecha_actual + "_" + *it;
        }
    }

    return salidas;
}

// TAGS

std::string ConfiguracionLogger::tagActivado()
{
    return "activado";
}

std::string ConfiguracionLogger::tagNombreLogger()
{
    return "nombre";
}

std::string ConfiguracionLogger::tagTamanioColaAsync()
{
    return "tamanio_cola_async";
}

std::string ConfiguracionLogger::tagAgruparPorFecha()
{
    return "agrupar_por_fecha";
}

std::string ConfiguracionLogger::tagNivelLog()
{
    return "nivel_log";
}

std::string ConfiguracionLogger::tagNivelFlush()
{
    return "nivel_flush";
}

std::string ConfiguracionLogger::tagPatron()
{
    return "patron";
}

std::string ConfiguracionLogger::tagSalidas()
{
    return "salidas";
}
