Scaleform::GFx::ShapeDataBase *__thiscall Scaleform::GFx::FontData::GetPermanentGlyphShape(
        Scaleform::GFx::FontData *this,
        unsigned int glyphIndex)
{
  if ( glyphIndex >= this->Glyphs.Data.Size )
    return 0;
  else
    return this->Glyphs.Data.Data[glyphIndex].pObject;
}
