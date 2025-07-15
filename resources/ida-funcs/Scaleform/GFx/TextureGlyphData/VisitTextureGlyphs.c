void __thiscall Scaleform::GFx::TextureGlyphData::VisitTextureGlyphs(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::TextureGlyphData::TextureGlyphVisitor *pvisitor)
{
  unsigned int v3; // esi
  int v4; // edi
  unsigned int Size; // [esp+8h] [ebp-4h]

  v3 = 0;
  Size = this->TextureGlyphs.Data.Size;
  if ( Size )
  {
    v4 = 0;
    do
      pvisitor->Visit(pvisitor, v3++, &this->TextureGlyphs.Data.Data[v4++]);
    while ( v3 < Size );
  }
}
