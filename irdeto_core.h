#ifndef IRDETO_CORE
#define IRDETO_CORE

#include <time.h>
#include<stdio.h>
#include <fstream>
#include <cstring>

using namespace std;

extern void generate_emm(uint8_t *buffer,int type,uint8_t *hexserial,uint8_t *providerid,uint8_t provider,uint8_t *hmk,uint8_t *pmk,int keyident,uint8_t *chid,uint8_t *start,uint8_t *valid);
extern void generate_ecm(uint8_t *buffernew,uint8_t *chid,uint8_t provider,uint8_t keynum,uint8_t *cw0 ,uint8_t *cw1);
extern void readkeys(void);
#endif
