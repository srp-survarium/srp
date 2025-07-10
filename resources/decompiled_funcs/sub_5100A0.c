_BYTE *__cdecl sub_5100A0(_BYTE *a1, int *a2, int *a3, _DWORD *a4)
{
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  v6 = 0;
  v5 = -1;
  while ( (byte_888D30[(unsigned __int8)*a1] & 4) != 0 )
    v6 = 10 * v6 + (unsigned __int8)*a1++ - 48;
  if ( (unsigned int)v6 >= 0x10000 )
  {
    *a4 = 5;
    return a1;
  }
  if ( *a1 == 125 )
  {
    v5 = v6;
  }
  else if ( *++a1 != 125 )
  {
    v5 = 0;
    while ( (byte_888D30[(unsigned __int8)*a1] & 4) != 0 )
      v5 = 10 * v5 + (unsigned __int8)*a1++ - 48;
    if ( (unsigned int)v5 >= 0x10000 )
    {
      *a4 = 5;
      return a1;
    }
    if ( v5 < v6 )
    {
      *a4 = 4;
      return a1;
    }
  }
  *a2 = v6;
  *a3 = v5;
  return a1;
}
