# myem

Experiments with cpu emulator

To build, first install vade :
https://github.com/nsauzede/vade

Then :
```
myem$ vade clean ; vade build ; vade test
	RM	pkg
	RM	bin
	CXX	myem.d
	CXX	myem.o
	AR	libmyem.a
	CXX	myem.exe
	RUN	./bin/myem.exe
hello myem
```
