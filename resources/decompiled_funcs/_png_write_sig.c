unsigned int __cdecl png_write_sig(int a1)
{
  unsigned int result; // eax
  _BYTE v2[8]; // [esp+0h] [ebp-Ch] BYREF

  v2[0] = -119;
  v2[1] = 80;
  v2[2] = 78;
  v2[3] = 71;
  v2[4] = 13;
  v2[5] = 10;
  v2[6] = 26;
  v2[7] = 10;
  *(_DWORD *)(a1 + 684) = 18;
  png_write_data(a1, (int)&v2[*(unsigned __int8 *)(a1 + 321)], 8 - *(unsigned __int8 *)(a1 + 321));
  result = *(unsigned __int8 *)(a1 + 321);
  if ( result < 3 )
  {
    result = a1;
    *(_DWORD *)(a1 + 108) |= 0x1000u;
  }
  return result;
}
