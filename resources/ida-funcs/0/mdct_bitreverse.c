void __usercall mdct_bitreverse(mdct_lookup *init@<eax>, float *x@<edx>)
{
  int *bitrev; // esi
  float *v3; // ebp
  float *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  double v7; // st6
  float *v8; // edi
  float *v9; // ebx
  int v10; // edi
  int v11; // ebx
  double v12; // st6
  float *v13; // edi
  float *v14; // ebx
  float r0; // [esp+10h] [ebp-10h]
  float r0a; // [esp+10h] [ebp-10h]
  float r0b; // [esp+10h] [ebp-10h]
  float r0c; // [esp+10h] [ebp-10h]
  float r1; // [esp+14h] [ebp-Ch]
  float r1a; // [esp+14h] [ebp-Ch]
  float r1b; // [esp+14h] [ebp-Ch]
  float r1c; // [esp+14h] [ebp-Ch]
  float r2; // [esp+18h] [ebp-8h]
  float r2a; // [esp+18h] [ebp-8h]
  float r3; // [esp+1Ch] [ebp-4h]
  float r3a; // [esp+1Ch] [ebp-4h]

  bitrev = init->bitrev;
  v3 = &x[init->n >> 1];
  v4 = &init->trig[init->n];
  v5 = v3 + 3;
  do
  {
    v6 = bitrev[1];
    v7 = v3[*bitrev + 1] - v3[v6 + 1];
    v8 = &v3[*bitrev];
    v9 = &v3[v6];
    v5 -= 4;
    r0 = v7;
    r1 = *v9 + *v8;
    r2 = *v4 * r1 + r0 * v4[1];
    r3 = r1 * v4[1] - r0 * *v4;
    r0a = (v9[1] + v8[1]) * 0.5;
    r1a = (*v8 - *v9) * 0.5;
    *x = r2 + r0a;
    *(v5 - 1) = r0a - r2;
    x[1] = r3 + r1a;
    *v5 = r3 - r1a;
    v10 = bitrev[2];
    v11 = bitrev[3];
    v12 = v3[v10 + 1] - v3[v11 + 1];
    v13 = &v3[v10];
    v14 = &v3[v11];
    r0b = v12;
    r1b = *v14 + *v13;
    r2a = v4[2] * r1b + v4[3] * r0b;
    r3a = r1b * v4[3] - r0b * v4[2];
    r0c = (v14[1] + v13[1]) * 0.5;
    x += 4;
    v4 += 4;
    bitrev += 4;
    r1c = (*v13 - *v14) * 0.5;
    *(x - 2) = r2a + r0c;
    *(v5 - 3) = r0c - r2a;
    *(x - 1) = r3a + r1c;
    *(v5 - 2) = r3a - r1c;
  }
  while ( x < v5 - 3 );
}
