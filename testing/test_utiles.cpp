// gtest
#include <gtest/gtest.h>

// cpprestsdk
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/Json.h>

using namespace herramientas::utiles;

TEST(modelo, GettersYSettersJson)
{
    Json* json = new Json("{\"etiqueta\":\"primavera_2017\",\"contenido\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}, \"tweets\":[{\"id_tweet\":1},{\"id_tweet\":2},{\"id_tweet\":3}]}");

    std::string etiqueta = json->getAtributoValorString("etiqueta");

    Json* contenido = json->getAtributoValorJson("contenido");

    std::string json_original = contenido->jsonString();

    unsigned long long int id_periodo = contenido->getAtributoValorUint("id_periodo");
    unsigned long long int id_reporte = contenido->getAtributoValorUint("id_reporte");
    std::vector<unsigned long long int> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");
    std::vector<unsigned long long int> ids_medios = contenido->getAtributoArrayUint("ids_medios");
    std::vector<unsigned long long int> ids_secciones = contenido->getAtributoArrayUint("ids_secciones");
    std::vector<Json*> tweets = json->getAtributoArrayJson("tweets");

    std::string json_sin_modificar = contenido->jsonString();

    std::string json_tweets_1 = tweets[0]->jsonString();
    std::string json_tweets_2 = tweets[1]->jsonString();
    std::string json_tweets_3 = tweets[2]->jsonString();

    for (std::vector<Json*>::iterator it = tweets.begin(); it != tweets.end(); it++)
    {
        delete *it;
    }

    delete json;
    delete contenido;

    ASSERT_STREQ("primavera_2017", etiqueta.c_str());

    ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", json_original.c_str());

    ASSERT_STREQ("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}", json_sin_modificar.c_str());

    ASSERT_STREQ("{\"id_tweet\":1}", json_tweets_1.c_str());

    ASSERT_STREQ("{\"id_tweet\":2}", json_tweets_2.c_str());

    ASSERT_STREQ("{\"id_tweet\":3}", json_tweets_3.c_str());

    ASSERT_EQ(2, id_periodo);
    ASSERT_EQ(3, id_reporte);

    ASSERT_EQ(6, ids_conceptos[0]);
    ASSERT_EQ(10, ids_conceptos[1]);
    ASSERT_EQ(14, ids_conceptos[2]);

    ASSERT_EQ(15, ids_medios[0]);
    ASSERT_EQ(16, ids_medios[1]);

    ASSERT_EQ(17, ids_secciones[0]);
    ASSERT_EQ(18, ids_secciones[1]);
}

TEST(modelo, GettersYSettersJsonArray)
{
    Json* json = new Json("[{\"id_tweet\":1},{\"id_tweet\":2},{\"id_tweet\":3}]");

    std::vector<Json*> tweets = json->getAtributoArrayJson();

    std::string json_tweets_1 = tweets[0]->jsonString();
    std::string json_tweets_2 = tweets[1]->jsonString();
    std::string json_tweets_3 = tweets[2]->jsonString();
    
    for (std::vector<Json*>::iterator it = tweets.begin(); it != tweets.end(); it++)
    {
        delete *it;
    }

    delete json;

    ASSERT_STREQ("{\"id_tweet\":1}", json_tweets_1.c_str());

    ASSERT_STREQ("{\"id_tweet\":2}", json_tweets_2.c_str());

    ASSERT_STREQ("{\"id_tweet\":3}", json_tweets_3.c_str());
}


TEST(modelo, GettersYSettersCodificaciones)
{
//    ******** NOTA ********
//        cuando le pasamos al Json un code unit (codigo en formato unicode de la forma '\uXXXX'), rapidjson lo procesa internamente en formato UTF8, es decir que
//        lo traduce a sus caracteres correspondientes. Por eso cuando recuperamos un valor como String, en la posicion de codeunit vamos a ver la secuencia de caracteres
//        que corresponden al codeunit.
//        En este caso particular,
//        - '\u00e9' (que representa al caracter '�') se traduce como 'é' (C3 A9), y 
//        - '\u2026' (que representa al caracter '�') se traduce como '…' (E2 80 A6)
//
//        mas info:
//  https://r12a.github.io/apps/conversion/
//  http://www.weblogism.com/item/270/why-does-e-become-a
//  https://developer.twitter.com/en/docs/basics/counting-characters
//  http://rapidjson.org/md_doc_encoding.html

    std::string json_tweets = "{\"id_tweet\":\"Jerusal\\u00e9n: suenan sirenas de alarma en el sur de Israel tras el disparo de un cohete desde Gaza\\u2026 https:\/\/t.co\/eqSJm9AkQB\"}";

    Json* json = new Json(json_tweets);

    std::string json_tweets_1 = json->getAtributoValorString("id_tweet");

    delete json;

    std::string correcto = "Jerusalén: suenan sirenas de alarma en el sur de Israel tras el disparo de un cohete desde Gaza… https://t.co/eqSJm9AkQB";

    ASSERT_STREQ(correcto.c_str(), json_tweets_1.c_str());
}