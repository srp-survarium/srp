void __thiscall Scaleform::GFx::TextureGlyphData::AddTextureGlyph(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphIndex,
        const Scaleform::Render::TextureGlyph *glyph)
{
  unsigned int v3; // esi
  unsigned int Size; // ebx
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *p_TextureGlyphs; // edi

  v3 = glyphIndex;
  if ( this->TextureGlyphs.Data.Size > glyphIndex )
    goto LABEL_6;
  Size = this->TextureGlyphs.Data.Size;
  p_TextureGlyphs = &this->TextureGlyphs;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    glyphIndex + 1);
  if ( glyphIndex + 1 > Size )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      (char *)&p_TextureGlyphs->Data.Data[Size],
      glyphIndex + 1 - Size);
  if ( this->TextureGlyphs.Data.Size > glyphIndex )
  {
    v3 = glyphIndex;
LABEL_6:
    Scaleform::Render::TextureGlyph::operator=(&this->TextureGlyphs.Data.Data[v3], glyph);
  }
}
