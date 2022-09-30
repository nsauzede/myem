/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>

#include "myem/myem.h"

#include "myem/json.hpp"
using json = nlohmann::json;

MyEm::MyEm() :
m_bios_size(0),
m_bios_start(0),
m_bus(),
m_cpu(m_bus),
m_rom(Mem::ro) {
        printf("hello myem\n");
}

MyEm::~MyEm() {
        printf("bye myem\n");
}

void MyEm::Run() {
        printf("running..\n");
        while (1) {
                if (m_cpu.Run()) {
                        printf("bye\n");
                        break;
                }
        }
}

void MyEm::Load(const std::string& config) {
        printf("loading config %s..\n", config.c_str());
        auto j = json::parse(config);
        printf("j=%s\n", j.dump().c_str());
        std::string bios = j.at("bios");
        printf("bios=%s\n", bios.c_str());
        if (m_rom.Load(bios)) {
                m_bios_size = m_rom.GetSize();
                printf("bios size=%" PRIu32 "\n", m_bios_size);
                m_bios_start = 0x100000 - m_bios_size;
                m_rom.Bind(m_bios_start, m_bios_start + m_bios_size);
                m_bus.BindSlave(m_rom);
        } else {
                printf("can't open bios (%s)\n", bios.c_str());
                exit(0);
        }
}
