void __thiscall Scaleform::GFx::FontCompactor::AssignGlyphAdvance(
        Scaleform::GFx::FontCompactor *this,
        unsigned int glyphIndex,
        __int16 advanceX)
{
  if ( glyphIndex < this->GlyphInfoTable.Size )
    this->GlyphInfoTable.Pages[glyphIndex >> 6][glyphIndex & 0x3F].AdvanceX = advanceX;
}
