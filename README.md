# myem

Experiments with cpu emulator

To build, first install vade :
https://github.com/nsauzede/vade

Then :
```
myem$ vade clean test
	RM	pkg
	RM	bin
	CXX	bus.o
	AR	bus.a
	AR	libbus.a
	CXX	cpu.o
	AR	cpu.a
	AR	libcpu.a
	CXX	myem.o
	AR	myem.a
	CXX	mem.o
	AR	mem.a
	AR	libmyem.a
	CXX	myem_test.o
	AR	myem_test.a
	CC	testing.o
	AR	libmyem_test.a
	CXX	myem_test.exe
	AR	libmem.a
	RUN	./bin/myem_test.exe
Testing MyEm..
hello myem
Testing MyEm config..
loading config {"bios":"bios.bin"}..
j={"bios":"bios.bin"}
bios=bios.bin
bios size=32768
Testing MyEm run..
running..
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=fff0
000FFFF0  EA5BE000F0 jmp 0xf000:0xe05b
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=e05b
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=e05b
000FE05B  E9EFF5 jmp 0xd64d
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=d64d
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=d64d
000FD64D  B84000 mov ax,0x40
FIXME: impl regs
AX=0000 BX=0000 CX=0000 DX=0000
DS=0000 ES=0000 CS=f000 IP=d650
bye
bye myem
```
