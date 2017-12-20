// gtest
#include <gtest/gtest.h>

// cpprestsdk
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/Json.h>
#include <utiles/include/FuncionesString.h>

using namespace herramientas::utiles;

TEST(utiles, GettersYSettersJson)
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

TEST(utiles, GettersYSettersJsonArray)
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


TEST(utiles, GettersYSettersCodificaciones)
{
//    ******** NOTA ********
//        cuando le pasamos al Json un code unit (codigo en formato unicode de la forma '\uXXXX'), rapidjson lo procesa internamente en formato UTF8, es decir que
//        lo traduce a sus caracteres correspondientes. Por eso cuando recuperamos un valor como String, en la posicion de codeunit vamos a ver la secuencia de caracteres
//        que corresponden al codeunit.
//        En este caso particular,
//        - '\u00e9' (que representa al caracter 'é') se traduce como 'Ã©' (C3 A9), y 
//        - '\u2026' (que representa al caracter '…') se traduce como 'â€¦' (E2 80 A6)
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

    std::string correcto = "JerusalÃ©n: suenan sirenas de alarma en el sur de Israel tras el disparo de un cohete desde Gazaâ€¦ https://t.co/eqSJm9AkQB";

    ASSERT_STREQ(correcto.c_str(), json_tweets_1.c_str());
}

TEST(utiles, FuncionesStringSeparar)
{
    std::string string_a_separar_1 = "hola,como,estas,amigo";
    std::string string_a_separar_2 = "hola,como,estas,,amigo";
    std::string string_a_separar_3 = "hola,como,estas,amigo,";
    std::string string_a_separar_4 = ",hola,como,estas,amigo";
    std::string string_a_separar_5 = ",hola,como,estas,amigo,";

    std::string string_a_separar_6 = "0x00BE,¾,194 190,VULGAR FRACTION THREE QUARTERS,3/4";
    std::string string_a_separar_7 = "0x00E4,ä,195 164,LATIN SMALL LETTER A WITH DIAERESIS,a";
    std::string string_a_separar_8 = "0x00AB,«,194 171,LEFT-POINTING DOUBLE ANGLE QUOTATION MARK,<<";

    std::vector<std::string> tokens_1 = FuncionesString::separar(string_a_separar_1, ",");
    std::vector<std::string> tokens_2 = FuncionesString::separar(string_a_separar_2, ",");
    std::vector<std::string> tokens_3 = FuncionesString::separar(string_a_separar_3, ",");
    std::vector<std::string> tokens_4 = FuncionesString::separar(string_a_separar_4, ",");
    std::vector<std::string> tokens_5 = FuncionesString::separar(string_a_separar_5, ",");
    std::vector<std::string> tokens_6 = FuncionesString::separar(string_a_separar_6, ",");
    std::vector<std::string> tokens_7 = FuncionesString::separar(string_a_separar_7, ",");
    std::vector<std::string> tokens_8 = FuncionesString::separar(string_a_separar_8, ",");

    ASSERT_STREQ("amigo", tokens_1[3].c_str());
    ASSERT_STREQ("amigo", tokens_2[4].c_str());
    ASSERT_STREQ("amigo", tokens_3[3].c_str());
    ASSERT_STREQ("amigo", tokens_4[4].c_str());
    ASSERT_STREQ("amigo", tokens_5[4].c_str());

    ASSERT_STREQ("¾", tokens_6[1].c_str());
    ASSERT_STREQ("VULGAR FRACTION THREE QUARTERS", tokens_6[3].c_str());

    ASSERT_STREQ("ä", tokens_7[1].c_str());
    ASSERT_STREQ("LATIN SMALL LETTER A WITH DIAERESIS", tokens_7[3].c_str());

    ASSERT_STREQ("«", tokens_8[1].c_str());
    ASSERT_STREQ("LEFT-POINTING DOUBLE ANGLE QUOTATION MARK", tokens_8[3].c_str());
}

TEST(utiles, FuncionesStringReemplazarOcurrencias)
{
    std::string string_a_modificar = "el puerco esta en la pocilga.";

    unsigned int cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_a_modificar, "la pocilga", "el rebaño");

    ASSERT_EQ(1, cantidad_de_ocurrencias);
    ASSERT_STREQ("el puerco esta en el rebaño.", string_a_modificar.c_str());

    cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_a_modificar, "el", "un");

    ASSERT_EQ(2, cantidad_de_ocurrencias);
    ASSERT_STREQ("un puerco esta en un rebaño.", string_a_modificar.c_str());

    std::string string_utf8_a_modificar = u8"me tomo un café.";

    cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_utf8_a_modificar, u8"café", "cafe");

    ASSERT_EQ(1, cantidad_de_ocurrencias);
    ASSERT_STREQ("me tomo un cafe.", string_utf8_a_modificar.c_str());
}