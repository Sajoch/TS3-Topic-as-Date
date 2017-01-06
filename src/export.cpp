#include <stdint.h>
#include "export.hpp"
#include "main.hpp"

TS3Functions ts3Functions;

extern "C" {
	const char* ts3plugin_name() {
		return "Topic as Date";
	}

	const char* ts3plugin_version() {
		return "1.0";
	}

	int ts3plugin_apiVersion() {
		return 21;
	}

	const char* ts3plugin_author() {
		return "Sajoch";
	}

	const char* ts3plugin_description() {
		return "When you connect to a server, then plugin set topic as current date (dd.mm.yyyy)";
	}

	void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
		ts3Functions = funcs;
	}

	int ts3plugin_init() {
		return init();
	}

	void ts3plugin_shutdown() {
		shutdown();
	}
}