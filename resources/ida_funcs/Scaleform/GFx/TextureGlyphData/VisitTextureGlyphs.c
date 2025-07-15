void __thiscall Scaleform::GFx::TextureGlyphData::VisitTextureGlyphs(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::TextureGlyphData::TextureGlyphVisitor *pvisitor)
{
  unsigned int v3; // esi
  int v4; // edi
  unsigned int n; // [esp+8h] [ebp-4h]

  v3 = 0;
  n = this->TextureGlyphs.Data.Size;
  if ( n )
  {
    v4 = 0;
    do
      pvisitor->Visit(pvisitor, v3++, &this->TextureGlyphs.Data.Data[v4++]);
    while ( v3 < n );
  }
}
