#ifndef FONT_H
#define FONT_H

/* TODO -> Better Font, more neutral, GBA feel like maybe, but also should be legible and try to be small so long song titles could enter */

const unsigned short Letter_A[5] = {0b01111100, 0b11101110, 0b11101110, 0b11111110, 0b11101110};
const unsigned short Letter_B[5] = {0b11111100, 0b11101110, 0b11111100, 0b11101110, 0b11111100};
const unsigned short Letter_C[5] = {0b01111100, 0b11101110, 0b11100000, 0b11101110, 0b01111100};
const unsigned short Letter_D[5] = {0b11111100, 0b11101110, 0b11101110, 0b11101110, 0b11111100};
const unsigned short Letter_E[5] = {0b11111110, 0b11100000, 0b11111100, 0b11100000, 0b11111110};
const unsigned short Letter_F[5] = {0b11111110, 0b11100000, 0B11111100, 0b11100000, 0b11100000};
const unsigned short Letter_G[5] = {0b01111100, 0b11100000, 0b11101110, 0b11100110, 0b01111100};
const unsigned short Letter_H[5] = {0b11101110, 0b11101110, 0b11111110, 0b11101110, 0b11101110};
const unsigned short Letter_I[5] = {0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110};
const unsigned short Letter_J[5] = {0b00001110, 0b00001110, 0b00001110, 0b11101110, 0b01111110};
const unsigned short Letter_K[5] = {0b11101110, 0b11111100, 0b11111000, 0b11111100, 0b11101110};
const unsigned short Letter_L[5] = {0b11100000, 0b11100000, 0b11100000, 0b11111110, 0b11111110};
const unsigned short Letter_M[5] = {0b11000110, 0b11101110, 0b11111110, 0b11010110, 0b11000110};
const unsigned short Letter_N[5] = {0b11000110, 0b11110110, 0b11111110, 0b11011110, 0b11000110};
const unsigned short Letter_O[5] = {0b01111100, 0b11101110, 0b11101110, 0b11101110, 0b01111100};
const unsigned short Letter_P[5] = {0b11111100, 0b11101110, 0b11101110, 0b11111100, 0b11100000};
const unsigned short Letter_Q[5] = {0b01111100, 0b11101110, 0b11101110, 0b11111100, 0b00011110};
const unsigned short Letter_R[5] = {0b11111100, 0b11101110, 0b11111110, 0b11101100, 0b11101110};
const unsigned short Letter_S[5] = {0b01111110, 0b11100000, 0b01111100, 0b00001110, 0b11111100};
const unsigned short Letter_T[5] = {0b11111110, 0b00111000, 0b00111000, 0b00111000, 0b00111000};
const unsigned short Letter_U[5] = {0b11101110, 0b11101110, 0b11101110, 0b11101110, 0b01111110};
const unsigned short Letter_V[5] = {0b11101110, 0b11101110, 0b11101110, 0b01111100, 0b00111000};
const unsigned short Letter_W[5] = {0b11000110, 0b11010110, 0b11111110, 0b11111110, 0b01101100};
const unsigned short Letter_X[5] = {0b11101110, 0b01111100, 0b00111000, 0b01111100, 0b11101110};
const unsigned short Letter_Y[5] = {0b11000110, 0b11101110, 0b01111100, 0b00111000, 0b00111000};
const unsigned short Letter_Z[5] = {0b11111110, 0b00011100, 0b00111000, 0b01110000, 0b11111110};

const unsigned short* Letters[26] = {
    Letter_A, Letter_B, Letter_C, Letter_D, Letter_E, Letter_F, Letter_G, Letter_H, Letter_I,
    Letter_J, Letter_K, Letter_L, Letter_M, Letter_N, Letter_O, Letter_P, Letter_Q,
    Letter_R, Letter_S, Letter_T, Letter_U, Letter_V, Letter_W, Letter_X, Letter_Y, Letter_Z
};


#endif