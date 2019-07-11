/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <malloc.h>

#include <fstream>

#include "myem.h"

#include "json.hpp"
using json = nlohmann::json;

MyEm::MyEm() :
m_bios(0),
m_bios_size(0) {
	printf("hello myem\n");
}

MyEm::~MyEm() {
	if (m_bios) {
		free(m_bios);
	}
	printf("bye myem\n");
}

void MyEm::Run() {
	printf("running..\n");
}

void MyEm::Load(const std::string& config) {
	printf("loading config %s..\n", config.c_str());
	auto j = json::parse(config);
	printf("j=%s\n", j.dump().c_str());
	std::string bios = j.at("bios");
	printf("bios=%s\n", bios.c_str());
	std::ifstream biosf(bios, std::ios::in | std::ios::binary | std::ios::ate);
	if (biosf.is_open()) {
		m_bios_size = biosf.tellg();
		biosf.seekg(0, std::ios::beg);
		printf("bios size=%lu\n", m_bios_size);
		m_bios = (unsigned char *)malloc(m_bios_size);
		biosf.read((char *)m_bios, m_bios_size);
		biosf.close();
	} else {
		printf("can't open bios\n");
		exit(0);
	}
}
