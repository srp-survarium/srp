Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  const Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // esi
  unsigned int v4; // edi
  int UInt32fixlen; // eax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > it; // [esp+8h] [ebp-28h] BYREF

  p_Decoder = &this->Decoder;
  v4 = this->GlyphInfoTablePos + 8 * glyphIndex;
  it.Data.Data = this->Decoder.Data;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder,
                   v4 + 4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &it,
    UInt32fixlen);
  if ( it.XMin >= it.XMax || it.YMin >= it.YMax )
  {
    it.YMax = 0;
    it.YMin = 0;
    it.XMin = 0;
    LOBYTE(it.XMax) = p_Decoder->Data->Pages[(v4 + 2) >> 12][(v4 + 2) & 0xFFF];
    HIBYTE(it.XMax) = p_Decoder->Data->Pages[(v4 + 3) >> 12][(v4 + 3) & 0xFFF];
  }
  return Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetBounds(
           (Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *)&it,
           prect);
}
