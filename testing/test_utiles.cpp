// stl
#include <filesystem>

// catch2
#include <catch.hpp>

// cpprestsdk
#include <cpprest/http_client.h>

// utiles
#include <utiles/include/Json.h>
#include <utiles/include/FuncionesString.h>
#include <utiles/include/Fecha.h>
#include <utiles/include/ID.h>
#include <utiles/include/GestorIDs.h>
#include <utiles/include/Stemming.h>
#include <utiles/include/csv.h>

using namespace herramientas::utiles;

TEST_CASE("getters_y_setters_json", "utiles") {
    Json* json = new Json("{\"etiqueta\":\"primavera_2017\",\"contenido\":{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]},\"tweets\":[{\"id_tweet\":1},{\"id_tweet\":2},{\"id_tweet\":3}]}");

    std::string etiqueta = json->getAtributoValorString("etiqueta");

    Json* contenido = json->getAtributoValorJson("contenido");
    
    std::string json_original = contenido->jsonString();

    float peso_nuevo = 3.45674345f;
    contenido->agregarAtributoValor("peso", peso_nuevo);
    contenido->agregarAtributoValor("es_retweet", true);

    uint64_t id_periodo = contenido->getAtributoValorUint("id_periodo");
    uint64_t id_reporte = contenido->getAtributoValorUint("id_reporte");
    std::vector<uint64_t> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");
    std::vector<uint64_t> ids_medios = contenido->getAtributoArrayUint("ids_medios");
    std::vector<uint64_t> ids_secciones = contenido->getAtributoArrayUint("ids_secciones");
    std::vector<Json*> tweets = json->getAtributoArrayJson("tweets");
    float peso = contenido->getAtributoValorFloat("peso");
    bool es_retweet = contenido->getAtributoValorBool("es_retweet");

    bool no_existe = contenido->contieneAtributo("atributo-inexistente");
    bool existe = contenido->contieneAtributo("es_retweet");
    bool es_array = contenido->esArray();

    bool excepcion_atrapada = false;
    try
    {
        contenido->getAtributoValorBool("atributo-inexistente");
    }
    catch (excepciones::JsonNoExisteClave & e)
    {
        excepcion_atrapada = true;
    }

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

    REQUIRE(true == existe);
    REQUIRE(false == no_existe);
    REQUIRE(false == es_array);
    REQUIRE(true == excepcion_atrapada);

    REQUIRE("primavera_2017" == etiqueta.c_str());

    REQUIRE(peso_nuevo == peso);

    REQUIRE("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18]}" == json_original.c_str());

    REQUIRE("{\"id_periodo\":2,\"id_reporte\":3,\"ids_conceptos\":[6,10,14],\"ids_medios\":[15,16],\"ids_secciones\":[17,18],\"peso\":3.4567,\"es_retweet\":true}" == json_sin_modificar.c_str());

    REQUIRE("{\"id_tweet\":1}" == json_tweets_1.c_str());

    REQUIRE("{\"id_tweet\":2}" == json_tweets_2.c_str());

    REQUIRE("{\"id_tweet\":3}" == json_tweets_3.c_str());

    REQUIRE(2 == id_periodo);
    REQUIRE(3 == id_reporte);

    REQUIRE(6 == ids_conceptos[0]);
    REQUIRE(10 == ids_conceptos[1]);
    REQUIRE(14 == ids_conceptos[2]);

    REQUIRE(15 == ids_medios[0]);
    REQUIRE(16 == ids_medios[1]);

    REQUIRE(17 == ids_secciones[0]);
    REQUIRE(18 == ids_secciones[1]);
}

