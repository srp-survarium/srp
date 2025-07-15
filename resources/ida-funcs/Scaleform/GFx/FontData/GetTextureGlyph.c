const Scaleform::Render::TextureGlyph *__thiscall Scaleform::GFx::FontData::GetTextureGlyph(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  Scaleform::GFx::TextureGlyphData *pObject; // ecx

  pObject = this->pTGData.pObject;
  if ( pObject && glyphIndex < pObject->TextureGlyphs.Data.Size )
    return Scaleform::GFx::TextureGlyphData::GetTextureGlyph(pObject, glyphIndex);
  else
    return 0;
}
