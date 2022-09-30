#include <stdio.h>
#include <malloc.h>

#include <fstream>

#include "mem.h"

Mem::Mem(MemAccess access) :
m_mem(0),
m_size(0),
m_access(access) {
}

Mem::~Mem() {
        if (m_mem) {
                free(m_mem);
        }
}

bool Mem::Load(const std::string& file) {
        bool success = false;
        std::ifstream f(file, std::ios::in | std::ios::binary | std::ios::ate);
        if (f.is_open()) {
                m_size = f.tellg();
                f.seekg(0, std::ios::beg);
//                printf("bios size=%" PRIu32 "\n", m_bios_size);
                m_mem = (unsigned char *)malloc(m_size);
                f.read((char *)m_mem, m_size);
                f.close();
                success = true;
        }
        return success;
}

uint8_t Mem::Read8(uint32_t offs) const {
        uint8_t data = 0xff;
//        printf("offs=%" PRIx32 "\n", offs);
        data = *(m_mem + offs);
        return data;
}
