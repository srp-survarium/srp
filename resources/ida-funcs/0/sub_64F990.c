int __cdecl sub_64F990(int a1, unsigned __int16 **a2, unsigned __int16 *a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 2 * ((a5 - *a4) >> 1);
  if ( (char *)a3 - (char *)*a2 > result && (*(_BYTE *)(a3 - 1) & 0xF8) == 0xD8 )
    result = (int)--a3;
  while ( *a2 != a3 )
  {
    result = (int)a4;
    if ( *a4 == a5 )
      break;
    *(_WORD *)*a4 = _byteswap_ushort(**a2);
    *a4 += 2;
    result = (int)a2;
    ++*a2;
  }
  return result;
}
