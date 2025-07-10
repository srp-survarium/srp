void __cdecl fastzero_I(_OWORD *dst, unsigned int len)
{
  unsigned int v3; // ecx

  v3 = len >> 7;
  do
  {
    *dst = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst += 8;
    --v3;
  }
  while ( v3 );
}
