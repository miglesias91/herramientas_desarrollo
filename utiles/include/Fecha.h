#pragma once

// stl
#include <string>
#include <vector>

namespace herramientas
{
namespace utiles
{

class Fecha
{
public:

	// CONSTRUCTORES

	Fecha(std::string etiqueta = "");

	Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta = "");

    Fecha(unsigned int dia, unsigned int mes, unsigned int anio, unsigned int horas, unsigned int minutos, unsigned int segundos, std::string etiqueta = "");

	virtual ~Fecha();

    // GETTERS

    static Fecha getFechaActual();

	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAnio() const;
    unsigned int getHoras() const;
    unsigned int getMinutos() const;
    unsigned int getSegundos() const;

	std::string getStringDia() const;
	std::string getStringMes() const;
	std::string getStringAnio() const;
    std::string getStringHoras() const;
    std::string getStringMinutos() const;
    std::string getStringSegundos() const;

    std::string getNombreMes() const;

    std::string getStringDDMMAAAA(std::string separador = "") const;

    std::string getStringDDmesAAAA(std::string separador = "") const;

    std::string getStringAAAAMMDD(std::string separador = "") const;
    
    std::string getStringAAAAMMDDHHmmSS(std::string separador_dia = "", std::string separador_dia_hora = "", std::string separador_hora = "") const;

	// SETTERS

	void setDia(std::string dia);
	void setMes(std::string mes);
	void setAnio(std::string anio);
    void setHoras(std::string dia);
    void setMinutos(std::string mes);
    void setSegundos(std::string anio);

	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAnio(unsigned int anio);
    void setHoras(unsigned int dia);
    void setMinutos(unsigned int mes);
    void setSegundos(unsigned int anio);

    // METODOS

    static bool parsear(const std::string & string_fecha, const std::string & formato, Fecha * fecha);
    static Fecha parsearFormatoAAAAMMDD(std::string string_fecha, std::string separador = "");
    static Fecha parsearFormatoAAAAMMDDHHmmSS(std::string string_fecha, std::string separador_dia = "", std::string separador_dia_hora = "", std::string separador_hora = "");
    static Fecha parsearFormatoDDmesAAAA(std::string string_fecha, std::string separador = "");
    static Fecha parsearFormatoDDMMAAAA(std::string string_fecha, std::string separador = "");

    // CONSULTAS

    // OPERADORES

    bool operator<(const Fecha & fecha_a_comparar) const;
    bool operator>(const Fecha & fecha_a_comparar) const;
    bool operator<=(const Fecha & fecha_a_comparar) const;
    bool operator>=(const Fecha & fecha_a_comparar) const;
    bool operator==(const Fecha & fecha_a_comparar) const;
    bool operator!=(const Fecha & fecha_a_comparar) const;

private:

    static std::vector<std::string> nombres_meses;

    std::string etiqueta;

	unsigned int dia;
	unsigned int mes;
	unsigned int anio;

    unsigned int horas;
    unsigned int minutos;
    unsigned int segundos;

};

};
};

