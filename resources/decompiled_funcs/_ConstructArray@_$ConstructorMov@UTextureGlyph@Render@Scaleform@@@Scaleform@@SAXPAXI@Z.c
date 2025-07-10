void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // ecx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 24;
    do
    {
      if ( v3 != (char *)24 )
      {
        *((_DWORD *)v3 - 6) = &Scaleform::RefCountImplCore::`vftable';
        *((_DWORD *)v3 - 5) = 1;
        *((_DWORD *)v3 - 6) = &Scaleform::Render::TextureGlyph::`vftable';
        *((float *)v3 - 2) = 0.0;
        *((float *)v3 - 1) = 0.0;
        *((_DWORD *)v3 - 4) = 0;
        *(float *)v3 = 0.0;
        *((float *)v3 + 1) = 0.0;
        *((_DWORD *)v3 + 4) = -1;
      }
      v3 += 48;
      --v2;
    }
    while ( v2 );
  }
}
