GPP=g++
CXXFLAGS=  -fshow-column -fno-diagnostics-show-caret   -O2  `pkg-config --cflags opencv` -std=c++11
LDFLAGS=  -s  `pkg-config --libs opencv`
OBJS=release.lnx/main.o 

all: release.lnx linux.lnx\opencv

clean:
	rm -rf ${OBJS} linux.lnx\opencv release.lnx

linux.lnx\opencv: ${OBJS}
	${GPP} ${OBJS} ${LDFLAGS} -o $@

release.lnx:
	mkdir release.lnx

release.lnx/main.o: main.cpp json.hpp
	${GPP} ${CXXFLAGS} -c main.cpp -o $@

