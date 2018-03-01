// gtest
#include <gtest/gtest.h>

// log
#include <log/include/AdministradorLog.h>

using namespace herramientas::log;

TEST(log, CrearEscribirYCerrar)
{
    Logger * logger = AdministradorLog::iniciarNuevo("log_testing.json");

    logger->marca("marca: se supone que se tiene que registrar.");
    logger->debug("debug: se supone que se tiene que registrar.");
    logger->info("info: se supone que se tiene que registrar.");
    logger->advertencia("advertencia: se supone que se tiene que registrar.");
    logger->error("error: se supone que se tiene que registrar.");
    logger->critico("critical: se supone que se tiene que registrar.");

    AdministradorLog::liberarTodo();
}

TEST(log, CrearDosIguales)
{
    Logger * logger = AdministradorLog::iniciarNuevo("log_testing.json");
    Logger * logger_duplicado = AdministradorLog::iniciarNuevo("log_testing.json");

    ASSERT_EQ(NULL, logger_duplicado);

    logger->marca("marca2: se supone que se tiene que registrar.");
    logger->debug("debug2: se supone que se tiene que registrar.");
    logger->info("info2: se supone que se tiene que registrar.");
    logger->advertencia("advertencia2: se supone que se tiene que registrar.");
    logger->error("error2: se supone que se tiene que registrar.");
    logger->critico("critical2: se supone que se tiene que registrar.");

    AdministradorLog::liberarTodo();
}


TEST(log, VariosLoggerAUnaMismaSalida)
{
    Logger * logger = AdministradorLog::iniciarNuevo("log_testing.json");
    Logger * logger_2 = AdministradorLog::iniciarNuevo("log_testing_2.json");

    logger->marca("logger1 marca: se supone que se tiene que registrar.");
    logger->debug("logger1 debug2: se supone que se tiene que registrar.");
    logger->info("logger1 info2: se supone que se tiene que registrar.");
    logger->advertencia("logger1 advertencia2: se supone que se tiene que registrar.");
    logger->error("logger1 error2: se supone que se tiene que registrar.");
    logger->critico("logger1 critical2: se supone que se tiene que registrar.");

    logger_2->marca("logger2 marca2: se supone que se tiene que registrar.");
    logger_2->debug("logger2 debug2: se supone que se tiene que registrar.");
    logger_2->info("logger2 info2: se supone que se tiene que registrar.");
    logger_2->advertencia("logger2 advertencia2: se supone que se tiene que registrar.");
    logger_2->error("logger2 error2: se supone que se tiene que registrar.");
    logger_2->critico("logger2 critical2: se supone que se tiene que registrar.");

    AdministradorLog::liberarTodo();
}