TEST_CASE("getters_y_setters_json_array", "utiles") {
    Json* json = new Json("[{\"id_tweet\":1},{\"id_tweet\":2},{\"id_tweet\":3}]");

    bool es_array = json->esArray();

    std::vector<Json*> tweets = json->getAtributoArrayJson();

    std::string json_tweets_1 = tweets[0]->jsonString();
    std::string json_tweets_2 = tweets[1]->jsonString();
    std::string json_tweets_3 = tweets[2]->jsonString();
    
    for (std::vector<Json*>::iterator it = tweets.begin(); it != tweets.end(); it++)
    {
        delete *it;
    }

    delete json;

    tweets.clear();

    REQUIRE(true == es_array);

    REQUIRE("{\"id_tweet\":1}" == json_tweets_1.c_str());

    REQUIRE("{\"id_tweet\":2}" == json_tweets_2.c_str());

    REQUIRE("{\"id_tweet\":3}" == json_tweets_3.c_str());

    Json * json_1 = new Json("{\"id_tweet\":1}");
    Json * json_2 = new Json("{\"id_tweet\":2}");
    Json * json_3 = new Json("{\"id_tweet\":3}");

    tweets.push_back(json_1);
    tweets.push_back(json_2);
    tweets.push_back(json_3);

    Json * json_array = new Json();

    json_array->agregarAtributoArray("tweets", tweets);

    bool atributo_es_array = json_array->esArray("tweets");
    bool no_es_array = json_array->esArray();

    bool excepcion_no_es_array = false;
    try
    {
        json_1->getAtributoArrayString("id_tweet");
    }
    catch (excepciones::JsonNoEsArray & e)
    {
        excepcion_no_es_array = true;
    }

    bool excepcion_no_existe_array = false;
    try
    {
        json_array->getAtributoArrayString("no-es-array");
    }
    catch (excepciones::JsonNoExisteClave & e)
    {
        excepcion_no_existe_array = true;
    }

    REQUIRE(true == atributo_es_array);
    REQUIRE(false == no_es_array);

    REQUIRE(true == excepcion_no_es_array);
    REQUIRE(true == excepcion_no_existe_array);

    REQUIRE("{\"tweets\":[{\"id_tweet\":1},{\"id_tweet\":2},{\"id_tweet\":3}]}" == json_array->jsonString());

    delete json_1;
    delete json_2;
    delete json_3;

    delete json_array;
}

TEST_CASE("getters_y_setters_codificaciones", "utiles") {

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

    REQUIRE(correcto == json_tweets_1);
}

TEST_CASE("string_unir", "utiles") {
    std::vector<std::string> strings_a_unir_vacio;
    std::vector<std::string> strings_a_unir_1 = { "" };
    std::vector<std::string> strings_a_unir_2 = { "", "" };
    std::vector<std::string> strings_a_unir_3 = { "hola" };
    std::vector<std::string> strings_a_unir_4 = { "hola", "como", "estas", "amigo" };


    std::string string_unido_1 = FuncionesString::unir(strings_a_unir_1, ", ");
    std::string string_unido_2 = FuncionesString::unir(strings_a_unir_2, ", ");
    std::string string_unido_3 = FuncionesString::unir(strings_a_unir_3, ", ");
    std::string string_unido_4 = FuncionesString::unir(strings_a_unir_4, "; ");
    std::string string_unido_5 = FuncionesString::unir(strings_a_unir_4);
    std::string string_unido_vacio = FuncionesString::unir(strings_a_unir_vacio, "; ");

    REQUIRE("" == string_unido_vacio);
    REQUIRE("" == string_unido_1);
    REQUIRE(", " == string_unido_2);
    REQUIRE("hola" == string_unido_3);
    REQUIRE("hola; como; estas; amigo" == string_unido_4);
    REQUIRE("holacomoestasamigo" == string_unido_5);
}

TEST_CASE("string_separar", "utiles") {
    std::string string_a_separar_1 = "hola,como,estas,amigo";
    std::string string_a_separar_2 = "hola,como,estas,,amigo";
    std::string string_a_separar_3 = "hola,como,estas,amigo,";
    std::string string_a_separar_4 = ",hola,como,estas,amigo";
    std::string string_a_separar_5 = ",hola,como,estas,amigo,";

    std::string string_a_separar_6 = "0x00BE,�,194 190,VULGAR FRACTION THREE QUARTERS,3/4";
    std::string string_a_separar_7 = "0x00E4,�,195 164,LATIN SMALL LETTER A WITH DIAERESIS,a";
    std::string string_a_separar_8 = "0x00AB,�,194 171,LEFT-POINTING DOUBLE ANGLE QUOTATION MARK,<<";

    std::vector<std::string> tokens_1 = FuncionesString::separar(string_a_separar_1, ",");
    std::vector<std::string> tokens_2 = FuncionesString::separar(string_a_separar_2, ",");
    std::vector<std::string> tokens_3 = FuncionesString::separar(string_a_separar_3, ",");
    std::vector<std::string> tokens_4 = FuncionesString::separar(string_a_separar_4, ",");
    std::vector<std::string> tokens_5 = FuncionesString::separar(string_a_separar_5, ",");
    std::vector<std::string> tokens_6 = FuncionesString::separar(string_a_separar_6, ",");
    std::vector<std::string> tokens_7 = FuncionesString::separar(string_a_separar_7, ",");
    std::vector<std::string> tokens_8 = FuncionesString::separar(string_a_separar_8, ",");

    REQUIRE("amigo" == tokens_1[3].c_str());
    REQUIRE("amigo" == tokens_2[4].c_str());
    REQUIRE("amigo" == tokens_3[3].c_str());
    REQUIRE("amigo" == tokens_4[4].c_str());
    REQUIRE("amigo" == tokens_5[4].c_str());

    REQUIRE("�" == tokens_6[1].c_str());
    REQUIRE("VULGAR FRACTION THREE QUARTERS" == tokens_6[3].c_str());

    REQUIRE("�" == tokens_7[1].c_str());
    REQUIRE("LATIN SMALL LETTER A WITH DIAERESIS" == tokens_7[3].c_str());

    REQUIRE("�" == tokens_8[1].c_str());
    REQUIRE("LEFT-POINTING DOUBLE ANGLE QUOTATION MARK" == tokens_8[3].c_str());
}

