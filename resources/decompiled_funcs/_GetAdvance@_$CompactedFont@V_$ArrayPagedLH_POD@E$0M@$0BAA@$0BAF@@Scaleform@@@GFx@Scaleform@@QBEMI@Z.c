double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetAdvance(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex)
{
  unsigned int v2; // eax

  v2 = this->GlyphInfoTablePos + 8 * glyphIndex + 2;
  return (double)(this->Decoder.Data->Pages[v2 >> 12][v2 & 0xFFF]
                | (unsigned int)(__int16)(this->Decoder.Data->Pages[(v2 + 1) >> 12][(v2 + 1) & 0xFFF] << 8));
}
