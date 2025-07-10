unsigned int __cdecl vostok::sound::cart_to_lut_position(float re, float im)
{
  unsigned int pos; // [esp+34h] [ebp-8h]
  float denom; // [esp+38h] [ebp-4h]

  pos = 0;
  denom = COERCE_FLOAT(LODWORD(re) & 0x7FFFFFFF) + COERCE_FLOAT(LODWORD(im) & 0x7FFFFFFF);
  if ( denom > 0.0 )
    pos = (__int64)(128.0 * COERCE_FLOAT(LODWORD(im) & 0x7FFFFFFF) / denom + 0.5);
  if ( re < 0.0 )
    pos = 256 - pos;
  if ( im < 0.0 )
    pos = 512 - pos;
  return pos % 0x200;
}
