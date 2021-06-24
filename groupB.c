#include <stdio.h>

void CMP(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;
    int R = (int) (D - S);

    if(R < 0)
        SR |= 2;
    else if(R > 0)
        SR |= 0;
    else
        SR |= 1;
}

void CMC(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;
    int R = (int) (D - S);

    if(R < 0)
        SR |= 0;
    else if(R > 0)
        SR |= 2;
    else
        SR |= 3;   
}

void TST(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;
    uint16_t R = D & S;

    if(R == 0)
        SR |= 1;
    else {
        uint16_t i = 1 << 15;
        if(R&i)
            SR |= 8;
        else
            SR |= 0;
    }
}

void XCH(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t t = *pD;
    *pD = *pS;
    *pS = *t;
}

void ADD(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;
    if(!m)
        D = D + S;
    else
        S = D + S;    
}

void ADC(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t C = 0xff01;
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D + S + C;
    else
        S = D + S + C;   
}

void SUB(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D - S;
    else
        S = D - S;    
}

void SBC(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t C = 0xff01;
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D - S + C;
    else
        S = D - S + C;       
}

void AND(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D & S;
    else
        S = D & S;   
}

void IOR(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D | S;
    else
        S = D | S;   
}

void XOR(uint16_t *pD, uint16_t *pS, bool m)
{
    uint16_t D = *pD;
    uint16_t S = *pS;

    if(!m)
        D = D ^ S;
    else
        S = D ^ S;
}

void call_F8()
{
    bool m = false;
    if (IR & 0x0100) 
		m = true;
    uint16_t gggg = (IR & 0x00E0) >> 4;

    switch(gggg){
        case 0: CMP(&D, &S, m);
                break;
        case 1: CMC(&D, &S, m);
                break;
        case 2: TST(&D, &S, m);
                break;
        case 3: XCH(&D, &S, m);
                break;
        case 4: ADD(&D, &S, m);
                break;
        case 5: ADC(&D, &S, m);
                break;
        case 6: SUB(&D, &S, m);
                break;
        case 7: SBC(&D, &S, m);
                break;
        case 8: AND(&D, &S, m);
                break;
        case 9: IOR(&D, &S, m);
                break;
        case 10: XOR(&D, &S, m);
                break;
    }
}

void call_F9()
{
    uint16_t gggg = (IR & 0x000E) >> 1;

    switch(gggg){
        case 0: CMP(&D, &S, 0);
                break;
        case 1: CMC(&D, &S, 0);
                break;
        case 2: TST(&D, &S, 0);
                break;
        case 3: XCH(&D, &S, 0);
                break;
        case 4: ADD(&D, &S, 0);
                break;
        case 5: ADC(&D, &S, 0);
                break;
        case 6: SUB(&D, &S, 0);
                break;
        case 7: SBC(&D, &S, 0);
                break;
        case 8: AND(&D, &S, 0);
                break;
        case 9: IOR(&D, &S, 0);
                break;
        case 10: XOR(&D, &S, 0);
                break;
    }
}