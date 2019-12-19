#include "parser_long.h"

uint8_t frame[255];
uint8_t chid[2];
uint8_t chanid[2];
uint8_t keyid;
uint8_t provider;
uint8_t casid[2];
uint8_t streamid[2];// 0f,20
uint8_t ecmid[2]; //15,16
uint8_t cpdura[2];//1b, 1c
uint8_t cw0[8];
uint8_t cw1[8];
uint8_t  acc[20];
uint8_t cwnum[2];
uint8_t cpnum[2];

const uint8_t ans0003[0x57] = {
//00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f
0x02 , 0x00 , 0x03 , 0x00 , 0x51 , 0x00 , 0x0e , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x02 , 0x00 , 0x01 , 0x01,
0x00 , 0x16 , 0x00 , 0x02 , 0x00 , 0xc8 , 0x00 , 0x17 , 0x00 , 0x02 , 0x00 , 0xc8 , 0x00 , 0x03 , 0x00 , 0x02,
0x00 , 0xc8 , 0x00 , 0x04 , 0x00 , 0x02 , 0x00 , 0xc8 , 0x00 , 0x05 , 0x00 , 0x02 , 0xfe , 0x0c , 0x00 , 0x06,
0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x07 , 0x00 , 0x02 , 0x00 , 0x64 , 0x00 , 0x08 , 0x00 , 0x02 , 0x00 , 0x00,
0x00 , 0x09 , 0x00 , 0x02 , 0x00 , 0x0a , 0x00 , 0x0a , 0x00 , 0x01 , 0x01 , 0x00 , 0x0b , 0x00 , 0x01 , 0x02,
0x00 , 0x0c , 0x00 , 0x02 , 0x00 , 0x64 , 0x00
};

const uint8_t ans0103[0x1d] = {
//00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f
0x02 , 0x01 , 0x03 , 0x00 , 0x17 , 0x00 , 0x0e , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x0f , 0x00 , 0x02 , 0x00,
0x00 , 0x00 , 0x19 , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x11 , 0x00 , 0x01 , 0x00 , 0x00
};

const uint8_t ans0202[0xd8] = {
0x02, 0x02, 0x02, 0x00, 0xd2, 0x00, 0x0e, 0x00, 0x02, 0xff, 0xff, 0x00, 0x0f, 0x00, 0x02, 0xff,
0xff, 0x00, 0x12, 0x00, 0x02, 0xff, 0xff, 0x00, 0x15, 0x00, 0xbc, 0x47, 0x5f, 0xff, 0x10, 0x00,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
};

const uint8_t ans0105[0x12] = {
0x02 , 0x01 , 0x05 , 0x00 , 0x0c , 0x00 , 0x0e , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x0f , 0x00 , 0x02 , 0x00,
0x00 , 0x00
};

