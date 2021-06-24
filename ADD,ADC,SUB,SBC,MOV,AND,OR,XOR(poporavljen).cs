#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void ADD(int8_t R1, int8_t R2)
{
	int16_t sum;
	sum = R1 + R2;
	printf("%d", sum);
}
void SUB(int16_t R1, int16_t R2) {
	int16_t rez;
	rez = R1 - R2;
	printf("%d", rez);
}
int16_t MOV(int16_t R1, int16_t R2) {
	R2 = R1;
	printf("%d %d", R1, R2);
	return R2;
}
void AND(int16_t R1, int16_t R2)
{
	int16_t rez;
	rez = R1 & R2;
	printf("%d", rez);
}
void IOR(int16_t R1, int16_t R2)
{
	int16_t rez;
	rez = R1 | R2;
	printf("%d", rez);
}
void XOR(int16_t R1, int16_t R2)
{
	int16_t rez;
	rez = R1 ^ R2;
	printf("%d", rez);
}
void ADC(int16_t R1, int16_t R2) {
	int16_t res;
	res = R1 + R2;
	if (res >= 65536) {
	//postavljanje carry-bita u jedinicu (statusni registar uzet iz datasheeta)
	}
}
void SBC(int16_t R1, int16_t R2) {
	int16_t res;
	res = R1 - R2;
	if (res >= 65536) {
		//postavljanje carry-bita u jedinicu (statusni registar uzet iz datasheeta)
	}
}
void funkcija1011(uint16_t IR) {
	int16_t R1=4, R2=7;
	uint16_t Mask1 = 0b0000111000000000;
	uint16_t gBitovi = IR & Mask1;
	if (gBitovi == 0b0000000000000000) {
		ADD(R1, R2);
	}
	if (gBitovi == 0b0000001000000000) {
		ADC(R1, R2);
	}
	if (gBitovi == 0b000001000000000) {
		AND(R1, R2);
	}
	if (gBitovi == 0b000001100000000) {
		IOR(R1, R2);
	}
	if (gBitovi == 0b000010000000000) {
		XOR(R1, R2);
	}
	if (gBitovi == 0b0000101000000000) {
		MOV(R1, R2);
	}
	if (gBitovi == 0b0000110000000000) {
		SUB(R1, R2);
	}
	if (gBitovi == 0b0000111000000000) {
		SBC(R1, R2);
	}
}
void funkcija0101(uint16_t IR) {
	uint16_t R1=7, R2=4;
	uint16_t Mask1 = 0b0000111000000000;
	uint16_t gBitovi = IR & Mask1;
	if (gBitovi == 0b0000000000000000) {
		ADD(R1, R2);
	}
	if (gBitovi == 0b0000001000000000) {
		ADC(R1, R2);
	}
	if (gBitovi == 0b000001000000000) {
		AND(R1, R2);
	}
	if (gBitovi == 0b000001100000000) {
		IOR(R1, R2);
	}
	if (gBitovi == 0b000010000000000) {
		XOR(R1, R2);
	}
	if (gBitovi == 0b0000101000000000) {
		MOV(R1, R2);
	}
	if (gBitovi == 0b0000110000000000) {
		SUB(R1, R2);
	}
	if (gBitovi == 0b0000111000000000) {
		SBC(R1, R2);
	}
}

void main()
{
	
	uint16_t IR = 0b1011110011010001;
	funkcija1011(IR);
	funkcija0101(IR);
	
}

	D(R1, R2);
		else if (IR[4] == 0 && IR[5] == 1 && IR[6] == 1 && IR[7] == 1)
			IOR(R1, R2);
		else if (IR[4] == 1 && IR[5] == 0 && IR[6] == 0 && IR[7] == 1)
			XOR(R1, R2);
		else if (IR[4] == 1 && IR[5] == 0 && IR[6] == 1 && IR[7] == 1)
			MOV(R1, R2);
		else if (IR[4] == 1 && IR[5] == 1 && IR[6] == 0 && IR[7] == 1)
			SUB(R1, R2);
		else if (IR[4] == 1 && IR[5] == 1 && IR[6] == 1 && IR[7] == 1)
		SBC(R1, R2);
	}


}