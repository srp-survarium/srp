int __cdecl png_set_sRGB(int a1, int a2, char a3)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      *(_BYTE *)(a2 + 44) = a3;
      result = *(_DWORD *)(a2 + 8) | 0x800;
      *(_DWORD *)(a2 + 8) = result;
    }
  }
  return result;
}
