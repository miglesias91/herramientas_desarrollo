#include <utiles/include/IContieneJson.h>

using namespace herramientas::utiles;

IContieneJson::IContieneJson(Json * json) : json(json)
{
}

IContieneJson::~IContieneJson()
{
    delete this->json;
    this->json = NULL;
}

Json * IContieneJson::getJson()
{
    return this->json;
}

void IContieneJson::setJson(Json * json)
{
    delete this->json;

    this->json = json;
}
