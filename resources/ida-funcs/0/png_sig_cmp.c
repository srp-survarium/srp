int __cdecl png_sig_cmp(int a1, unsigned int a2, unsigned int a3)
{
  _BYTE v4[8]; // [esp+0h] [ebp-Ch] BYREF

  v4[0] = -119;
  v4[1] = 80;
  v4[2] = 78;
  v4[3] = 71;
  v4[4] = 13;
  v4[5] = 10;
  v4[6] = 26;
  v4[7] = 10;
  if ( a3 <= 8 )
  {
    if ( !a3 )
      return -1;
  }
  else
  {
    a3 = 8;
  }
  if ( a2 > 7 )
    return -1;
  if ( a3 + a2 > 8 )
    a3 = 8 - a2;
  return memcmp((unsigned __int8 *)(a2 + a1), &v4[a2], a3);
}
