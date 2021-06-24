#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"group14.cpp"
#include"group15.cpp"
#include"gvariables.h"


//values of data/program memory (modifiable if doesn't corresponds to datasheet)
int DATA_MEMORY_SIZE = 65536;
int PROG_MEMORY_SIZE = 131072;


void Initialize()
{
	//this points to first adress in allocated memory block(virtually 0x0000)
	dataMemory = (uint16_t*)calloc(DATA_MEMORY_SIZE, sizeof(uint16_t));
	progMemory = (uint16_t*)calloc(PROG_MEMORY_SIZE, sizeof(uint16_t));

	PC = (uint32_t*)(progMemory + 0x00800);
	stack = (uint16_t*)(dataMemory + 0x00FE);	//stack pointer
	SR = (uint8_t*)(dataMemory + 0x0100);		//status register

	RP00 = (uint16_t*)(dataMemory);
	RP02 = (uint16_t*)(dataMemory + 0x0002);
	RP04 = (uint16_t*)(dataMemory + 0x0004);
	RP06 = (uint16_t*)(dataMemory + 0x0006);
	RP08 = (uint16_t*)(dataMemory + 0x0008);
	RP10 = (uint16_t*)(dataMemory + 0x000A);
	RP12 = (uint16_t*)(dataMemory + 0x000C);
	RP14 = (uint16_t*)(dataMemory + 0x000E);
	A = (uint16_t*)(dataMemory + 0x000E);		//accumulator

	R00 = (uint8_t*)(dataMemory);
	R01 = (uint8_t*)(dataMemory + 0x0001);
	R02 = (uint8_t*)(dataMemory + 0x0002);
	R03 = (uint8_t*)(dataMemory + 0x0003);
	R04 = (uint8_t*)(dataMemory + 0x0004);
	R05 = (uint8_t*)(dataMemory + 0x0005);
	R06 = (uint8_t*)(dataMemory + 0x0006);
	R07 = (uint8_t*)(dataMemory + 0x0007);
	R08 = (uint8_t*)(dataMemory + 0x0008);
	R09 = (uint8_t*)(dataMemory + 0x0009);
	R10 = (uint8_t*)(dataMemory + 0x000A);
	R11 = (uint8_t*)(dataMemory + 0x000B);
	R12 = (uint8_t*)(dataMemory + 0x000C);
	R13 = (uint8_t*)(dataMemory + 0x000D);
	R14 = (uint8_t*)(dataMemory + 0x000E);
	R15 = (uint8_t*)(dataMemory + 0x000F);
	AL = (uint8_t*)(dataMemory + 0x000E);		//accumulator low
	AH = (uint8_t*)(dataMemory + 0x000F);		//accumulator high

	skip = 0;

	IR = 0b0000000000000000;

	temp16_1 = 0b0000000000000000;
	temp16_2 = 0b0000000000000000;
	temp16_3 = 0b0000000000000000;

	temp8_1 = 0b00000000;
	temp8_2 = 0b00000000;
	temp8_3 = 0b00000000;

	RP0E = (uint16_t*)(dataMemory + 0x0200);
	RP2E = (uint16_t*)(dataMemory + 0x0202);
	RP4E = (uint16_t*)(dataMemory + 0x0204);
	RP6E = (uint16_t*)(dataMemory + 0x0206);

}


