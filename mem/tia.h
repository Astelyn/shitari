#ifndef _TIA_H
#define _TIA_H

/* TIA write addresses */
#define VSYNC  0x00 // Vertical sync, set/clear
#define VBLANK 0x01 // Vertical blank, set/clear
#define WSYNC  0x02 //-Wait for leading edge of HBLANK
#define RSYNC  0x03 //-Reset HSYNC counter
#define NUSIZ0 0x04 // Size of player/missile 0
#define NUSIZ1 0x05 // Size of player/missile 1
#define COLUP0 0x06 // Color/luminosity of player/missile 0
#define COLUP1 0x07 // Color/luminosity of player/missile 1
#define COLUPF 0x08 // Color/luminosity of playfield/ball
#define COLUBK 0x09 // Color/luminosity of background
#define CTRLPF 0x0A // Control playfield size/collisions
#define REFP0  0x0B // Reflect player 0
#define REFP1  0x0C // Reflect player 1
#define PF0    0x0D // Playfield register byte 0
#define PF1    0x0E // Playfield register byte 1
#define PF2    0x0F // Playfield register byte 2
#define RESP0  0x10 //-Reset player 0
#define RESP1  0x11 //-Reset player 1
#define RESM0  0x12 //-Reset missile 0
#define RESM1  0x13 //-Reset missile 1
#define RESBL  0x14 //-Reset ball
#define AUDC0  0x15 // Audio control 0
#define AUDC1  0x16 // Audio control 1
#define AUDF0  0x17 // Audio frequency 0
#define AUDF1  0x18 // Audio frequency 1
#define AUDV0  0x19 // Audio volume 0
#define AUDV1  0x1A // Audio volume 1
#define GRP0   0x1B // Graphics player 0
#define GRP1   0x1C // Graphics player 1
#define ENAM0  0x1D // Graphics enable missile 0
#define ENAM1  0x1E // Graphics enable missile 1
#define ENABL  0x1F // Graphics enable ball
#define HMP0   0x20 // Horizontal motion for player 0
#define HMP1   0x21 // Horizontal motion for player 1
#define HMM0   0x22 // Horizontal motion for missile 0
#define HMM1   0x23 // Horizontal motion for missile 1
#define HMBL   0x24 // Horizontal motion for ball
#define VDELP0 0x25 // Vertical delay for player 0
#define VDELP1 0x26 // Vertical delay for player 1
#define VDELBL 0x27 // Vertical delay for ball
#define RESMP0 0x28 // Reset missile 0 to player 0
#define RESMP1 0x29 // Reset missile 1 to player 1
#define HMOVE  0x2A //-Apply horizontal motion
#define HMCLR  0x2B //-Clear horizontal motion registers
#define CXCLR  0x2C //-Clear collision latches

/* TIA read addresses */
#define CXM0P  0x30 // Collision M0-P1, M0-P0
#define CXM1P  0x31 // Collision M1-P0, M1-P1
#define CXP0FB 0x32 // Collision P0-PF, P0-BL
#define CXP1FB 0x33 // Collision P1-PF, P1-BL
#define CXM0FB 0x34 // Collision M0-PF, M0-BL
#define CXM1FB 0x35 // Collision M1-PF, M1-BL
#define CXBLPF 0x36 // Collision BL-PF, N/A
#define CXPPMM 0x37 // Collision P0-P1, M0-M1
#define INPT0  0x38 // Input 0
#define INPT1  0x39 // Input 1
#define INPT2  0x3A // Input 2
#define INPT3  0x3B // Input 3
#define INPT4  0x3C // Input 4
#define INPT5  0x3D // Input 5

extern mem_t mem;

void tia_clear_strobes(void);
void tia_wsync(void);
void tia_rsync(void);
void tia_resp0(void);
void tia_resp1(void);
void tia_resm0(void);
void tia_resm1(void);
void tia_resbl(void);
void tia_hmove(void);
void tia_hmclr(void);
void tia_cxclr(void);

#endif

