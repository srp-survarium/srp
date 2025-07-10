double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphWidth(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex)
{
  const Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // esi
  unsigned int v3; // edi
  int UInt32fixlen; // eax
  __int16 XMin; // bx
  __int16 XMax; // cx
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > it; // [esp+Ch] [ebp-28h] BYREF

  p_Decoder = &this->Decoder;
  v3 = this->GlyphInfoTablePos + 8 * glyphIndex;
  it.Data.Data = this->Decoder.Data;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder,
                   v3 + 4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &it,
    UInt32fixlen);
  XMin = it.XMin;
  XMax = it.XMax;
  if ( it.XMin >= it.XMax || it.YMin >= it.YMax )
  {
    XMin = 0;
    XMax = p_Decoder->Data->Pages[(v3 + 2) >> 12][(v3 + 2) & 0xFFF]
         | (p_Decoder->Data->Pages[(v3 + 3) >> 12][(v3 + 3) & 0xFFF] << 8);
  }
  return (double)(XMax - XMin);
}