TEST_CASE("string_reemplazar", "utiles") {
    std::string string_a_modificar = "el puerco esta en la pocilga.";

    uint32_t cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_a_modificar, "la pocilga", "el reba�o");

    REQUIRE(1 == cantidad_de_ocurrencias);
    REQUIRE("el puerco esta en el reba�o." == string_a_modificar.c_str());

    cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_a_modificar, "el", "un");

    REQUIRE(2 == cantidad_de_ocurrencias);
    REQUIRE("un puerco esta en un reba�o." == string_a_modificar.c_str());

    std::string string_utf8_a_modificar = u8"me tomo un caf�.";

    cantidad_de_ocurrencias = FuncionesString::reemplazarOcurrencias(string_utf8_a_modificar, u8"�", "e");

    REQUIRE(1 == cantidad_de_ocurrencias);
    REQUIRE("me tomo un cafe." == string_utf8_a_modificar.c_str());
}

TEST_CASE("string_eliminar", "utiles") {
    std::string string_a_modificar = "el puerco esta en el barro.";

    uint32_t cantidad_de_ocurrencias = FuncionesString::eliminarOcurrencias(string_a_modificar, " barro");

    REQUIRE(1 == cantidad_de_ocurrencias);
    REQUIRE("el puerco esta en el." == string_a_modificar.c_str());

    cantidad_de_ocurrencias = FuncionesString::eliminarOcurrencias(string_a_modificar, "el");

    REQUIRE(2 == cantidad_de_ocurrencias);
    REQUIRE(" puerco esta en ." == string_a_modificar.c_str());

    std::string string_utf8_a_modificar = u8"me tomo un caf�.";

    cantidad_de_ocurrencias = FuncionesString::eliminarOcurrencias(string_utf8_a_modificar, u8" caf�");

    REQUIRE(1 == cantidad_de_ocurrencias);
    REQUIRE("me tomo un." == string_utf8_a_modificar.c_str());
}

TEST_CASE("string_minuscula", "utiles") {
    std::string oracion_con_mayusculas = "Hab�a uNa veZ un Caf� qUE uSaBa UnA c�mArA CoN MuChA EmOCi�n.";
    std::string oracion_sin_mayusculas = "hab�a una vez un caf� que usaba una c�mara con mucha emoci�n.";

    FuncionesString::todoMinuscula(oracion_con_mayusculas);

    REQUIRE(oracion_sin_mayusculas == oracion_con_mayusculas);
}

TEST_CASE("string_eliminar_signos_y_puntuacion", "utiles") {
    std::string oracion_con_simbolos_no_caracteres = "y matori dijo: \"me quedan $20,35.-\". habia (mal)gastado el premio -que no habia ganado- en un monton de m&m y demas basuras.";
    std::string oracion_sin_simbolos_no_caracteres = "y matori dijo me quedan 20 35 habia mal gastado el premio que no habia ganado en un monton de m m y demas basuras ";

    FuncionesString::eliminarSignosYPuntuacion(oracion_con_simbolos_no_caracteres);

    REQUIRE(oracion_con_simbolos_no_caracteres == oracion_sin_simbolos_no_caracteres);

    oracion_con_simbolos_no_caracteres = "y matori dijo: \"me quedan $20,35.-\". habia (mal)gastado el premio -que no habia ganado- en un monton de m&m y demas basuras.";
    oracion_sin_simbolos_no_caracteres = "y matori dijo: me quedan 20 35 - habia mal gastado el premio -que no habia ganado- en un monton de m m y demas basuras ";

    FuncionesString::eliminarSignosYPuntuacion(oracion_con_simbolos_no_caracteres, {"-", ":"});

    REQUIRE(oracion_con_simbolos_no_caracteres == oracion_sin_simbolos_no_caracteres);
}

