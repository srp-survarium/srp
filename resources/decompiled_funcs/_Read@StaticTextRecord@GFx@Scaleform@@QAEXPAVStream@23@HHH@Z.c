void __thiscall Scaleform::GFx::StaticTextRecord::Read(
        Scaleform::GFx::StaticTextRecord *this,
        Scaleform::GFx::Stream *in,
        int glyphCount,
        int glyphBits,
        unsigned int advanceBits)
{
  int i; // edi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v7; // esi
  Scaleform::GFx::StaticTextRecord::GlyphEntry *v8; // esi

  Scaleform::ArrayData<Scaleform::GFx::StaticTextRecord::GlyphEntry,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextRecord::GlyphEntry,258>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Glyphs.Data,
    glyphCount);
  for ( i = 0; i < glyphCount; v8->GlyphAdvance = (float)Scaleform::GFx::Stream::ReadSInt(in, advanceBits) )
  {
    v7 = &this->Glyphs.Data.Data[i];
    v7->GlyphIndex = Scaleform::GFx::Stream::ReadUInt(in, glyphBits);
    v8 = &this->Glyphs.Data.Data[i++];
  }
}
