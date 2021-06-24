#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"gvariables.h"


void ROL8(uint16_t* temp1)
{
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	*R00 = (*temp1 << 1) | (*temp1 >> 7);
	printf("%d", *R00);
}
/*funkcija za rotiranje u desno*/
void ROR8(uint16_t* temp1)
{
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	*R00 = (*temp1 >> 1) | (*temp1 << 7);
	printf("%d", *R00);
}
/*funkcije za logiko pomicanje u lijevo*/
void LSL8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	*R00 = *temp1 << 1;
	printf("%d", *R00);
}
/*funkcija za logiko pomicanje u desno*/
void LSR8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	*R00 = *temp1 >> 1;
	printf("%d", *R00);
}

void RCL8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;

	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	uint8_t carry = *temp1 & 0x80; 
	*temp1 <<= 1; 
	*R00 = *temp1 | carry; 
	printf("%d", *R00);

}

/*funkcija za pomicanje u desno sa carry*/
void RCR8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;

	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	uint8_t carry = (*temp1 & 0x01); 
	carry = (carry << 7); 
	*temp1 = (*temp1 >> 1);
	*R00 = *temp1 | carry; 
	printf("%d\n", *R00);
}

void ROL16(uint16_t* temp1)
{

	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	*RP00 = (*temp1 << 1) | (*temp1 >> 15);  
	printf("%d", *RP00);
}
/*funkcija za pomicanje udesno */
void ROR16(uint16_t* temp1)
{
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	*RP00 = (*temp1 >> 1) | (*temp1 << 15); 
	printf("%d", *RP00);
}
/*funkcija za logiko pomicanje u lijevo*/
void LSL16(uint16_t* temp1) {
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	*RP00 = *temp1 << 1; 
	printf("%d", *RP00);
}
/*funkcija za logiko pomicanje u desno */
void LSR16(uint16_t* temp1) {
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	*RP00 = *temp1 >> 1; 
	printf("%d", *RP00);
}

/*funkcija za pomicanje u lijevo sa carry*/
void RCL16(uint16_t* temp1) {

		if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	uint16_t carry = *temp1 & 0x8000; 
	*temp1 <<= 1; // pomicanje u lijevo za 1 bit
	*RP00 = *temp1 | carry; 
	printf("%d\n", *RP00);
}
/*8-bitne*/

/*funkcija za aritmeticko pomicanje u desno*/
void ASR8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;

	if (var1 == 0)
		*SR = *SR || Z_MASK;
	if (((*temp1 & 0b11111111) & 0b10000000) == 0b10000000)
		*SR = *SR || C_MASK;
	uint8_t carry = (*temp1 & 0x80); //spremanje najznacajnijeg bita u carry
	*temp1 = (*temp1 >> 1); //pomicanje rijeci u desno za 1 bit
	*R00 = (*temp1 | carry); //zbrajanje carry i R01
	printf("%d", *R00);
}


/*funkcija inkrementa*/
void INC8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	*R00 = *temp1++;
	printf("%d", *R00);
}

/*funkcija dekrementa*/
void DEC8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	*R00 = *R01--;
	printf("%d", *R00);
}
/*funkcija za racunanje prvog komplementa*/
void COM8(uint16_t* temp1) {
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	*R00 = ~*temp1;
	printf("%d", *R00); //invertira 0 u 1 i 1 u 0
}

/*funkcija za racunanje drugog komplementa*/
void NEG8(uint16_t* temp1)
{
	uint8_t var1 = uint8_t(*temp1);
	*temp1 = var1;
	if (var1 == 0)
		*SR = *SR || Z_MASK;
	*R00 = ~*temp1 + 1;
	printf("%d", *R00); //invertira 0 i 1 i dodaje 1
}

/*16-bitne*/

/*funkcija za aritmeticko pomicanje udesno */
void ASR16(uint16_t* temp1) {
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;

	if (((*temp1 & 0b1111111111111111) & 0b10000000000000000) == 0b10000000000000000)
		*SR = *SR || C_MASK;
	uint16_t carry = (*temp1 & 0x8000); //sprema namanje vazan bit u carry
	*temp1 = (*temp1 >> 1); //pomice rijec udesno za 1
	*RP00 = (*temp1 + carry); //zbraja carry sa pomaknutom rijeci
	printf("%d", *RP00);
}

void INC16(uint16_t* temp1) {
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	*RP00 = *temp1++;
	printf("%d", *RP00);
}
void DEC16(uint16_t* temp1) {
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	*RP00 = *temp1--;
	printf("%d", *RP00);
}
/*funkcija za racunanje prvi komplement*/
void COM16(uint16_t* temp1)
{
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	*RP00 = ~*temp1;
	printf("%d", *RP00); //invertira 0 i 1
}
/*funkcija za racunanje drugi komplement*/
void NEG16(uint16_t* temp1)
{
	if (*temp1 == 0)
		*SR = *SR || Z_MASK;
	*RP00 = ~*temp1 + 1;
	printf("%d", *RP00); //invertiranim 0 i 1 dodaje 1 
}