TEST_CASE("string_eliminar_caracteres_control", "utiles") {
    std::string string_a_modificar = "\tel puerco esta en el barro.\nel zorro no sabe donde ir.\rel pato hace cuak.\a";
    std::string string_modificado = " el puerco esta en el barro. el zorro no sabe donde ir. el pato hace cuak. ";

    uint32_t cantidad_de_caracteres_de_control_eliminados = FuncionesString::eliminarCaracteresDeControl(string_a_modificar);
    
    REQUIRE(4 == cantidad_de_caracteres_de_control_eliminados);
    REQUIRE(string_modificado == string_a_modificar);
}

TEST_CASE("string_eliminar_espacios_redundantes", "utiles") {
    std::string string_a_modificar = "   el      puerco    esta en    el barro.     el zorro   no     sabe   donde  ir.   el    pato  hace   cuak.     ";
    std::string string_modificado = " el puerco esta en el barro. el zorro no sabe donde ir. el pato hace cuak. ";

    uint32_t cantidad_de_espacios_redundantes_eliminados = FuncionesString::eliminarEspaciosRedundantes(string_a_modificar);

    REQUIRE(38 == cantidad_de_espacios_redundantes_eliminados);
    REQUIRE(string_modificado == string_a_modificar);
}

TEST_CASE("string_empieza_con", "utiles") {
    std::string string_a_consultar = "hola como estas?";
    std::string string_a_buscar = "hola com";

    REQUIRE(true == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));

    string_a_buscar = "chau";

    REQUIRE(false == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));

    string_a_buscar = "como";

    REQUIRE(false == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));

    string_a_buscar = "como estas?";

    REQUIRE(false == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));

    string_a_buscar = "hola como estas?";

    REQUIRE(true == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));

    string_a_buscar = "hola como estas? todo bien?";

    REQUIRE(false == FuncionesString::empiezaCon(string_a_consultar, string_a_buscar));
}

TEST_CASE("string_convertir", "utiles") {
    double numero = 12345.6789101112;
    std::string string_numero_dos_decimales = "12345.68";
    std::string string_numero_cuatro_decimales = "12345.6789";

    REQUIRE(string_numero_dos_decimales == FuncionesString::toString(numero));
    REQUIRE(string_numero_cuatro_decimales == FuncionesString::toString(numero, 4));
}

TEST_CASE("fecha_parsear", "utiles") {
    std::string fecha_formato_rss("Wed, 20 Jun 2018 19:06:46 +0000");
    std::string fecha_formato_atom("2018-06-20T18:46:00-03:00");

    Fecha fecha_rss, fecha_atom;

    Fecha::parsear(fecha_formato_rss, "%a, %d %b %Y %H:%M:%S", &fecha_rss);
    Fecha::parsear(fecha_formato_atom, "%Y-%m-%dT%H:%M:%S", &fecha_atom);

    REQUIRE(2018 == fecha_rss.getAnio());
    REQUIRE(06 == fecha_rss.getMes());
    REQUIRE(20 == fecha_rss.getDia());
    REQUIRE(19 == fecha_rss.getHoras());
    REQUIRE(06 == fecha_rss.getMinutos());
    REQUIRE(46 == fecha_rss.getSegundos());

    REQUIRE(2018 == fecha_atom.getAnio());
    REQUIRE(06 == fecha_atom.getMes());
    REQUIRE(20 == fecha_atom.getDia());
    REQUIRE(18 == fecha_atom.getHoras());
    REQUIRE(46 == fecha_atom.getMinutos());
    REQUIRE(00 == fecha_atom.getSegundos());
}

TEST_CASE("fecha_parsear_AAAAMMDD", "utiles") {
    std::string string_fecha_sin_separador = "20180102";
    std::string string_fecha_con_separador = "2018 01 02";
    std::string string_fecha_invalida = "2018 14 02";

    Fecha fecha_sin_separador = Fecha::parsearFormatoAAAAMMDD(string_fecha_sin_separador);
    Fecha fecha_con_separador = Fecha::parsearFormatoAAAAMMDD(string_fecha_con_separador, " ");
    Fecha fecha_invalida = Fecha::parsearFormatoAAAAMMDD(string_fecha_invalida, " ");

    REQUIRE(2018 == fecha_sin_separador.getAnio());
    REQUIRE(2018 == fecha_con_separador.getAnio());
    REQUIRE(0 == fecha_invalida.getAnio());

    REQUIRE(01 == fecha_sin_separador.getMes());
    REQUIRE(01 == fecha_con_separador.getMes());
    REQUIRE(0 == fecha_invalida.getMes());

    REQUIRE(02 == fecha_sin_separador.getDia());
    REQUIRE(02 == fecha_con_separador.getDia());
    REQUIRE(0 == fecha_invalida.getDia());
}

