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

release.lnx/main.o: main.cpp json.hpp pdi_functions.h utils.h ../../../../../../../usr/local/opencv/opencv-3.2.0/modules/core/include/opencv2/core/cvdef.h
	${GPP} ${CXXFLAGS} -c main.cpp -o $@

