void __usercall mdct_butterfly_16(float *x@<eax>)
{
  float *v1; // ecx
  float r0; // [esp+0h] [ebp-8h]
  float r0a; // [esp+0h] [ebp-8h]
  float r0b; // [esp+0h] [ebp-8h]
  float r0c; // [esp+0h] [ebp-8h]
  float r1; // [esp+4h] [ebp-4h]
  float r1a; // [esp+4h] [ebp-4h]
  float r1b; // [esp+4h] [ebp-4h]
  float r1c; // [esp+4h] [ebp-4h]

  r0 = x[1] - x[9];
  r1 = *x - x[8];
  x[8] = x[8] + *x;
  x[9] = x[9] + x[1];
  *x = (r1 + r0) * 0.7071067690849304;
  x[1] = (r0 - r1) * 0.7071067690849304;
  r0a = x[3] - x[11];
  r1a = x[10] - x[2];
  x[10] = x[10] + x[2];
  x[11] = x[11] + x[3];
  x[2] = r0a;
  x[3] = r1a;
  r0b = x[12] - x[4];
  r1b = x[13] - x[5];
  x[12] = x[12] + x[4];
  x[13] = x[13] + x[5];
  x[4] = (r0b - r1b) * 0.7071067690849304;
  x[5] = 0.7071067690849304 * (r0b + r1b);
  r0c = x[14] - x[6];
  r1c = x[15] - x[7];
  x[14] = x[14] + x[6];
  x[15] = x[15] + x[7];
  x[6] = r0c;
  x[7] = r1c;
  mdct_butterfly_8(x);
  mdct_butterfly_8(v1);
}