TEST_CASE("fecha_parsear_AAAAMMDDHHmmSS", "utiles") {
    std::string string_fecha_sin_separador = "20180102235959";
    std::string string_fecha_con_separador = "2018 01 02-22:58:57";
    std::string string_fecha_invalida = "2018 12 0224-60-59";

    Fecha fecha_sin_separador = Fecha::parsearFormatoAAAAMMDDHHmmSS(string_fecha_sin_separador);
    Fecha fecha_con_separador = Fecha::parsearFormatoAAAAMMDDHHmmSS(string_fecha_con_separador, " ", "-", ":");
    Fecha fecha_invalida = Fecha::parsearFormatoAAAAMMDDHHmmSS(string_fecha_invalida, " ", "", "-");

    REQUIRE(2018 == fecha_sin_separador.getAnio());
    REQUIRE(2018 == fecha_con_separador.getAnio());
    REQUIRE(23 == fecha_sin_separador.getHoras());
    REQUIRE(22 == fecha_con_separador.getHoras());
    REQUIRE(0 == fecha_invalida.getAnio());

    REQUIRE(01 == fecha_sin_separador.getMes());
    REQUIRE(01 == fecha_con_separador.getMes());
    REQUIRE(59 == fecha_sin_separador.getMinutos());
    REQUIRE(58 == fecha_con_separador.getMinutos());
    REQUIRE(0 == fecha_invalida.getMes());

    REQUIRE(02 == fecha_sin_separador.getDia());
    REQUIRE(02 == fecha_con_separador.getDia());
    REQUIRE(59 == fecha_sin_separador.getSegundos());
    REQUIRE(57 == fecha_con_separador.getSegundos());
    REQUIRE(0 == fecha_invalida.getDia());
}

TEST_CASE("fecha_parsear_DDmesAAAA", "utiles") {
    std::string string_fecha_sin_separador_1 = "02enero2018";
    std::string string_fecha_sin_separador_2 = "02diciembre2018";
    std::string string_fecha_con_separador = "02 enero 2018";
    std::string string_fecha_invalida = "02 roberto 2018";

    Fecha fecha_sin_separador_1 = Fecha::parsearFormatoDDmesAAAA(string_fecha_sin_separador_1);
    Fecha fecha_sin_separador_2 = Fecha::parsearFormatoDDmesAAAA(string_fecha_sin_separador_2);
    Fecha fecha_con_separador = Fecha::parsearFormatoDDmesAAAA(string_fecha_con_separador, " ");
    Fecha fecha_invalida = Fecha::parsearFormatoDDmesAAAA(string_fecha_invalida, " ");

    REQUIRE(2018 == fecha_sin_separador_1.getAnio());
    REQUIRE(2018 == fecha_sin_separador_2.getAnio());
    REQUIRE(2018 == fecha_con_separador.getAnio());
    REQUIRE(0 == fecha_invalida.getAnio());

    REQUIRE(01 == fecha_sin_separador_1.getMes());
    REQUIRE(12 == fecha_sin_separador_2.getMes());
    REQUIRE(01 == fecha_con_separador.getMes());
    REQUIRE(0 == fecha_invalida.getMes());

    REQUIRE(02 == fecha_sin_separador_1.getDia());
    REQUIRE(02 == fecha_sin_separador_2.getDia());
    REQUIRE(02 == fecha_con_separador.getDia());
    REQUIRE(0 == fecha_invalida.getDia());
}

TEST_CASE("fecha_parsear_DDMMAAAA", "utiles") {
    std::string string_fecha_sin_separador = "02012018";
    std::string string_fecha_con_separador = "02 01 2018";
    std::string string_fecha_invalida = "33 01 2018";

    Fecha fecha_sin_separador = Fecha::parsearFormatoDDMMAAAA(string_fecha_sin_separador);
    Fecha fecha_con_separador = Fecha::parsearFormatoDDMMAAAA(string_fecha_con_separador, " ");
    Fecha fecha_invalida = Fecha::parsearFormatoDDMMAAAA(string_fecha_invalida, " ");

    REQUIRE(2018 == fecha_sin_separador.getAnio());
    REQUIRE(2018 == fecha_con_separador.getAnio());
    REQUIRE(0 == fecha_invalida.getAnio());

    REQUIRE(01 == fecha_sin_separador.getMes());
    REQUIRE(01 == fecha_con_separador.getMes());
    REQUIRE(0 == fecha_invalida.getMes());

    REQUIRE(02 == fecha_sin_separador.getDia());
    REQUIRE(02 == fecha_con_separador.getDia());
    REQUIRE(0 == fecha_invalida.getDia());
}

