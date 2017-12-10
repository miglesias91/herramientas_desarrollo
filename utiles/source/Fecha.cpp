#include <utiles/include/Fecha.h>

using namespace herramientas::utiles;

std::string Fecha::nombres_meses[] = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };

// CONSTRUCTORES

Fecha::Fecha(std::string etiqueta) : dia(0), mes(0), anio(0), etiqueta(etiqueta)
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : dia(dia), mes(mes), anio(anio), etiqueta(etiqueta)
{
}

Fecha::~Fecha()
{
}

// GETTERS

unsigned int Fecha::getDia()
{
	return this->dia;
}

unsigned int Fecha::getMes()
{
	return this->mes;
}

unsigned int Fecha::getAnio()
{
	return this->anio;
}

std::string Fecha::getStringDia()
{
	return std::to_string(this->dia);
}

std::string Fecha::getStringMes()
{
	return std::to_string(this->mes);
}

std::string Fecha::getStringAnio()
{
	return std::to_string(this->anio);
}

std::string Fecha::getNombreMes()
{
    return nombres_meses[this->mes - 1];
}

std::string Fecha::getStringDDMMAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getStringMes() + separador + this->getStringAnio();
}

std::string Fecha::getStringAAAAMMDD(std::string separador)
{
    return this->getStringAnio() + separador + this->getStringMes() + separador + this->getStringDia();
}

std::string Fecha::getStringDDmesAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getNombreMes() + separador + this->getStringAnio();
}

// SETTERS

void Fecha::setDia(std::string dia)
{
	this->dia = std::stoi(dia);
}

void Fecha::setMes(std::string mes)
{
	this->mes = std::stoi(mes);
}

void Fecha::setAnio(std::string anio)
{
	this->anio = std::stoi(anio);
}

void Fecha::setDia(unsigned int dia)
{
	this->dia = dia;
}

void Fecha::setMes(unsigned int mes)
{
	this->mes = mes;
}

void Fecha::setAnio(unsigned int anio)
{
	this->anio = anio;
}

// METODOS

// CONSULTAS

// OPERADORES

bool Fecha::operator<(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha < string_fecha_a_comparar;
}

bool Fecha::operator>(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha > string_fecha_a_comparar;
}

bool Fecha::operator<=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha <= string_fecha_a_comparar;
}

bool Fecha::operator>=(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha >= string_fecha_a_comparar;
}

bool Fecha::operator==(Fecha & fecha_a_comparar)
{
    std::string string_esta_fecha = this->getStringAAAAMMDD();
    std::string string_fecha_a_comparar = fecha_a_comparar.getStringAAAAMMDD();

    return string_esta_fecha == string_fecha_a_comparar;
}
