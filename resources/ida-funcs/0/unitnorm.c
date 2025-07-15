double __cdecl unitnorm(float x)
{
  return COERCE_FLOAT(LODWORD(x) & 0x80000000 | 0x3F800000);
}
