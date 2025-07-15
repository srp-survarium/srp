int __cdecl png_set_gAMA_fixed(int a1, int a2, int a3)
{
  int result; // eax

  if ( a1 && a2 )
  {
    if ( a3 >= 16 && a3 <= 625000000 )
    {
      *(_DWORD *)(a2 + 40) = a3;
      result = a2;
      *(_DWORD *)(a2 + 8) |= 1u;
    }
    else
    {
      return png_warning(a1, "Out of range gamma value ignored");
    }
  }
  return result;
}
