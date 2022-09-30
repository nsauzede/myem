#include <stdio.h>

#include "cpu.h"

Cpu::Cpu(const Bus& bus) :
m_bus(bus),
m_cs(0),m_ds(0),m_es(0),
m_ip(0),
m_ax(0),m_bx(0),m_cx(0),m_dx(0),
m_quit(false) {
        Reset();
}

void Cpu::Reset() {
        m_cs = 0xf000;
        m_ip = 0xfff0;
}

uint8_t Cpu::Fetch8(uint32_t addr) {
        unsigned char b = m_bus.Read8(addr);
        printf("%02" PRIX8, b);
        return b;
}

#if 0
#define dprintf(...) do{printf(__VA_ARGS__);}while(0)
#else
#define dprintf(...) do{}while(0)
#endif

const char* WREG[] = {
"al","bl","cl","dl","e1","fl","gl","hl",
"ax","bx","cx","dx","ex","fx","gx","hx",
};
#define WREGNAME(wreg) WREG[wreg&0xf]

void Cpu::Decode() {
        uint32_t addr = 16 * m_cs + m_ip;
        unsigned char b;
        printf("%08" PRIX32 "  ", addr);
        b = Fetch8(addr);m_ip++;
        dprintf("==Decode : addr=%" PRIx32 " b=%02x\n", addr, b);
        switch (b) {
                case 0x8e: {
                /*
                1000 1110
                MOV Move
                Register to Segment Register
                mod 0 reg r/m
                */
                        dprintf("MOV Register/Memory to Segment Register\n");
                        uint8_t wreg = b & 0x0f;
                        dprintf("wreg=%" PRIx8 "\n", wreg);
                        uint8_t datalow = Fetch8(++addr);m_ip++;
                        dprintf("data-low=%" PRIx8 "\n", datalow);
                        uint8_t datahigh = 0;
                        if (wreg & 0x8) {
                                datahigh = Fetch8(++addr);m_ip++;
                                dprintf("data-high=%" PRIx8 "\n", datahigh);
                        }
                        uint32_t data = datahigh * 256 + datalow;
                        dprintf("data=%" PRIx8 "\n", data);
                        printf(" mov %s,0x%" PRIx16 "\n", WREGNAME(wreg), (uint16_t)data);
                        printf("FIXME: impl regs\n");
                        m_quit = true;
                        break;
                }
                case 0xb0 ... 0xbf: {
                /*
                1011 wreg
                MOV Move
                Immediate to Register
                data [data if w=1]
                */
                        dprintf("MOV Immediate to Register\n");
                        uint8_t wreg = b & 0x0f;
                        dprintf("wreg=%" PRIx8 "\n", wreg);
                        uint8_t datalow = Fetch8(++addr);m_ip++;
                        dprintf("data-low=%" PRIx8 "\n", datalow);
                        uint8_t datahigh = 0;
                        if (wreg & 0x8) {
                                datahigh = Fetch8(++addr);m_ip++;
                                dprintf("data-high=%" PRIx8 "\n", datahigh);
                        }
                        uint32_t data = datahigh * 256 + datalow;
                        dprintf("data=%" PRIx8 "\n", data);
                        printf(" mov %s,0x%" PRIx16 "\n", WREGNAME(wreg), (uint16_t)data);
                        printf("FIXME: impl regs\n");
                        m_quit = true;
                        break;
                }
                case 0xe9: {
                /*
                1110 1001
                JMP Unconditional Jump
                Direct Within Segment
                disp-low disp-high
                */
                        dprintf("JMP Direct Within Segment\n");
                        uint8_t displow = Fetch8(++addr);m_ip++;
                        dprintf("disp-low=%" PRIx8 "\n", displow);
                        uint8_t disphigh = Fetch8(++addr);m_ip++;
                        dprintf("disp-high=%" PRIx8 "\n", disphigh);
                        uint32_t disp = disphigh * 256 + displow;
                        m_ip += disp;
                        printf(" jmp 0x%" PRIx16 "\n", (uint16_t)m_ip);
                        break;
                }
                case 0xea: {
                /*
                1110 1010
                JMP Unconditional Jump
                Direct Intersegment
                offset-low offset-high seg-low seg-high
                */
                        dprintf("JMP Direct Intersegment\n");
                        uint8_t offslow = Fetch8(++addr);m_ip++;
                        dprintf("offset-low=%" PRIx8 "\n", offslow);
                        uint8_t offshigh = Fetch8(++addr);m_ip++;
                        dprintf("offset-high=%" PRIx8 "\n", offshigh);
                        uint8_t seglow = Fetch8(++addr);m_ip++;
                        dprintf("seg-low=%" PRIx8 "\n", seglow);
                        uint8_t seghigh = Fetch8(++addr);m_ip++;
                        dprintf("seg-high=%" PRIx8 "\n", seghigh);
                        uint32_t offs = offshigh * 256 + offslow;
                        uint32_t seg = seghigh * 256 + seglow;
                        m_ip = offs;
                        m_cs = seg;
                        printf(" jmp 0x%" PRIx16 ":0x%" PRIx16 "\n", (uint16_t)seg, (uint16_t)offs);
                        break;
                }
                default:
                        printf("==Decode : addr=%" PRIx32 " b=%02x\n", addr, b);
                        printf("unknown OPC b=%02x\n", b);
                        m_quit = true;
                        break;
        }
}

void Cpu::Execute() {
}

void Cpu::dumpregs() {
        printf("AX=%04" PRIx16 " BX=%04" PRIx16 " CX=%04" PRIx16 " DX=%04" PRIx16 "\n", m_ax, m_bx, m_cx, m_dx);
        printf("DS=%04" PRIx16 " ES=%04" PRIx16 " CS=%04" PRIx16 " IP=%04" PRIx16 "\n", m_ds, m_es, m_cs, m_ip);
}

bool Cpu::Run() {
        dumpregs();
        Decode();
        dumpregs();
        Execute();
        return m_quit;
}
