#include <utiles/include/IHashable.h>

using namespace herramientas::utiles;

std::hash<std::string> IHashable::hasher_string;
std::hash<unsigned int> IHashable::hasher_uint;

IHashable::IHashable()
{
}

IHashable::~IHashable()
{
}

unsigned long long int IHashable::hashear(std::string string_a_hashear)
{
    return hasher_string(string_a_hashear);
}

unsigned long long int IHashable::hashear(unsigned int uint_a_hashear)
{
    return hasher_uint(uint_a_hashear);
}

