#ifndef GVARIABLES_H
#define GVARIABLES_H

#include<stdint.h>

uint32_t *PC;
uint16_t *stack;
uint16_t *dataMemory;
uint16_t *progMemory;
uint8_t *SR;
uint16_t IR;

bool skip;	//skip flag

uint8_t IE_MASK = 0b10000000;	//Status register masks
uint8_t F1_MASK = 0b01000000;
uint8_t F0_MASK = 0b00100000;
uint8_t O_MASK = 0b00010000;
uint8_t S_MASK = 0b00001000;
uint8_t H_MASK = 0b00000100;
uint8_t C_MASK = 0b00000010;
uint8_t Z_MASK = 0b00000001;

uint16_t temp16_1;	//temporary registers 16-bit
uint16_t temp16_2;
uint16_t temp16_3;

uint8_t temp8_1;	//temporary registers 8-bit
uint8_t temp8_2;
uint8_t temp8_3;

uint16_t* RP0E;	//extension registers
uint16_t* RP2E;
uint16_t* RP4E;
uint16_t* RP6E;

uint16_t* RP00;	//register pairs
uint16_t* RP02;
uint16_t* RP04;
uint16_t* RP06;
uint16_t* RP08;
uint16_t* RP10;
uint16_t* RP12;
uint16_t* RP14;
uint16_t* A;

uint8_t* R00;	//8-bit registers
uint8_t* R01;
uint8_t* R02;
uint8_t* R03;
uint8_t* R04;
uint8_t* R05;
uint8_t* R06;
uint8_t* R07;
uint8_t* R08;
uint8_t* R09;
uint8_t* R10;
uint8_t* R11;
uint8_t* R12;
uint8_t* R13;
uint8_t* R14;
uint8_t* R15;
uint8_t* AL;
uint8_t* AH;

#endif