TEST_CASE("fecha_restar_y_sumar_tiempos", "utiles") {
    Fecha fecha_1(10, 2, 2018, 20, 40, 50);
    Fecha fecha_2(1, 1, 2018, 0, 0, 0);

    std::chrono::hours dos_horas(2);
    std::chrono::minutes dos_minutos(2);
    std::chrono::seconds dos_segundos(2);

    fecha_1 -= dos_horas;
    fecha_1 -= dos_minutos;
    fecha_1 -= dos_segundos;

    REQUIRE(18 == fecha_1.getHoras());
    REQUIRE(38 == fecha_1.getMinutos());
    REQUIRE(48 == fecha_1.getSegundos());

    fecha_1 += dos_horas;
    fecha_1 += dos_minutos;
    fecha_1 += dos_segundos;

    REQUIRE(20 == fecha_1.getHoras());
    REQUIRE(40 == fecha_1.getMinutos());
    REQUIRE(50 == fecha_1.getSegundos());

    fecha_2 -= dos_segundos;

    REQUIRE(2017 == fecha_2.getAnio());
    REQUIRE(12 == fecha_2.getMes());
    REQUIRE(31 == fecha_2.getDia());
    REQUIRE(23 == fecha_2.getHoras());
    REQUIRE(59 == fecha_2.getMinutos());
    REQUIRE(58 == fecha_2.getSegundos());

    fecha_2 += dos_segundos;

    REQUIRE(2018 == fecha_2.getAnio());
    REQUIRE(1 == fecha_2.getMes());
    REQUIRE(1 == fecha_2.getDia());
    REQUIRE(0 == fecha_2.getHoras());
    REQUIRE(0 == fecha_2.getMinutos());
    REQUIRE(0 == fecha_2.getSegundos());
}

TEST_CASE("fecha_armar_AAAAMMDD", "utiles") {
    Fecha fecha_1(1, 2, 2018);
    Fecha fecha_2(10, 2, 2018);
    Fecha fecha_3(1, 12, 2018);
    Fecha fecha_4(10, 12, 2018);

    REQUIRE("20180201" == fecha_1.getStringAAAAMMDD());
    REQUIRE("20180210" == fecha_2.getStringAAAAMMDD());
    REQUIRE("20181201" == fecha_3.getStringAAAAMMDD());
    REQUIRE("20181210" == fecha_4.getStringAAAAMMDD());
}

TEST_CASE("fecha_armar_AAAAMMDDHHmmSS", "utiles") {
    Fecha fecha_1(1, 2, 2018, 23, 59, 59);
    Fecha fecha_2(10, 2, 2018, 00, 00, 00);
    Fecha fecha_3(1, 12, 2018, 12, 13, 14);
    Fecha fecha_4(10, 12, 2018, 14, 13, 12);

    REQUIRE("20180201235959" == fecha_1.getStringAAAAMMDDHHmmSS());
    REQUIRE("20180210000000" == fecha_2.getStringAAAAMMDDHHmmSS());
    REQUIRE("20181201121314" == fecha_3.getStringAAAAMMDDHHmmSS());
    REQUIRE("20181210141312" == fecha_4.getStringAAAAMMDDHHmmSS());
}

TEST_CASE("fecha_armar_DDmesAAAA", "utiles") {
    Fecha fecha_1(1, 2, 2018);
    Fecha fecha_2(10, 2, 2018);
    Fecha fecha_3(1, 12, 2018);
    Fecha fecha_4(10, 12, 2018);

    REQUIRE("01febrero2018" == fecha_1.getStringDDmesAAAA());
    REQUIRE("10febrero2018" == fecha_2.getStringDDmesAAAA());
    REQUIRE("01diciembre2018" == fecha_3.getStringDDmesAAAA());
    REQUIRE("10diciembre2018" == fecha_4.getStringDDmesAAAA());
}

TEST_CASE("fecha_armar_DDMMAAAA", "utiles") {
    Fecha fecha_1(1, 2, 2018);
    Fecha fecha_2(10, 2, 2018);
    Fecha fecha_3(1, 12, 2018);
    Fecha fecha_4(10, 12, 2018);

    REQUIRE("01022018" == fecha_1.getStringDDMMAAAA());
    REQUIRE("10022018" == fecha_2.getStringDDMMAAAA());
    REQUIRE("01122018" == fecha_3.getStringDDMMAAAA());
    REQUIRE("10122018" == fecha_4.getStringDDMMAAAA());
}

