void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::HighlightDesc>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // edx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 28;
    do
    {
      if ( v3 != (char *)28 )
      {
        *((_DWORD *)v3 - 7) = -1;
        *((_DWORD *)v3 - 6) = 0;
        *((_DWORD *)v3 - 5) = -1;
        *((_DWORD *)v3 - 4) = 0;
        *((_DWORD *)v3 - 3) = 0;
        *((_DWORD *)v3 - 2) = 0;
        *((_DWORD *)v3 + 1) = 0;
        *(_DWORD *)v3 = 0;
        *((_DWORD *)v3 - 1) = 0;
        v3[8] = 0;
      }
      v3 += 40;
      --v2;
    }
    while ( v2 );
  }
}
