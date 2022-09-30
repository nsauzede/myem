#ifndef MEM_H_
#define MEM_H_

#include "bus/bus.h"

class Mem : public BusSlave {
 public:
        typedef const enum {rw, ro} MemAccess;
 private:
        unsigned char *m_mem;
        uint32_t m_size;
        MemAccess m_access;
 public:
        Mem(MemAccess = rw);
        ~Mem();
        bool Load(const std::string& file);
        uint32_t GetSize() const {
                return m_size;
        }
        virtual uint8_t Read8(uint32_t offs) const;
};

#endif/*MEM_H_*/
