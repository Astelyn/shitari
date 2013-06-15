#include "common.h"
#include "mem.h"
#include "tia.h"

/* Clear all TIA strobe registers */
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

/* Wait for leading edge of HBLANK */
void tia_wsync(void)
{

}

/* Reset HBLANK counter */
void tia_rsync(void)
{

}

/* Reset player 0 */
void tia_resp0(void)
{

}

/* Reset player 1 */
void tia_resp1(void)
{

}

/* Reset missile 0 */
void tia_resm0(void)
{

}

/* Reset missile 1 */
void tia_resm1(void)
{

}

/* Reset ball */
void tia_resbl(void)
{

}

/* Apply horizontal motion */
void tia_hmove(void)
{

}

/* Clear horizontal motion registers */
void tia_hmclr(void)
{
    mem.tia[HMP0] = 0;
    mem.tia[HMP1] = 0;
    mem.tia[HMM0] = 0;
    mem.tia[HMM1] = 0;
    mem.tia[HMBL] = 0;
}

/* Clear collision latches */
void tia_cxclr(void)
{
    mem.tia[CXM0P] = 0;
    mem.tia[CXM1P] = 0;
    mem.tia[CXP0FB] = 0;
    mem.tia[CXP1FB] = 0;
    mem.tia[CXM0FB] = 0;
    mem.tia[CXM1FP] = 0;
    mem.tia[CXBLPF] = 0;
    mem.tia[CXPPMM] = 0;
}

