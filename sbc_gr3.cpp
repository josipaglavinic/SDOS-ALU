#include<stdio.h>
#include<limits.h>
#include<stdint.h>
#include<stdlib.h>
#include"Sequencer.cpp"


void ADD_16(uint16_t* A, uint16_t* R, bool m)
{

	int16_t res = *A + *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b1111111111111111) + (*R & 0b1111111111111111)) & 0b10000000000000000) == 0b10000000000000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b0000000011111111) + (*R & 0b0000000011111111)) & 0b0000000100000000) == 0b0000000100000000)
		* SR = *SR | H_MASK;
	if (res & 0b1000000000000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void ADC_16(uint16_t* A, uint16_t* R, bool m)
{
	int16_t res;
	if (*SR & C_MASK)
		res = *A + *R + 1;
	else
		res = *A + *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b1111111111111111) + (*R & 0b1111111111111111)) & 0b10000000000000000) == 0b10000000000000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b0000000011111111) + (*R & 0b0000000011111111)) & 0b0000000100000000) == 0b0000000100000000)
		* SR = *SR | H_MASK;
	if (res & 0b1000000000000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}

void SBC_16(uint16_t* A, uint16_t* R, bool m)
{
	int16_t res;
	if (*SR & C_MASK)
		res = *A - *R - 1;
	else
		res = *A - *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b1111111111111111) + (*R & 0b1111111111111111)) & 0b10000000000000000) == 0b10000000000000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b0000000011111111) + (*R & 0b0000000011111111)) & 0b0000000100000000) == 0b0000000100000000)
		* SR = *SR | H_MASK;
	if (res & 0b1000000000000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void SUB_16(uint16_t* A, uint16_t* R, bool m)
{
	int16_t res = *A - *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b1111111111111111) + (*R & 0b1111111111111111)) & 0b10000000000000000) == 0b10000000000000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b0000000011111111) + (*R & 0b0000000011111111)) & 0b0000000100000000) == 0b0000000100000000)
		* SR = *SR | H_MASK;
	if (res & 0b1000000000000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void MOV_16(uint16_t* A, uint16_t* R, bool m)
{
	if (m)
		* R = *A;
	else
		*A = *R;
}
void AND_16(uint16_t* A, uint16_t* R, bool m)
{
	int16_t res = *A & *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}
void XOR_16(uint16_t* A, uint16_t* R, bool m)
{
	int16_t res = *A ^ *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}
void IOR_16(uint16_t* A, uint16_t* R, bool m)
{

	int16_t res = *A | *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}

void ADD_8(uint16_t* A, uint16_t* R, bool m)
{
	int8_t res = *A + *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b11111111) + (*R & 0b11111111)) & 0b100000000) == 0b100000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b00001111) + (*R & 0b00001111)) & 0b00010000) == 0b00010000)
		* SR = *SR | H_MASK;
	if (res & 0b100000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;

}
void ADC_8(uint16_t* A, uint16_t* R, bool m)
{
	int8_t res;
	if (*SR & C_MASK)
		res = *A + *R + 1;
	else
		res = *A + *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b11111111) + (*R & 0b11111111)) & 0b100000000) == 0b100000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b00001111) + (*R & 0b00001111)) & 0b00010000) == 0b00010000)
		* SR = *SR | H_MASK;
	if (res & 0b100000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void SBC_8(uint16_t* A, uint16_t* R, bool m)
{
	int8_t res;
	if (*SR & C_MASK)
		res = *A - *R - 1;
	else
		res = *A - *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b11111111) + (*R & 0b11111111)) & 0b100000000) == 0b100000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b00001111) + (*R & 0b00001111)) & 0b00010000) == 0b00010000)
		* SR = *SR | H_MASK;
	if (res & 0b100000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void SUB_8(uint16_t* A, uint16_t* R, bool m)
{
	int8_t res = *A - *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if ((((*A & 0b11111111) + (*R & 0b11111111)) & 0b100000000) == 0b100000000)
		* SR = *SR | C_MASK;
	if ((((*A & 0b00001111) + (*R & 0b00001111)) & 0b00010000) == 0b00010000)
		* SR = *SR | H_MASK;
	if (res & 0b100000000)
		* SR = *SR | S_MASK;
	if (((*R > 0) && (*A > 0) && (res < 0)) || ((*R < 0) && (*A < 0) && (res > 0)))
		* SR = *SR | O_MASK;
	if (m)
	{
		*R = res;
	}
	else
		*A = res;
}
void MOV_8(uint16_t* A, uint16_t* R, bool m)
{
	if (m)
		* R = *A;
	else
		*A = *R;
}
void AND_8(uint16_t* A, uint16_t* R, bool m)
{
	int8_t res = *A & *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}
void XOR_8(uint16_t* A, uint16_t* R, bool m)
{

	int8_t res = *A ^ *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}
void IOR_8(uint16_t* A, uint16_t* R, bool m)
{

	int8_t res = *A | *R;
	if (res == 0)
		* SR = *SR | Z_MASK;
	if (m)
		* R = res;
	else
		*A = res;
}
void call_F4_1()
{
	if (skip == 0) {

		temp16_3 = IR & 0x00FF; //#i8
		uint16_t ggg = (IR & 0x0E00) >> 9;
		switch (ggg) {
		case 0: ADD_8(A, &temp16_3, 0);
			break;
		case 1: ADC_8(A, &temp16_3, 0);
			break;
		case 2: AND_8(A, &temp16_3, 0);
			break;
		case 3: IOR_8(A, &temp16_3, 0);
			break;
		case 4: XOR_8(A, &temp16_3, 0);
			break;
		case 5: MOV_8(A, &temp16_3, 0);
			break;
		case 6: SUB_8(A, &temp16_3, 0);
			break;
		case 7: SBC_8(A, &temp16_3, 0);
		}
	}
	else {
		skip = 0;
		PC++;
	}
}
void call_F7() {

	if (skip == 0) {

		uint16_t* RP = NULL;
		uint16_t rr = IR & 0x0003;
		uint16_t xx = (IR & 0x000C) >> 2;
		temp16_1 = *PC++;

		switch (rr) {
		case 0: RP = RP00;
			break;
		case 1: RP = RP02;
			break;
		case 2: RP = RP04;
			break;
		case 3: RP = RP06;
			break;
		}

		//#i16
		if (IR & 0x0100) {

			uint16_t gggg = (IR & 0x00E0) >> 4;
			switch (gggg) {
			case 0: ADD_16(RP, &temp16_1, 0);
				break;
			case 1: ADC_16(RP, &temp16_1, 0);
				break;
			case 2: AND_16(RP, &temp16_1, 0);
				break;
			case 3: IOR_16(RP, &temp16_1, 0);
				break;
			case 4: XOR_16(RP, &temp16_1, 0);
				break;
			case 5: MOV_16(RP, &temp16_1, 0);
				break;
			case 6: SUB_16(RP, &temp16_1, 0);
				break;
			case 7: SBC_16(RP, &temp16_1, 0);
			}

		}
		//#i8
		else
		{

			uint16_t gggg = (IR & 0x00E0) >> 5;
			switch (gggg) {
			case 0: ADD_8(RP, &temp16_1, 0);
				break;
			case 1: ADC_8(RP, &temp16_1, 0);
				break;
			case 2: ADC_8(RP, &temp16_1, 0);
				break;
			case 3: IOR_8(RP, &temp16_1, 0);
				break;
			case 4: XOR_8(RP, &temp16_1, 0);
				break;
			case 5: MOV_8(RP, &temp16_1, 0);
				break;
			case 6: SUB_8(RP, &temp16_1, 0);
				break;
			case 7: SBC_8(RP, &temp16_1, 0);
			}

		}
		switch (xx) {
			//01 -> RP++
			//10 -> RP--
		case 1: RP += 0x0002;
			break;
		case 2: RP -= 0x0002;
			break;
		}
	}
	else {
		skip = 0;
		PC += 2;
	}
}

void call_F6_1() {

	if (skip == 0) {

		bool m = false;
		uint16_t* RP = NULL;
		uint16_t ggg = (IR & 0x000E) >> 1;
		uint16_t xx = (IR & 0x00C0) >> 6;
		uint16_t rr = (IR & 0x0030) >> 4;

		switch (rr) {
		case 0: RP = RP00;
			break;
		case 1: RP = RP02;
			break;
		case 2: RP = RP04;
			break;
		case 3: RP = RP06;
			break;
		}
		if (IR & 0x0100) { //m
			m = true;
		}

		if (IR & 0x0001)
		{//16bit

			switch (ggg) {

			case 0: ADD_16(A, RP, m);
				break;
			case 1: ADC_16(A, RP, m);
				break;
			case 2: AND_16(A, RP, m);
				break;
			case 3: IOR_16(A, RP, m);
				break;
			case 4: XOR_16(A, RP, m);
				break;
			case 5: MOV_16(A, RP, m);
				break;
			case 6: SUB_16(A, RP, m);
				break;
			case 7: SBC_16(A, RP, m);
				break;
			}


		}
		else
		{//8bit

			switch (ggg) {

			case 0: ADD_8(A, RP, m);
				break;
			case 1: ADC_8(A, RP, m);
				break;
			case 2: SUB_8(A, RP, m);
				break;
			case 3: SBC_8(A, RP, m);
				break;
			case 4: AND_8(A, RP, m);
				break;
			case 5: XOR_8(A, RP, m);
				break;
			case 6: IOR_8(A, RP, m);
				break;
			case 7: MOV_8(A, RP, m);
				break;
			}

		}
		switch (xx) {
			//01 -> RP++
			//10 -> RP--
		case 1: RP += 0x0002;
			break;
		case 2: RP -= 0x0002;
			break;
		}

	}
	else {
		skip = 0;
		PC++;
	}
}