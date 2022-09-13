# myem

Experiments with cpu emulator

To build, first install vade :
https://github.com/nsauzede/vade

To test, first get some BIOS, eg:
```
myem$ wget -q -O bios.bin https://github.com/640-KB/GLaBIOS/releases/download/v0.1.6/GLABIOS_0.1.6_091322_8088.ROM
```
Then :
```
myem$ vade clean test
    RM  pkg
    RM  bin
    CXX bus.o
    AR  bus.a
    AR  libbus.a
    CXX cpu.o
    AR  cpu.a
    AR  libcpu.a
    CXX mem.o
    AR  mem.a
    AR  libmem.a
    CXX myem.o
    AR  myem.a
    AR  libmyem.a
    CXX myem_test.o
    CC  testing.o
    AR  myem_test.a
    AR  libmyem_test.a
    CXX myem_test.exe
    RUN ./bin/myem_test.exe
Testing MyEm..
hello myem
Testing MyEm config..
loading config {"bios":"bios.bin"}..
j={"bios":"bios.bin"}
bios=bios.bin
bios size=8192
Testing MyEm run..
running..
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=fff0
000FFFF0  EA5BE000F0 jmp 0xf000:0xe05b
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=e05b
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=e05b
000FE05B  FA==Decode : addr=fe05b b=fa
unknown OPC b=fa
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=e05c
bye
bye myem
```
