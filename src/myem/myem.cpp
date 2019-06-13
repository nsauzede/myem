/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>

#include "myem.h"

#include "json.hpp"
using json = nlohmann::json;

MyEm::MyEm() {
	printf("hello myem\n");
}

void MyEm::Load(const std::string& config) {
	printf("loading config %s..\n", config.c_str());
	auto j = json::parse(config);
	printf("j=%s\n", j.dump().c_str());
	std::string bios = j.at("bios");
	printf("bios=%s\n", bios.c_str());
}
