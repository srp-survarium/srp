void __usercall mdct_butterfly_8(float *x@<eax>)
{
  float r0; // [esp+0h] [ebp-10h]
  float r0a; // [esp+0h] [ebp-10h]
  float r0b; // [esp+0h] [ebp-10h]
  float r2; // [esp+4h] [ebp-Ch]
  float r2a; // [esp+4h] [ebp-Ch]
  float r1; // [esp+8h] [ebp-8h]
  float r1a; // [esp+8h] [ebp-8h]
  float r3; // [esp+Ch] [ebp-4h]

  r0 = x[6] + x[2];
  r1 = x[6] - x[2];
  r2 = *x + x[4];
  r3 = x[4] - *x;
  x[6] = r2 + r0;
  x[4] = r0 - r2;
  r0a = x[5] - x[1];
  r2a = x[7] - x[3];
  *x = r1 + r0a;
  x[2] = r1 - r0a;
  r0b = x[5] + x[1];
  r1a = x[7] + x[3];
  x[3] = r3 + r2a;
  x[1] = r2a - r3;
  x[7] = r1a + r0b;
  x[5] = r1a - r0b;
}
