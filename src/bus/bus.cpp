#include <stdio.h>

#include "bus.h"

Bus::Bus() {
}

uint8_t Bus::Read8(uint32_t addr) const {
        uint8_t res = 0xff;
#if 0
        if ((addr >= m_bios_start) && (addr < (m_bios_start + m_bios_size))) {
                res = *(m_bios + addr - m_bios_start);
        }
#else
        for (const auto& it : m_slaves) {
                if (it->Match(addr)) {
//                        printf("Match ! addr=%" PRIx32 " start=%" PRIx32 "\n", addr, it->GetStart());
                        res = it->Read8(addr - it->GetStart());
                        break;
                }
        }
#endif
        return res;
}

void Bus::BindSlave(const BusSlave& slave) {
        m_slaves.push_back(&slave);
}

void BusSlave::Bind(uint32_t start, uint32_t end) {
//        printf("start=%" PRIx32 " end=%" PRIx32 "\n", start, end);
        m_start = start;
        m_end = end;
}

uint32_t BusSlave::GetStart() const {
        return m_start;
}

uint8_t BusSlave::Read8(uint32_t offs) const {
        return 0xff;
}

bool BusSlave::Match(uint32_t addr) const {
        bool match = false;
        if ((addr >= m_start) && (addr < m_end)) {
                match = true;
        }
        return match;
}
