#pragma once

// stl
#include <vector>

// log
#include <log/include/ConfiguracionLogger.h>
#include <log/include/SalidaLogger.h>

namespace herramientas
{
namespace log
{

class Logger
{
public:

    Logger(std::vector<SalidaLogger*> salidas, ConfiguracionLogger * configuracion);
    virtual ~Logger();

    // GETTERS

    std::string getNombre();

    spdlog::level::level_enum getNivelLog();
    spdlog::level::level_enum getNivelFlush();

    // SETTERS

    // METODOS

    void marca(const std::string & mensaje);
    void debug(const std::string & mensaje);
    void info(const std::string & mensaje);
    void advertencia(const std::string & mensaje);
    void error(const std::string & mensaje);
    void critico(const std::string & mensaje);

    // CONSULTAS

private:

    // ATRIBUTOS

    ConfiguracionLogger * configuracion;

    std::vector<SalidaLogger*> salidas;

    std::shared_ptr<spdlog::logger> logger_ptr;

    static std::vector<std::string> nombres_niveles;
};

};
};

