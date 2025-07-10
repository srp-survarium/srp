int __cdecl png_read_sig(int a1, int a2)
{
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-8h]

  result = a1;
  if ( *(unsigned __int8 *)(a1 + 321) < 8u )
  {
    v3 = *(unsigned __int8 *)(a1 + 321);
    *(_DWORD *)(a1 + 684) = 17;
    png_read_data(a1, a2 + v3 + 32, 8 - v3);
    *(_BYTE *)(a1 + 321) = 8;
    result = png_sig_cmp(a2 + 32, v3, 8 - v3);
    if ( result )
    {
      if ( v3 < 4 )
      {
        if ( png_sig_cmp(a2 + 32, v3, 8 - v3 - 4) )
          png_error(a1, (int)"Not a PNG file");
      }
      png_error(a1, (int)"PNG file corrupted by ASCII conversion");
    }
    if ( v3 < 3 )
    {
      result = *(_DWORD *)(a1 + 108) | 0x1000;
      *(_DWORD *)(a1 + 108) = result;
    }
  }
  return result;
}
