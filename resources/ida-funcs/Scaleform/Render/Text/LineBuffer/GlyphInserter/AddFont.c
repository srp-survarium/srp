void __thiscall Scaleform::Render::Text::LineBuffer::GlyphInserter::AddFont(
        Scaleform::Render::Text::LineBuffer::GlyphInserter *this,
        Scaleform::GFx::Resource *pfont)
{
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v3; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v4; // ecx

  v3 = &this->pGlyphs[this->GlyphIndex];
  v3->Flags |= 0x4000u;
  v4 = &this->pGlyphs[this->GlyphIndex];
  v4->Flags |= 0x2000u;
  this->pNextFormatData[this->FormatDataIndex++].ColorV = (unsigned int)pfont;
  Scaleform::RefCountImpl::AddRef(pfont);
}
