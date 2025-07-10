int __fastcall ipv6_hex(int inlen, const char *in, unsigned __int8 *out)
{
  int v4; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // dl
  int v9; // ecx
  int v10; // eax

  v4 = 0;
  if ( inlen > 4 )
    return 0;
  for ( ; inlen; v4 = v10 | v9 )
  {
    v7 = *in;
    v8 = *in - 48;
    --inlen;
    ++in;
    v9 = 16 * v4;
    if ( v8 > 9u )
    {
      if ( (unsigned __int8)(v7 - 65) > 5u )
      {
        if ( (unsigned __int8)(v7 - 97) > 5u )
          return 0;
        v10 = v7 - 87;
      }
      else
      {
        v10 = v7 - 55;
      }
    }
    else
    {
      v10 = v7 - 48;
    }
  }
  *out = BYTE1(v4);
  out[1] = v4;
  return 1;
}
