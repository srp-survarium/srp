void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::DestructArray(
        Scaleform::Render::TextureGlyph *p,
        unsigned int count)
{
  Scaleform::Render::TextureGlyph *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      ((void (__thiscall *)(Scaleform::Render::TextureGlyph *, _DWORD))v2->~Scaleform::Render::TextureGlyph)(v2, 0);
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