TEST_CASE("fecha_operadores_sobrecargados", "utiles") {
    Fecha fecha_1(1, 1, 2018, 23, 59, 59);
    Fecha fecha_2(1, 1, 2018, 23, 59 ,59);
    Fecha fecha_3(1, 1, 2017, 23, 59, 59);
    Fecha fecha_4(1, 1, 2017, 22, 59, 59);

    REQUIRE(true == (fecha_1 == fecha_2));
    REQUIRE(false == (fecha_1 != fecha_2));
    REQUIRE(true == fecha_1 <= fecha_2);
    REQUIRE(true == fecha_1 >= fecha_2);
    REQUIRE(false == fecha_1 < fecha_2);
    REQUIRE(false == fecha_1 > fecha_2);

    REQUIRE(false == (fecha_1 == fecha_3));
    REQUIRE(true == (fecha_1 != fecha_3));
    REQUIRE(false == fecha_1 <= fecha_3);
    REQUIRE(true == fecha_1 >= fecha_3);
    REQUIRE(false == fecha_1 < fecha_3);
    REQUIRE(true == fecha_1 > fecha_3);

    REQUIRE(false == fecha_3 <= fecha_4);
    REQUIRE(true == fecha_3 >= fecha_4);
    REQUIRE(false == fecha_3 < fecha_4);
    REQUIRE(true == fecha_3 > fecha_4);
}

TEST_CASE("asignacion_ids", "utiles") {
    GestorIDs gestor_ids;

    uint64_t id_actual = gestor_ids.getIdActual();

    REQUIRE(1 == id_actual);

    ID * id_1 = gestor_ids.nuevoID();
    ID * id_2 = gestor_ids.nuevoID();

    REQUIRE(1 == id_1->numero());
    REQUIRE("1" == id_1->string());

    REQUIRE(2 == id_2->numero());
    REQUIRE("2" == id_2->string());

    id_actual = gestor_ids.getIdActual();

    REQUIRE(3 == id_actual);

    gestor_ids.setIdActual(150);

    id_actual = gestor_ids.getIdActual();

    REQUIRE(150 == id_actual);

    ID * id_3 = gestor_ids.nuevoID();
    ID * id_4 = gestor_ids.nuevoID();

    REQUIRE(150 == id_3->numero());
    REQUIRE("150" == id_3->string());

    REQUIRE(151 == id_4->numero());
    REQUIRE("151" == id_4->string());

    delete id_1;
    delete id_2;
    delete id_3;
    delete id_4;
}

TEST_CASE("steeming", "utiles") {
    std::string palabra_a_stemmear_1 = "continuaci�n";
    std::string palabra_a_stemmear_2 = "continuar�";
    std::string palabra_a_stemmear_3 = "continua";
    std::string palabra_a_stemmear_4 = "continuamiento";

    std::vector<std::string> palabras_a_stemmear_1 = { palabra_a_stemmear_1, palabra_a_stemmear_2, palabra_a_stemmear_3, palabra_a_stemmear_4 };

    std::string palabra_a_stemmear_5 = "transporte";
    std::string palabra_a_stemmear_6 = "transportaci�n";
    std::string palabra_a_stemmear_7 = "transportar";
    std::string palabra_a_stemmear_8 = "transportamiento";

    std::string aborto = "aborto";
    Stemming::stem(aborto);

    std::string podemos = "podemos";
    Stemming::stem(podemos);

    std::string kirchnerismo = "kirchnerismo";
    Stemming::stem(kirchnerismo);

    std::string cambiemos = "cambiemos";
    Stemming::stem(cambiemos);

    std::string perez = "perez";
    Stemming::stem(perez);

    std::string macri = "macri";
    Stemming::stem(macri);

    std::string vidal = "vidal";
    Stemming::stem(vidal);

    std::string vida = "vida";
    Stemming::stem(vida);

    std::string video = "video";
    Stemming::stem(video);

    std::vector<std::string> palabras_a_stemmear_2 = { palabra_a_stemmear_5, palabra_a_stemmear_6, palabra_a_stemmear_7, palabra_a_stemmear_8 };

    Stemming::stem(palabra_a_stemmear_1);
    Stemming::stem(palabra_a_stemmear_2);
    Stemming::stem(palabra_a_stemmear_3);
    Stemming::stem(palabra_a_stemmear_4);

    Stemming::stem(palabras_a_stemmear_1);

    Stemming::stem(palabra_a_stemmear_5);
    Stemming::stem(palabra_a_stemmear_6);
    Stemming::stem(palabra_a_stemmear_7);
    Stemming::stem(palabra_a_stemmear_8);

    Stemming::stem(palabras_a_stemmear_2);

    REQUIRE(palabra_a_stemmear_1 == "continu");
    REQUIRE(palabra_a_stemmear_2 == "continu");
    REQUIRE(palabra_a_stemmear_3 == "continu");
    REQUIRE(palabra_a_stemmear_4 == "continu");

    for (std::vector<std::string>::iterator it = palabras_a_stemmear_1.begin(); it != palabras_a_stemmear_1.end(); it++)
    {
        REQUIRE(*it == "continu");
    }

    REQUIRE(palabra_a_stemmear_5 == "transport");
    REQUIRE(palabra_a_stemmear_6 == "transport");
    REQUIRE(palabra_a_stemmear_7 == "transport");
    REQUIRE(palabra_a_stemmear_8 == "transport");
    
    for (std::vector<std::string>::iterator it = palabras_a_stemmear_2.begin(); it != palabras_a_stemmear_2.end(); it++)
    {
        REQUIRE(*it == "transport");
    }
}

