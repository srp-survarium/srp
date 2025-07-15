int __cdecl png_set_oFFs(int a1, int a2, int a3, int a4, char a5)
{
  int result; // eax

  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 100) = a3;
      *(_DWORD *)(a2 + 104) = a4;
      *(_BYTE *)(a2 + 108) = a5;
      result = a2;
      *(_DWORD *)(a2 + 8) |= 0x100u;
    }
  }
  return result;
}
