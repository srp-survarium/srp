unsigned int __cdecl vostok::sound::cart_to_lut_position(float re, float im)
{
  float v2; // xmm2_4
  unsigned __int64 v3; // rax
  float v5; // [esp+4h] [ebp-4h]

  v2 = im;
  LOWORD(v3) = 0;
  v5 = COERCE_FLOAT(LODWORD(im) & 0x7FFFFFFF) + COERCE_FLOAT(LODWORD(re) & 0x7FFFFFFF);
  if ( v5 > 0.0 )
  {
    v3 = (unsigned __int64)(COERCE_FLOAT(LODWORD(im) & 0x7FFFFFFF) / v5 * 128.0 + 0.5);
    v2 = im;
  }
  if ( re < 0.0 )
    LOWORD(v3) = 256 - v3;
  if ( v2 < 0.0 )
    LOWORD(v3) = 512 - v3;
  return v3 & 0x1FF;
}
