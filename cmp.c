#include <stdio.h>



void CMP(uint8_t *pD, uint8_t *pS, bool m)

{

    uint8_t D = *pD;

    uint8_t S = *pS;

    int R = (int) (D - S);



    if(R < 0)

        SR |= 2;

    else if(R > 0)

        SR |= 0;

    else

        SR |= 1;

}



void CMC(uint8_t *pD, uint8_t *pS, bool m)

{

    uint8_t D = *pD;

    uint8_t S = *pS;

    int R = (int) (D - S);



    if(R < 0)

        SR |= 0;

    else if(R > 0)

        SR |= 2;

    else

        SR |= 3;   

}



void TST(uint8_t *pD, uint8_t *pS, bool m)

{

    uint8_t D = *pD;

    uint8_t S = *pS;

    uint8_t R = D & S;



    if(R == 0)

        SR |= 1;

    else {

        uint8_t i = 1 << 15;

        if(R&i)

            SR |= 8;

        else

            SR |= 0;

    }

}



void XCH(uint8_t *pD, uint8_t *pS, bool m)

{

    uint8_t t = *pD;

    *pD = *pS;

    *pS = *t;

}



void call_F1_2()

{

    bool m = false;

    if (IR & 0x0100) 

		m = true;

    uint8_t gg = (IR & 0x00E0) >> 4;



    switch(gg){

        case 0: CMP(&D, &S, m);

                break;

        case 1: CMC(&D, &S, m);

                break;

        case 2: TST(&D, &S, m);

                break;

        case 3: XCH(&D, &S, m);

                break;

    }

}



void call_F4_2()

{

    uint8_t gg = (IR & 0x000E) >> 1;



    switch(gg){

        case 0: CMP(&D, &S, 0);

                break;

        case 1: CMC(&D, &S, 0);

                break;

        case 2: TST(&D, &S, 0);

                break;

        case 3: XCH(&D, &S, 0);

                break;

    }

}