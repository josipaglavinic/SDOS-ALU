#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



//authors: Marko Perajica,Luka Petričević,Frano Kutlešič-Bijader

uint16_t *PC;
uint16_t IR;
long C = 0000; //or 1111
long r = 0000; //or 1111
uint16_t *RP6;
long word;

//Skips instruction if condition is true (increment PC by one adress)
void skp()
{
	if (C == 1111)
	*PC++;
}

void rpt()
{
	//Somewhere in the program RP6 is set on some value which this instruction reads
	//and repeats instruction the number of times. The number is taken from RP6.
	//converts from binary to decimal

	for (int i = 0; i < 16; i++)
	{
		word = word + RP6[i];
	}

	int dec = 0, i = 0, rem;
	while (word != 0) {
		rem = word % 10;
		word /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	for (i = 0; i < dec; i++)
	{
		IR = *PC;
		void executeInstruction();
		
	}
}

//Loads from memory if r is set to 0000 or stores if it is set to 1111
// Destination of loading and storing data is RP6
long mvp()
{
	//load
	if (r == 0000)
	{
		word = 0;

		for (int i = 0; i < 16; i++)
		{
			word = word + RP6[i];
		}

		return word;
	}

	//store
	else if (r == 1111)
	{
		*RP6 = word;
	}
}

void executeInstruction()
{
		ID = IR & 0b1110000000000000;
		//napravit masku
		//IR = *(PC++);//pogledaj sta je s ovim

		if (ID == 0b1110000000000000)
		{
			//call of corresponding function 111
			f111(IR);
			PC++;
			IR = *PC;
			continue;
		}
		else if (IR == 0b1101)
		{
			//call of corresponding function 1101

			continue;

		}
		else if (IR == 0b1100)
		{
			//call of corresponding function 1100

		}
		else if (IR == 0b1011)
		{
			//call of corresponding function 1011
		}
		else if (IR == 0b1010)
		{
			//call of corresponding function 1010

		}
		else if (IR == 0b1001)
		{
			//call of corresponding function 1001
		}
		else if (IR == 0b0010111)
		{
			//call of corresponding function 0010 111
		}
		else if (IR == 0b0010101)
		{
			//call of corresponding function 0010 101
		}
		else if (IR == 0b0010110011)
		{
			//call of corresponding function 0010 1100 11
		}
}

