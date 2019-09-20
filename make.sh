#!/bin/bash
g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.x86
arm-linux-gnueabi-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.arm
arm-linux-gnueabihf-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.armhf
sh4-linux-gnu-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.sh4
mipsel-linux-gnu-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.mipsel
mips-linux-gnu-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.mips
powerpc-linux-gnu-g++ -Wall linux_ecmg.cpp -o irdeto-ecmg.ppc
powerpc-linux-gnuspe-g++  -Wall linux_ecmg.cpp -o irdeto-ecmg.ppcspe
aarch64-linux-gnu-g++  -Wall linux_ecmg.cpp -o irdeto-ecmg.arm64

