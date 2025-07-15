int __cdecl png_sig_cmp(int a1, unsigned int a2, unsigned int siz)
{
  _BYTE rhs[8]; // [esp+0h] [ebp-Ch] BYREF

  rhs[0] = -119;
  rhs[1] = 80;
  rhs[2] = 78;
  rhs[3] = 71;
  rhs[4] = 13;
  rhs[5] = 10;
  rhs[6] = 26;
  rhs[7] = 10;
  if ( siz <= 8 )
  {
    if ( !siz )
      return -1;
  }
  else
  {
    siz = 8;
  }
  if ( a2 > 7 )
    return -1;
  if ( siz + a2 > 8 )
    siz = 8 - a2;
  return memcmp((unsigned __int8 *)(a2 + a1), &rhs[a2], siz);
}
