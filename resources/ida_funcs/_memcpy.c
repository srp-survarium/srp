char *__fastcall _memcpy(unsigned int cb, char *pvDst, char *pvSrc)
{
  char *i; // edi

  for ( i = pvDst; cb; ++pvSrc )
  {
    --cb;
    *pvDst++ = *pvSrc;
  }
  return i;
}
