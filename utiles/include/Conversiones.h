#pragma once

// stl
#include <string>
#include <vector>

namespace herramientas
{
namespace utiles
{

class Conversiones
{
public:
    Conversiones();
    virtual ~Conversiones();

    static std::string string2base64(std::string tira_de_bytes_como_string);

    static std::string utf82iso8859_1(std::string a_convertir);
};

};
};


