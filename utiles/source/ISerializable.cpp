#include <utiles/include/ISerializable.h>

using namespace herramientas::utiles;

ISerializable::ISerializable(Json * json) : json(json)
{
}

ISerializable::~ISerializable()
{
    delete this->json;
    this->json = NULL;
}

Json * ISerializable::getJson()
{
    if (NULL == this->json)
    {
        this->json = new Json();
    }

    return this->json;
}

void ISerializable::setJson(Json * json)
{
    delete this->json;

    this->json = json;
}
