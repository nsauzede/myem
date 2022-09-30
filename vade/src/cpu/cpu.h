#ifndef CPU_H_
#define CPU_H_

#include "bus/bus.h"

class Cpu {
 private:
        const Bus& m_bus;
        uint16_t m_cs, m_ds, m_es;
        uint16_t m_ip;
        uint16_t m_ax, m_bx, m_cx, m_dx;
        bool m_quit;
 public:
        Cpu(const Bus& bus);
        void Reset();
        bool Run();
        uint8_t Fetch8(uint32_t addr);
        void Decode();
        void Execute();
        void dumpregs();
};

#endif/*CPU_H_*/
