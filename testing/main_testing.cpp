
#if defined(DEBUG) || defined(_DEBUG)
// vld
#include <vld.h>
#endif

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

int main(int argc, char **argv) {
    int result = Catch::Session().run(argc, argv);

	std::getchar();

	return result;
}