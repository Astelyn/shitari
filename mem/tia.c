#include "common.h"
#include "mem.h"
#include "tia.h"

void tia_clear_strobes(void)
{
    mem.tia[WSYNC] = 0;
    mem.tia[RSYNC] = 0;
    mem.tia[RESP0] = 0;
    mem.tia[RESP1] = 0;
    mem.tia[RESM0] = 0;
    mem.tia[RESM1] = 0;
    mem.tia[RESBL] = 0;
    mem.tia[HMOVE] = 0;
    mem.tia[HMCLR] = 0;
    mem.tia[CXCLR] = 0;
}

void tia_wsync(void)
{

}

void tia_rsync(void)
{

}

void tia_resp0(void)
{

}

void tia_resp1(void)
{

}

void tia_resm0(void)
{

}

void tia_resm1(void)
{

}

void tia_resbl(void)
{

}

void tia_hmove(void)
{

}

void tia_hmclr(void)
{

}

void tia_cxclr(void)
{

}

