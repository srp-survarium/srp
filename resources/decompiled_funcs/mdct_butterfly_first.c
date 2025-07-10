void __usercall mdct_butterfly_first(float *T@<edx>, float *x@<edi>, int points@<ecx>)
{
  float *v3; // eax
  float *v4; // ecx
  double v5; // st7
  float r0; // [esp+4h] [ebp-8h]
  float r0a; // [esp+4h] [ebp-8h]
  float r0b; // [esp+4h] [ebp-8h]
  float r0c; // [esp+4h] [ebp-8h]
  float r1; // [esp+8h] [ebp-4h]
  float r1a; // [esp+8h] [ebp-4h]
  float r1b; // [esp+8h] [ebp-4h]
  float r1c; // [esp+8h] [ebp-4h]

  v3 = &x[(points >> 1) - 8];
  v4 = &v3[points - (points >> 1) + 7];
  do
  {
    r0 = *(v4 - 1) - v3[6];
    r1 = *v4 - v3[7];
    *(v4 - 1) = v3[6] + *(v4 - 1);
    *v4 = v3[7] + *v4;
    v3[6] = *T * r0 + T[1] * r1;
    v3[7] = r1 * *T - r0 * T[1];
    r0a = *(v4 - 3) - v3[4];
    r1a = *(v4 - 2) - v3[5];
    *(v4 - 3) = v3[4] + *(v4 - 3);
    *(v4 - 2) = *(v4 - 2) + v3[5];
    v3[4] = T[5] * r1a + T[4] * r0a;
    v3[5] = r1a * T[4] - r0a * T[5];
    r0b = *(v4 - 5) - v3[2];
    r1b = *(v4 - 4) - v3[3];
    *(v4 - 5) = *(v4 - 5) + v3[2];
    *(v4 - 4) = *(v4 - 4) + v3[3];
    v3[2] = T[8] * r0b + r1b * T[9];
    v5 = r1b * T[8] - r0b * T[9];
    v3 -= 8;
    v4 -= 8;
    T += 16;
    v3[11] = v5;
    r0c = v4[1] - v3[8];
    r1c = v4[2] - v3[9];
    v4[1] = v3[8] + v4[1];
    v4[2] = v3[9] + v4[2];
    v3[8] = *(T - 4) * r0c + r1c * *(T - 3);
    v3[9] = r1c * *(T - 4) - r0c * *(T - 3);
  }
  while ( v3 >= x );
}
