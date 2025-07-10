int __cdecl png_set_pHYs(int a1, int a2, int a3, int a4, char a5)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 112) = a3;
      *(_DWORD *)(a2 + 116) = a4;
      *(_BYTE *)(a2 + 120) = a5;
      result = a2;
      *(_DWORD *)(a2 + 8) |= 0x80u;
    }
  }
  return result;
}
