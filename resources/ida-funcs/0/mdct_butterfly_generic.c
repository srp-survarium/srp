void __fastcall mdct_butterfly_generic(int points, float *T, float *x, unsigned int trigint)
{
  unsigned int v5; // esi
  float *v6; // eax
  float *v7; // ecx
  double v8; // st6
  double v9; // st5
  float *v10; // edx
  double v11; // st6
  double v12; // st5
  float *v13; // edx
  double v14; // st6
  double v15; // st5
  float *v16; // edx
  double v17; // st6
  double v18; // st5
  float r1; // [esp+10h] [ebp+4h]
  float r1a; // [esp+10h] [ebp+4h]
  float r1b; // [esp+10h] [ebp+4h]
  float r1c; // [esp+10h] [ebp+4h]
  float r0; // [esp+14h] [ebp+8h]
  float r0a; // [esp+14h] [ebp+8h]
  float r0b; // [esp+14h] [ebp+8h]
  float r0c; // [esp+14h] [ebp+8h]

  v5 = trigint;
  v6 = &x[(points >> 1) - 8];
  v7 = &v6[points - (points >> 1) + 7];
  do
  {
    r0 = *(v7 - 1) - v6[6];
    r1 = *v7 - v6[7];
    *(v7 - 1) = v6[6] + *(v7 - 1);
    *v7 = v6[7] + *v7;
    v6[6] = *T * r0 + T[1] * r1;
    v8 = r1 * *T;
    v9 = T[1];
    v10 = &T[v5];
    v6[7] = v8 - r0 * v9;
    r0a = *(v7 - 3) - v6[4];
    r1a = *(v7 - 2) - v6[5];
    *(v7 - 3) = v6[4] + *(v7 - 3);
    *(v7 - 2) = v6[5] + *(v7 - 2);
    v6[4] = *v10 * r0a + v10[1] * r1a;
    v11 = r1a * *v10;
    v12 = v10[1];
    v13 = &v10[v5];
    v6[5] = v11 - r0a * v12;
    r0b = *(v7 - 5) - v6[2];
    r1b = *(v7 - 4) - v6[3];
    *(v7 - 5) = v6[2] + *(v7 - 5);
    *(v7 - 4) = *(v7 - 4) + v6[3];
    v6[2] = *v13 * r0b + v13[1] * r1b;
    v14 = r1b * *v13;
    v6 -= 8;
    v15 = v13[1];
    v16 = &v13[v5];
    v7 -= 8;
    v6[11] = v14 - r0b * v15;
    r0c = v7[1] - v6[8];
    r1c = v7[2] - v6[9];
    v7[1] = v6[8] + v7[1];
    v7[2] = v6[9] + v7[2];
    v6[8] = *v16 * r0c + v16[1] * r1c;
    v17 = r1c * *v16;
    v18 = v16[1];
    T = &v16[v5];
    v6[9] = v17 - r0c * v18;
  }
  while ( v6 >= x );
}
