#pragma once

// stl
#include <string>

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

	virtual ~Fecha();

    // GETTERS

	unsigned int getDia();
	unsigned int getMes();
	unsigned int getAnio();

	std::string getStringDia();
	std::string getStringMes();
	std::string getStringAnio();

    std::string getNombreMes();

    std::string getStringDDMMAAAA(std::string separador = "");

    std::string getStringDDmesAAAA(std::string separador = "");

    std::string getStringAAAAMMDD(std::string separador = "");

	// SETTERS

	void setDia(std::string dia);
	void setMes(std::string mes);
	void setAnio(std::string anio);

	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAnio(unsigned int anio);

    // METODOS

    // CONSULTAS

    // OPERADORES

    bool operator<(Fecha & fecha_a_comparar);
    bool operator>(Fecha & fecha_a_comparar);
    bool operator<=(Fecha & fecha_a_comparar);
    bool operator>=(Fecha & fecha_a_comparar);
    bool operator==(Fecha & fecha_a_comparar);

private:

    static std::string nombres_meses[];

    std::string etiqueta;

	unsigned int dia;
	unsigned int mes;
	unsigned int anio;

};

};
};