int main() {

	Initialize();

	uint16_t ID03;
	uint16_t ID04;
	uint16_t ID05;
	uint16_t ID06;
	uint16_t ID07;
	uint16_t ID08;
	uint16_t ID10;
	uint16_t ID11;
	uint16_t ID12;
	uint16_t ID13;
	uint16_t ID14;
	uint16_t IDM1;
	uint16_t IDM2;
	uint16_t IDM3;

	uint16_t MASK03 = 0b1110000000000000;
	uint16_t MASK04 = 0b1111000000000000;
	uint16_t MASK05 = 0b1111100000000000;
	uint16_t MASK06 = 0b1111110000000000;
	uint16_t MASK07 = 0b1111111000000000;
	uint16_t MASK08 = 0b1111111100000000;
	uint16_t MASK10 = 0b1111111111000000;
	uint16_t MASK11 = 0b1111111111100000;
	uint16_t MASK12 = 0b1111111111110000;
	uint16_t MASK13 = 0b1111111111111000;
	uint16_t MASK14 = 0b1111111111111100;
	uint16_t MASKM1 = 0b1111000100000000;
	uint16_t MASKM2 = 0b1111100100000000;
	uint16_t MASKM3 = 0b1110100000000000;


	while (1) {

		IR = *(PC++);

		ID03 = IR & MASK03;
		ID04 = IR & MASK04;
		ID05 = IR & MASK05;
		ID06 = IR & MASK06;
		ID07 = IR & MASK07;
		ID08 = IR & MASK08;
		ID10 = IR & MASK10;
		ID11 = IR & MASK11;
		ID12 = IR & MASK12;
		ID13 = IR & MASK13;
		ID14 = IR & MASK14;
		IDM1 = IR & MASKM1;
		IDM2 = IR & MASKM2;
		IDM3 = IR & MASKM3;


		if (ID03 == 0b1110000000000000)
		{
			//call of corresponding function 111

			//e.g. f111(IR);

			continue;
		}

		if (IDM3 == 0b0100100000000000)
		{
			//call of corresponding function 010-1

			continue;
		}

		if (ID03 == 0b0110000000000000)
		{
			//call of corresponding function 011

			continue;
		}

		if (ID04 == 0b1101000000000000)
		{
			//call of corresponding function 1101


			continue;
		}

		if (ID04 == 0b1100000000000000)
		{
			//call of corresponding function 1100

			continue;

		}

		if (ID04 == 0b1011000000000000)
		{
			//call of corresponding function 1011

			continue;
		}

		if (ID04 == 0b1010000000000000)
		{
			//call of corresponding function 1010

			continue;

		}

		if (IDM1 == 0b1001000100000000)
		{
			//call of corresponding function 1001---1

			continue;
		}

		if (ID04 == 0b1000000000000000)
		{
			//call of corresponding function 1000

			continue;
		}

		if (IDM2 == 0b1001100000000000)
		{
			//call of corresponding function 1001 1--0

			continue;
		}

		if (IDM2 == 0b1001000000000000)
		{
			//call of corresponding function 1001 0--0

			continue;
		}

		if (ID05 == 0b0101000000000000)
		{
			//call of corresponding function 0101 0

			continue;
		}

		if (ID05 == 0b0011100000000000)
		{
			//call of corresponding function 0011 1

			continue;
		}

		if (ID05 == 0b0011000000000000)
		{
			//call of corresponding function 0011 0

			continue;
		}

		if (ID06 == 0b0100000000000000)
		{
			//call of corresponding function 0100 00

			continue;
		}

		if (ID07 == 0b0010111000000000)
		{
			//call of corresponding function 0010 111

			continue;
		}

		if (ID07 == 0b0010101000000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID07 == 0b0010100000000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID08 == 0b0010110100000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID10 == 0b0010110011000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID10 == 0b0010110001000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID10 == 0b0010110000000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID11 == 0b0010110010100000)
		{
			//call of corresponding function

			continue;
		}

		if (ID11 == 0b0010011111100000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID11 == 0b0010110010000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID12 == 0b0010011111010000)
		{
			//call of corresponding function 

			continue;

		}

		if (ID12 == 0b0010011111000000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID14 == 0b0010011110111100)
		{
			//call of corresponding function 

			continue;
		}

		if (ID13 == 0b0000000000001000)
		{
			//call of corresponding function 

			continue;
		}

		if (ID13 == 0b0000000000000000)
		{
			//call of corresponding function 

		}

	}

	return 0;
}