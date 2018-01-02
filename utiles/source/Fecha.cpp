#include <utiles/include/Fecha.h>

// funciones string
#include <utiles/include/FuncionesString.h>

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

Fecha Fecha::parsearFormatoAAAAMMDD(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }

    std::string string_anio = string_fecha.substr(0, 4);
    std::string string_mes = string_fecha.substr(4, 2);
    std::string string_dia = string_fecha.substr(6, 2);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::stoul(string_mes);
    unsigned int dia = std::stoul(string_dia);

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoDDmesAAAA(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }

    std::string string_dia = string_fecha.substr(0, 2);
    std::string string_mes = string_fecha.substr(2, string_fecha.size() - 6);
    std::string string_anio = string_fecha.substr(string_fecha.size() - 4, 4);

    unsigned int mes = std::distance(nombres_meses->begin(), std::find(nombres_meses->begin(), nombres_meses->end(), string_mes);

    unsigned int anio = std::stoul(string_anio);
    unsigned int mes = std::stoul(string_mes);
    unsigned int dia = std::stoul(string_dia);

    return Fecha(dia, mes, anio);
}

Fecha Fecha::parsearFormatoDDMMAAAA(std::string string_fecha, std::string separador)
{
    if (separador.size() > 0)
    {
        FuncionesString::eliminarOcurrencias(string_fecha, separador);
    }

    return Fecha();
}

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
