#pragma once

// stl
#include <string>
#include <vector>

// log
#include <log/include/SalidaLogger.h>

namespace herramientas
{
namespace log
{

class ConfiguracionLogger
{
public:

    ConfiguracionLogger(std::string path_archivo_configuracion = "");
    virtual ~ConfiguracionLogger();

    // METODOS

    void leerConfiguracion(std::string path_archivo_configuracion);

    // CONFIGURACIONES

    bool getActivado();
    std::string getNombreLogger();
    uint64_t  getTamanioColaAsync();
    bool getAgruparPorFecha();
    std::string getNivelLog();
    std::string getNivelFlush();
    std::string getPatron();
    std::vector<std::string> getSalidas();

    // TAGS

    std::string tagActivado();
    std::string tagNombreLogger();
    std::string tagTamanioColaAsync();
    std::string tagAgruparPorFecha();
    std::string tagNivelLog();
    std::string tagNivelFlush();
    std::string tagPatron();
    std::string tagSalidas();

private:

    bool activado;
    std::string nombre_logger;
    uint64_t tamanio_cola_async;
    bool agrupar_por_fecha;
    std::string nivel_log;
    std::string nivel_flush;
    std::string patron;
    std::vector<std::string> salidas_logger;
};

};
};
