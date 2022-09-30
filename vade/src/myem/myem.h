/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MYEM_H_
#define MYEM_H_

#include <string>

#include "bus/bus.h"
#include "mem/mem.h"
#include "cpu/cpu.h"

class MyEm {
 private:
        uint32_t m_bios_size;
        uint32_t m_bios_start;
        Bus m_bus;
        Cpu m_cpu;
        Mem m_rom;

 public:
        MyEm();
        ~MyEm();
        void Load(const std::string& config);
        void Run();
};

#endif/*MYEM_H_*/
