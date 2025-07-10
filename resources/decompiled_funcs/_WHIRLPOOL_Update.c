int __cdecl WHIRLPOOL_Update(WHIRLPOOL_CTX *c, unsigned __int8 *_inp, unsigned int bytes)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx

  v4 = bytes;
  if ( bytes >= 0x10000000 )
  {
    v5 = bytes >> 28;
    do
    {
      WHIRLPOOL_BitUpdate(c, _inp, 0x80000000);
      v4 -= 0x10000000;
      _inp += 0x10000000;
      --v5;
    }
    while ( v5 );
  }
  if ( v4 )
    WHIRLPOOL_BitUpdate(c, _inp, 8 * v4);
  return 1;
}
