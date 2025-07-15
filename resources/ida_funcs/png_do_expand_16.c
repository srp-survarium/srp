int __cdecl png_do_expand_16(int a1, int a2)
{
  int result; // eax
  unsigned int i; // [esp+0h] [ebp-8h]
  unsigned int v4; // [esp+4h] [ebp-4h]

  result = a1;
  if ( *(_BYTE *)(a1 + 9) == 8 )
  {
    result = *(unsigned __int8 *)(a1 + 8);
    if ( result != 3 )
    {
      v4 = *(_DWORD *)(a1 + 4) + a2;
      for ( i = *(_DWORD *)(a1 + 4) + v4; i > v4; i -= 2 )
      {
        *(_BYTE *)(i - 1) = *(_BYTE *)--v4;
        *(_BYTE *)(i - 2) = *(_BYTE *)(i - 1);
      }
      *(_DWORD *)(a1 + 4) *= 2;
      *(_BYTE *)(a1 + 9) = 16;
      result = a1;
      *(_BYTE *)(a1 + 11) = 16 * *(_BYTE *)(a1 + 10);
    }
  }
  return result;
}