TEST_CASE("stemming_utf8", "utiles") {
    std::string palabra_a_stemmear_1 = u8"continuaci�n";
    std::string palabra_a_stemmear_2 = u8"continuar�";
    std::string palabra_a_stemmear_3 = u8"continua";
    std::string palabra_a_stemmear_4 = u8"continuamiento";

    std::vector<std::string> palabras_a_stemmear_1 = { palabra_a_stemmear_1, palabra_a_stemmear_2, palabra_a_stemmear_3, palabra_a_stemmear_4 };

    std::string palabra_a_stemmear_5 = u8"transporte";
    std::string palabra_a_stemmear_6 = u8"transportaci�n";
    std::string palabra_a_stemmear_7 = u8"transportar";
    std::string palabra_a_stemmear_8 = u8"transportamiento";

    std::vector<std::string> palabras_a_stemmear_2 = { palabra_a_stemmear_5, palabra_a_stemmear_6, palabra_a_stemmear_7, palabra_a_stemmear_8 };

    Stemming::stemUTF8(palabra_a_stemmear_1);
    Stemming::stemUTF8(palabra_a_stemmear_2);
    Stemming::stemUTF8(palabra_a_stemmear_3);
    Stemming::stemUTF8(palabra_a_stemmear_4);

    Stemming::stemUTF8(palabras_a_stemmear_1);

    Stemming::stemUTF8(palabra_a_stemmear_5);
    Stemming::stemUTF8(palabra_a_stemmear_6);
    Stemming::stemUTF8(palabra_a_stemmear_7);
    Stemming::stemUTF8(palabra_a_stemmear_8);

    Stemming::stemUTF8(palabras_a_stemmear_2);

    REQUIRE(palabra_a_stemmear_1 == "continu");
    REQUIRE(palabra_a_stemmear_2 == "continu");
    REQUIRE(palabra_a_stemmear_3 == "continu");
    REQUIRE(palabra_a_stemmear_4 == "continu");

    for (std::vector<std::string>::iterator it = palabras_a_stemmear_1.begin(); it != palabras_a_stemmear_1.end(); it++)
    {
        REQUIRE(*it == "continu");
    }

    REQUIRE(palabra_a_stemmear_5 == "transport");
    REQUIRE(palabra_a_stemmear_6 == "transport");
    REQUIRE(palabra_a_stemmear_7 == "transport");
    REQUIRE(palabra_a_stemmear_8 == "transport");

    for (std::vector<std::string>::iterator it = palabras_a_stemmear_2.begin(); it != palabras_a_stemmear_2.end(); it++)
    {
        REQUIRE(*it == "transport");
    }
}

TEST_CASE("sumar_csv", "utiles") {
    herramientas::utiles::csv doc({ "columna1", "columna2", "columna3" });
    doc.agregar({ "item11", "item12", "item13" });
    doc.agregar({ "item21", "item22", "item23" });
    doc.agregar({ "item31", "item32", "item33" });
    doc.agregar({ "item41", "item42", "item43" });

    herramientas::utiles::csv doc2({ "columna1", "columna2", "columna3" });
    doc2.agregar({ "item51", "item52", "item53" });
    doc2.agregar({ "item61", "item62", "item63" });
    doc2.agregar({ "item71", "item72", "item73" });
    doc2.agregar({ "item81", "item82", "item83" });

    doc += doc2;

    REQUIRE( 8 == doc.filas().size() );
}

TEST_CASE("exportar_csv", "utiles") {
    herramientas::utiles::csv doc({"columna1", "columna2", "columna3"});

    doc.agregar({ "item11", "item12", "item13" });
    doc.agregar({ "item21", "item22", "item23" });
    doc.agregar({ "item31", "item32", "item33" });
    doc.agregar({ "item41", "item42", "item43" });

    std::ofstream salida("test.csv");
    doc.exportar(salida);

    std::experimental::filesystem::remove("test.csv");
}