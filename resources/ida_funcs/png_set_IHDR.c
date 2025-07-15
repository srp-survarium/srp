int __cdecl png_set_IHDR(_DWORD *a1, int a2, unsigned int a3, int a4, char a5, char a6, char a7, char a8, char a9)
{
  int result; // eax
  unsigned int v10; // [esp+0h] [ebp-4h]

  if ( a1 && a2 )
  {
    *(_DWORD *)a2 = a3;
    *(_DWORD *)(a2 + 4) = a4;
    *(_BYTE *)(a2 + 24) = a5;
    *(_BYTE *)(a2 + 25) = a6;
    *(_BYTE *)(a2 + 26) = a8;
    *(_BYTE *)(a2 + 27) = a9;
    *(_BYTE *)(a2 + 28) = a7;
    png_check_IHDR(
      a1,
      *(_DWORD *)a2,
      *(_DWORD *)(a2 + 4),
      *(unsigned __int8 *)(a2 + 24),
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned __int8 *)(a2 + 28),
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 27));
    if ( *(_BYTE *)(a2 + 25) == 3 )
    {
      *(_BYTE *)(a2 + 29) = 1;
    }
    else if ( (*(_BYTE *)(a2 + 25) & 2) != 0 )
    {
      *(_BYTE *)(a2 + 29) = 3;
    }
    else
    {
      *(_BYTE *)(a2 + 29) = 1;
    }
    if ( (*(_BYTE *)(a2 + 25) & 4) != 0 )
      ++*(_BYTE *)(a2 + 29);
    result = *(unsigned __int8 *)(a2 + 24) * *(unsigned __int8 *)(a2 + 29);
    *(_BYTE *)(a2 + 30) = result;
    if ( a3 <= 0x1FFFFF8E )
    {
      if ( *(unsigned __int8 *)(a2 + 30) < 8u )
        v10 = (a3 * *(unsigned __int8 *)(a2 + 30) + 7) >> 3;
      else
        v10 = a3 * (*(unsigned __int8 *)(a2 + 30) >> 3);
      result = a2;
      *(_DWORD *)(a2 + 12) = v10;
    }
    else
    {
      *(_DWORD *)(a2 + 12) = 0;
    }
  }
  return result;
}
