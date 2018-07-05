#include <utiles/include/Excepcion.h>

using namespace herramientas::utiles::excepciones;

Excepcion::Excepcion()
{
}

Excepcion::Excepcion(const std::string& desc)
{
    this->descripcion << desc;
}

Excepcion::Excepcion(const Excepcion& e)
{
    this->descripcion << e.descripcion.str();
    this->mensaje << e.mensaje.str();
}

Excepcion& Excepcion::operator = (const Excepcion& e)
{
    if (&e != this)
    {
        this->descripcion << e.descripcion.str();
        this->mensaje << e.mensaje.str();
    }
    return *this;
}

Excepcion::~Excepcion()
{
}

const std::stringstream& Excepcion::getMensaje() const
{
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(char* s)
{
    this->mensaje << s;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(std::string& s)
{
    this->mensaje << s;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(bool n)
{
    if (n)
    {
        this->mensaje << "true";
    }
    else
    {
        this->mensaje << "false";
    }
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(short n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(unsigned short n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(int n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(uint32_t n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(long n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(unsigned long n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(float n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(double n)
{
    this->mensaje << n;
    return this->mensaje;
}

std::stringstream& Excepcion::operator<<(long double n)
{
    this->mensaje << n;
    return this->mensaje;
}
