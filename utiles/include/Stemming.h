#pragma once

// stl
#include <vector>

// steemming
#include <stemming/spanish_stem.h>

namespace herramientas
{
namespace utiles
{

class Stemming
{
public:

    Stemming();
    virtual ~Stemming();

    static void stem(std::string & string_a_stemmear);

    static void stem(std::vector<std::string> & vector_de_string_a_stemmear);

private:

    static stemming::spanish_stem<> stem_spanish;

};

};
};