void parse(char *daten,uint8_t menge,char *zurueck,int& senden){
    //printf("\nins00 ");
    if (daten[1]==0x0 && daten[2]==0x01){//00 01 => 00 03
        //printf("cla01 \n");
        chid[0]=daten[0x9];chid[1]=daten[0xa];
        casid[0]=daten[0xf];casid[1]=daten[0x10];
        for(int i = 0;i <= ans0003[4]+5;i++){ zurueck[i] = ans0003[i];}
        zurueck[0x09]=chid[0];zurueck[0x0a]=chid[1];
        senden = 1;
    }
    //printf("\nins01 ");
    else if (daten[1] == 0x00 && daten[2] == 0x04){
        senden = 0;
    }

    else if(daten[1]==0x1 && daten[2]==0x01){//01 01 => 01 03
        //printf("cla01 \n");
        streamid[0]=daten[0x0f];streamid[1]=daten[0x10];
        ecmid[0]=daten[0x15];ecmid[1]= daten[0x16];
        cpdura[0]=daten[0x1b];cpdura[1]=daten[0x1c];
        for(int i = 0;i <= ans0103[4]+5;i++){ zurueck[i] = ans0103[i];}
        zurueck[0x09]=chid[0];zurueck[0x0a]=chid[1];
        zurueck[0x0f]=streamid[0];zurueck[0x10]=streamid[1];
        zurueck[0x15]=ecmid[0];zurueck[0x16]=ecmid[1];
        senden = 1;
    }
    else if (daten[1]==0x1 && daten[2]==0x04){ //01 04 => 01 05
        for(int i = 0;i <= ans0105[4]+5;i++){ zurueck[i] = ans0105[i];}
        zurueck[0x09]=daten[0x09];zurueck[0x0a]=daten[0x0a];
        zurueck[0x0f]=daten[0x0f];zurueck[0x10]=daten[0x10];
        senden = 1;
    }

    else if(daten[1]==0x2 &&daten[2]==0x01){//CW provisioning
           for (int i = 5; i <= daten[4]+5;i++){

    if(daten[i] == 0x00 && daten[i+1] == 0x14 && daten[i+3]== 0x0a) { //CW0 CW1
        //printf("Found CW! \n");
        cwnum[0] = daten[i+4]; cwnum[1] = daten[i+5];
        if ((cwnum[1] & 1) == 1){
            for(int j=0;j<=7;j++){cw1[j] = daten[i+6+j]&0xff;}
        }
        else {
            for(int j=0;j<=7;j++){cw0[j] = daten[i+6+j]&0xff;}
        }
    i += daten[i+3]+3;
    }
   else if(daten[i] == 0x00 && daten[i+1] == 0x0e && daten[i+3]== 0x02){ //CHID
        //printf("\nchid found \n");
        chid[0] = daten[i+4]&0xff;chid[1] = daten[i+5]&0xff;
        i += daten[i+3]+3;
    }
     else if(daten[i] == 0x00 && daten[i+1] == 0x0f && daten[i+3]== 0x02) { //streamid
        //printf("stream id found \n");
        streamid[0]=daten[i+4];streamid[1]=daten[i+5];
        i += daten[i+3]+3;
    }
     else if(daten[i] == 0x00 && daten[i+1] == 0x13 && daten[i+3]== 0x02) { //cp duration
        //printf("cp duration found \n");
        cpdura[0] = daten[i+4];cpdura[1] = daten[i+5];
        i += daten[i+3]+3;
    }
    else if(daten[i] == 0x00 && daten[i+1] == 0x12 && daten[i+3]== 0x02) {//crypto period
        //printf("cp number found \n");
        cpnum[0] = daten[i+4];cpnum[1] = daten[i+5];
        i += daten[i+3]+3;
    }
    else if(daten[i] == 0x00 && daten[i+1] == 0x0d && daten[i+3] > 0x0) {//access criteria
        //printf("access criteria found: \n");
        for(int j= 0;j <= daten[i+3]+3;j++){acc[j] = daten[i+3+j];}
        i += daten[i+3]+3;
    }

   }

//00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f 40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f 50 51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f 60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f 70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f 80 81 82 83 84 85 86 87 88 89 8a 8b 8c 8d 8e 8f 90 91 92 93 94 95 96 97 98 99 9a 9b 9c 9d 9e 9f a0 a1 a2 a3 a4 a5 a6 a7 a8 a9 aa ab ac ad ae af b0 b1 b2 b3 b4 b5 b6 b7 b8 b9 ba bb bc bd be bf c0 c1 c2 c3 c4 c5 c6 c7 c8 c9 ca cb cc cd ce cf d0 d1 d2 d3 d4 d5 d6 d7 d8 d9 da db dc dd de df e0 e1 e2 e3 e4 e5 e6 e7 e8 e9 ea eb ec ed ee ef f0 f1 f2 f3 f4 f5 f6 f7 f8 f9 fa fb fc fd fe ff
//02 02 02 00 D2 00 0E 00 02 75 30 00 0F 00 02 10 01 00 12 00 02 00 00 00 15 00 BC 47 5F FF 10 00 80 70 26 00 00 23 75 30 10 0A 00 1D 40 02 1E 83 78 12 0A 13 AA BD 1E 72 95 79 84 82 79 FF F5 6B CF 1A 17 DC 1B 6F F6 44 C7 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
//02 02 02 00 D2 00 0E 00 02 75 30 00 0F 00 02 10 01 00 12 00 02 00 00 00 15 00 BC 47 5F FF 10 00 80 70 26 00 00 23 75 30 10 0A 00 1D 40 02 1E 83 78 12 0A 13 AA BD 1E 72 95 79 84 82 79 FF F5 6B CF 1A 17 DC 1B 6F F6 44 C7 80 70 26 00 00 23 75 30 10 0A 00 1D 40 02 1E 83 78 12 0A 13 AA BD 1E 72 95 79 84 82 79 FF F5 6B CF 1A 17 DC 1B 6F F6 44 C7 80 70 26 00 00 23 75 30 10 0A 00 1D 40 02 1E 83 78 12 0A 13 AA BD 1E 72 95 79 84 82 79 FF F5 6B CF 1A 17 DC 1B 6F F6 44 C7 80 70 26 00 00 23 75 30 10 0A 00 1D 40 02 1E 83 78 12 0A 13 AA BD 1E 72 95 79 84 82 79 FF F5 6B CF 1A 17 DC 1B 6F F6 44 C7 FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
//                                                                                                00        ^                                                                                                                01        ^                                                                                                                02        ^                                                                                                                03        ^




    printf("\nCW0: ");
    for(int j=0;j<=7;j++){printf("%02X ",cw0[j]);}
    printf("\nCW1: ");
    for(int j=0;j<=7;j++){printf("%02X ",cw1[j]);}
    printf("\nAccess-Criteria: ");
    for(int j=1;j<=acc[0];j++){printf("%02X ",acc[j]&0xff);}
    printf("\nCHID: %02X %02X \n",chid[0]&0xff,chid[1]&0xff);
    printf("STREAM ID: %02X %02X \n",streamid[0]&0xff,streamid[1]&0xff);
    printf("CP Number: %02X %02X \n",cpnum[0],cpnum[1]);
    printf("CP DURATION: %02X %02X (%d sec.) \n",cpdura[0]&0xff,cpdura[1]&0xff,(cpdura[1]&0xff)/10);
    printf("\n");

    int ecmrunden = acc[0] / 4 -1;
    for(int i = 0;i <= ans0202[4]+5;i++){ zurueck[i] = (ans0202[i] & 0xff);}

for(int runde = 0; runde <= ecmrunden;runde++){

    int index = 0x29*runde;

    //08 10 0a 75 30 10 08 27 10
    //00 01 02 03 04 05 06 07 08


    if ((cpnum[1]&0x1) == 1){frame[0] = 0x1;}
    else {frame[0] = 0x00;}
    frame[1] = 0x00;

    chanid[0]=acc[3+(runde*4)];chanid[1]=acc[4+(runde*4)];

    generate_ecm(frame,chanid,acc[1+(runde*4)],acc[2+(runde*4)],cw0,cw1);

    frame[0]=0;

    printf("ECM to SEND: \n");

    //for(int i = 0;i <= ans0202[4]+5;i++){ zurueck[i] = (ans0202[i] & 0xff);}

    if ((cpnum[1]&0x1) == 1){zurueck[0x20+index] = 0x81;}
    else {zurueck[0x20+index] = 0x80;}
    zurueck[0x21+index]=0x70;

    for (int i=0;i <= 0x25 ;i++){printf("%02X ",frame[i]);zurueck[(0x23 + i)+index]=frame[i];}

    printf("\n");

    zurueck[0x09]=chid[0];zurueck[0x0a]=chid[1];
    zurueck[0x0f]=streamid[0];zurueck[0x10]=streamid[1];
    zurueck[0x15]=cpnum[0];zurueck[0x16]=cpnum[1];
    zurueck[0x22+index] = zurueck[0x25+index] + 3;
}
    senden = 1;

} //end cw provisioning
        printf("\n");
}
