_DWORD *__cdecl png_calculate_crc(_DWORD *a1, unsigned __int8 *buf, unsigned int a3)
{
  _DWORD *result; // eax
  BOOL v4; // [esp+8h] [ebp-4h]

  result = a1;
  if ( ((a1[64] >> 29) & 1) != 0 )
  {
    result = (_DWORD *)(a1[28] & 0x300);
    v4 = result != (_DWORD *)768;
  }
  else
  {
    v4 = (a1[28] & 0x800) == 0;
  }
  if ( v4 )
  {
    if ( a3 )
    {
      result = (_DWORD *)crc32(a1[73], buf, a3);
      a1[73] = result;
    }
  }
  return result;
}
