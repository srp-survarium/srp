const Scaleform::Render::TextureGlyph *__thiscall Scaleform::GFx::TextureGlyphData::GetTextureGlyph(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphIndex)
{
  if ( glyphIndex < this->TextureGlyphs.Data.Size )
    return &this->TextureGlyphs.Data.Data[glyphIndex];
  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    dummyTextureGlyph.UvBounds.x1 = 0.0;
    dummyTextureGlyph.UvBounds.y1 = 0.0;
    dummyTextureGlyph.UvBounds.x2 = 0.0;
    dummyTextureGlyph.RefCount = 1;
    dummyTextureGlyph.UvBounds.y2 = 0.0;
    dummyTextureGlyph.__vftable = (Scaleform::Render::TextureGlyph_vtbl *)&Scaleform::Render::TextureGlyph::`vftable';
    dummyTextureGlyph.pImage.pObject = 0;
    dummyTextureGlyph.BindIndex = -1;
    atexit(Scaleform::GFx::TextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__);
  }
  return &dummyTextureGlyph;
}
