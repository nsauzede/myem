#ifndef BUS_H_
#define BUS_H_

#include <inttypes.h>

#include <vector>

#if 0
class BusNode {
 public:
        uint8_t Read8
};

class BusMaster {
 public:
        
};
#endif

class BusSlave {
 private:
        uint32_t m_start;
        uint32_t m_end;
 public:
        void Bind(uint32_t start, uint32_t end);
        bool Match(uint32_t addr) const;
        uint32_t GetStart() const;

        virtual uint8_t Read8(uint32_t offs) const;
};

class Bus;

class BusMaster {
 private:
//        Bus
 public:
        void Bind(const Bus);
};

class Bus {
 private:
        std::vector<const BusSlave *> m_slaves;
 public:
        Bus();
        void BindSlave(const BusSlave& slave);
        unsigned char Read8(uint32_t addr) const;
};

#endif/*BUS_H*/
