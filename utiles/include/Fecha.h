#pragma once

// stl
#include <string>
#include <chrono>
#include <vector>
#include <time.h>

namespace herramientas
{
namespace utiles
{

class Fecha
{
public:

	// CONSTRUCTORES

	Fecha(const std::string & etiqueta = "");

	Fecha(const uint32_t & dia, const uint32_t & mes, const uint32_t & anio, const std::string & etiqueta = "");

    Fecha(const uint32_t & dia, const uint32_t & mes, const uint32_t & anio, const uint32_t & horas, const uint32_t & minutos, const uint32_t & segundos, const std::string & etiqueta = "");

	virtual ~Fecha();

    // GETTERS

    static Fecha getFechaActual();

	uint32_t getDia() const;
	uint32_t getMes() const;
	uint32_t getAnio() const;
    uint32_t getHoras() const;
    uint32_t getMinutos() const;
    uint32_t getSegundos() const;

	std::string getStringDia() const;
	std::string getStringMes() const;
	std::string getStringAnio() const;
    std::string getStringHoras() const;
    std::string getStringMinutos() const;
    std::string getStringSegundos() const;

    std::string getNombreMes() const;

    std::string getStringDDMMAAAA(const std::string & separador = "") const;

    std::string getStringDDmesAAAA(const std::string & separador = "") const;

    std::string getStringAAAAMMDD(const std::string & separador = "") const;
    
    std::string getStringAAAAMMDDHHmmSS(const std::string & separador_dia = "", const std::string & separador_dia_hora = "", const std::string & separador_hora = "") const;

	// SETTERS

	void setDia(const std::string & dia);
	void setMes(const std::string & mes);
	void setAnio(const std::string & anio);
    void setHoras(const std::string & dia);
    void setMinutos(const std::string & mes);
    void setSegundos(const std::string & anio);

	void setDia(const uint32_t & dia);
	void setMes(const uint32_t & mes);
	void setAnio(const uint32_t & anio);
    void setHoras(const uint32_t & dia);
    void setMinutos(const uint32_t & mes);
    void setSegundos(const uint32_t & anio);

    // METODOS

    static bool parsear(const std::string & string_fecha, const std::string & formato, Fecha * fecha);
    static Fecha parsearFormatoAAAAMMDD(const std::string & string_fecha, const std::string & separador = "");
    static Fecha parsearFormatoAAAAMMDDHHmmSS(const std::string & string_fecha, const std::string & separador_dia = "", const std::string & separador_dia_hora = "", const std::string & separador_hora = "");
    static Fecha parsearFormatoDDmesAAAA(const std::string & string_fecha, const std::string & separador = "");
    static Fecha parsearFormatoDDMMAAAA(const std::string & string_fecha, const std::string & separador = "");

    static Fecha parsear(const std::chrono::system_clock::time_point & segundos);

    // CONSULTAS

    // OPERADORES

    bool operator<(const Fecha & fecha_a_comparar) const;
    bool operator>(const Fecha & fecha_a_comparar) const;
    bool operator<=(const Fecha & fecha_a_comparar) const;
    bool operator>=(const Fecha & fecha_a_comparar) const;
    bool operator==(const Fecha & fecha_a_comparar) const;
    bool operator!=(const Fecha & fecha_a_comparar) const;

    bool operator-=(const std::chrono::hours & horas);
    bool operator+=(const std::chrono::hours & horas);
    bool operator-=(const std::chrono::minutes & minutos);
    bool operator+=(const std::chrono::minutes & minutos);
    bool operator-=(const std::chrono::seconds & segundos);
    bool operator+=(const std::chrono::seconds & segundos);

private:

    static std::vector<std::string> nombres_meses;

    std::string etiqueta;

	uint32_t dia;
	uint32_t mes;
	uint32_t anio;

    uint32_t horas;
    uint32_t minutos;
    uint32_t segundos;

};

};
};

