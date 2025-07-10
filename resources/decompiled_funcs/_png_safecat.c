unsigned int __cdecl png_safecat(int a1, unsigned int a2, unsigned int a3, _BYTE *a4)
{
  if ( a1 && a3 < a2 )
  {
    if ( a4 )
    {
      while ( *a4 && a3 < a2 - 1 )
      {
        *(_BYTE *)(a3 + a1) = *a4;
        ++a3;
        ++a4;
      }
    }
    *(_BYTE *)(a3 + a1) = 0;
  }
  return a3;
}
